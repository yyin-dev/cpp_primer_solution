#include "headers.h"

class TreeNode {
   public:
    TreeNode() : value(""), count(0), left(nullptr), right(nullptr) {}
    TreeNode(const string& v, const int i) : value(v), count(i), left(nullptr), right(nullptr) {}

    TreeNode(const TreeNode& n);
    TreeNode& operator=(const TreeNode& rhs);

    ~TreeNode();

   private:
    string value;
    int count;
    TreeNode* left;
    TreeNode* right;
};

TreeNode::TreeNode(const TreeNode& n) : value(n.value), count(n.count), left(nullptr), right(nullptr) {
    if (n.left)
        left = new TreeNode(*n.left);  // recursively call copy constructor
    if (n.right)
        right = new TreeNode(*n.right);  // recursively call copy constructor
}

TreeNode& TreeNode::operator=(const TreeNode& rhs) {
    value = rhs.value;
    count = rhs.count;
    left = rhs.left;
    right = rhs.right;
}

class BinStrTree {
    TreeNode* root;
};

class BinStrTree {
    TreeNode* root;
};