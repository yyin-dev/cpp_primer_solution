#ifndef EX13_34_H
#define EX13_34_H
#include "headers.h"

class Folder;

class Message {
    friend class Folder;
    friend void swap(Message& lhs, Message& rhs);

    // value-like
   public:
    Message(const string& s) : content(s) {}
    Message(const Message& m);
    Message& operator=(Message& rhs);
    ~Message();

    void save(Folder* f);
    void remove(Folder* f);

    void info();

   private:
    string content;
    set<Folder*> folders;
    void remove_from_all_folders();
    void add_to_all_folders(const Message* m);
};

class Folder {
    friend class Message;

   public:
    Folder() : ps(new string("Unnamed")) {}
    Folder(const string& s) : ps(new string(s)) {}
    void addMsg(Message* msg);
    void rmvMsg(Message* msg);
    void info();

   private:
    string* ps;
    set<Message*> messages;
};

Message::Message(const Message& m) : content(m.content), folders(m.folders) {
    // Make new copies of the content and the set of folders.
    // Also add a pointer to this newly created pointer to each Folder.
    add_to_all_folders(this);
}

Message& Message::operator=(Message& rhs) {
    // Replace the content of the left-hand Message with that of the right-hand.
    // Update the set of folders that the Message is folders.
    // Remove the left-hand message from previous folders and add to new folders.
    remove_from_all_folders();

    content = rhs.content;
    folders = rhs.folders;
    add_to_all_folders(this);
    return *this;
}

Message::~Message() {
    remove_from_all_folders();
}

void Message::save(Folder* f) {
    f->addMsg(this);
    folders.insert(f);
}

void Message::remove(Folder* f) {
    f->rmvMsg(this);
    if (folders.find(f) != folders.end()) {
        folders.erase(folders.find(f));
    }
}

void Message::remove_from_all_folders() {
    for (auto f : folders) {
        f->rmvMsg(this);
    }
}

void Message::add_to_all_folders(const Message* m) {
    for (auto f : m->folders) {
        f->addMsg(this);
    }
}

void Message::info() {
    cout << "Message: " << content << " [";
    bool first = true;
    for (auto pf : folders) {
        if (first) {
            cout << *(pf->ps);
            first = false;
        } else {
            cout << ", " << *(pf->ps);
        }
    }
    cout << "]" << endl;
}

void swap(Message& lhs, Message& rhs) {
    using std::swap;
    lhs.remove_from_all_folders();
    rhs.remove_from_all_folders();
    swap(lhs.content, rhs.content);
    swap(lhs.folders, rhs.folders);
    lhs.add_to_all_folders(&lhs);
    rhs.add_to_all_folders(&rhs);
}

void Folder::addMsg(Message* msg) {
    messages.insert(msg);
}

void Folder::rmvMsg(Message* msg) {
    if (messages.find(msg) != messages.end()) {
        messages.erase(messages.find(msg));
    }
}

void Folder::info() {
    cout << "Folder: " << *ps << " [";
    bool first = true;
    for (auto pm : messages) {
        if (first) {
            cout << pm->content;
            first = false;
        } else {
            cout << ", " << pm->content;
        }
    }
    cout << "]" << endl;
}

#endif