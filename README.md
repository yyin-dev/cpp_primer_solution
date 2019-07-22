# CPP Primer Note

This README contains important/hard points while reading the book.  

## Reference Type 

### 1. No rebinding
#### From the book: 
> A reference defines an alternative name for an object.   

> When we define a reference, instead of copying the initializer's value, we **bind** the reference to ins initializer. There is no way to rebind a reference to refer to a different object. Thus, references **must** be initialized. 

#### From StackOverflow:  

> https://stackoverflow.com/a/728272  
>
> The reason that C++ does not allow you to rebind references is given in Stroustrup's "Design and Evolution of C++" :
>> It is not possible to change what a reference refers to after initialization. That is, once a C++ reference is initialized it cannot be made to refer to a different object later; it cannot be re-bound. I had in the past been bitten by Algol68 references where r1=r2 can either assign through r1 to the object referred to or assign a new reference value to r1 (re-binding r1) depending on the type of r2. I wanted to avoid such problems in C++.  


> https://stackoverflow.com/a/728249  
> 
> In C++, it is often said that "the reference is the object". In one sense, it is true: though references are handled as pointers when the source code is compiled, **the reference is intended to signify an object that is not copied when a function is called.** Since references are not directly addressable (for example, references have no address, & returns the address of the object), it would not semantically make sense to reassign them. Moreover, C++ already has pointers, which handles the semantics of re-setting.    

### 2. A reference is not an object  
#### From the book
> A reference is not an object. Instead, a reference is just another name for an already existing object.  

> When we assign to a reference, we are assigning to the object bound with the reference.  
> When we fetch the value of a reference, we are really fetching the value of the object bound with the reference.  
> Similarly, when we use a reference as an initializer, we are really using the object bound with the reference.  

> https://stackoverflow.com/a/728299    
> 
> A reference is not a pointer, it may be implemented as a pointer in the background, but its core concept is not equivalent to a pointer. A reference should be looked at like it **IS** the object it is referring to.   
> A pointer is simply a variable that holds a memory address. **The pointer itself has a memory address of its own, and inside that memory address it holds another memory address that it is said to point to.** A reference is not the same, **it does not have an address of its own**, and hence it cannot be changed to "hold" another address.   
>> The reference itself isn't an object (it has no identity; taking the address of a reference gives you the address of the referent; remember: the reference is its referent).


### 3. Reference type  
With two exceptions, the type of a reference and the object it binds with must match exactly. Moreover, a reference may be bound only to an object, not to a literal.  

Two exceptions:  
1. We can initialize [ a reference to `const` ] from any expression that can be converted to the type of the reference. We can bind a reference to `const` to a non-`const` object or literal.   
    ```C++
    int i = 10;
    const int &r1 = i;  // bound with non constant int object
    const int &r2 = 10; // bound with int literal
    ```
    Reason:   
    When binding to an object of a different type, a temporary object is created by the compiler. I.e,: 
    ```C++
    double d = 1.0;
    const int &ri = d;
    ``` 
    becomes: 
    ```C++
    double d = 1.0;
    const int temp = d;
    const int &ri = temp;
    ```   
    In this case, the reference is bound to a **temporary** object. If `ri` is not constant, we can assign to `ri`, which is essentially assigning to the temporary object. However, the programmer would probably expect that assigning to `ri` would change `d`, as no one would want to change the value of a temporary object. So, C++ makes this illegal.  

2. Covered much later.     



## Default Initialization  
-  For built-in type(int, double, char, etc.), initializaed to `0` if not defined within any function. If it is defined inside a function, then initialized to `undefined`.  
- For non built-in type, initialized according to the class definition.  

## Arrays and Pointers  
> In C++ pointesr and arrays are closely intertwined. In particular, when we use an array, the compiler ordinarily converts the array to an pointer. ... **in most places** when we use an array, the compiler automatically substitutes a pointer.  

Examples:   
1. When using `auto`
    ```C++
    int arr[] = {0, 1, 2};
    auto ip(arr); // arr is an int * pointing to the first element
    ```

2. When using subscipt  
    ```C++
    int arr[] = {0, 1, 2};
    int i = arr[2]; // arr is converted to be a pointer
                    // equivalent to: int i = *(arr + 2)
    ```    

3. Multi-dimensional array Range `for`  
    ```C++
    constexpr size_t rowCount = 3, colCount = 4;
    int arr[rowCount][colCount];

    size_t count = 0;
    for (auto &row : arr){
        for (auto &col: row){
            col = count;
            count++;
        }
    }

    for (auto &row : arr){  // & is required even for reading (*)
        for (auto col: row){
            cout << col << endl;
        }
    }
    ```
    The `&` is required to avoid the normal array to pointer conversion by the compiler. If `&` is neglected, `row` would be converted to a pointer pointing to the first element of the 4-element array, `row` has type `int *`. Then the inner loop is illegal.  
    

## Name Lookup
### Rules
When a variable/type name is encountered by compiler, it looks for the name in the program. 
- General rule:  
    - First, look for a **declaration** of the name in the current block. Only names declared **before** the use are considered.  
    - If the name is not found, look in the enclosing, i.e. outer, scope.  
    - If no declaration is found in local or outer scopt, error occurs.   

Special rule (Two phase processing) for class definition: 
- Class definitions are processed in two phases: 
    - First, all member declarations in the class are compiled.  
    - Member function definitions/bodies are processed ***only after*** the entire class has be seen by the compiler. 
    - During compilation of member function bodies, the compiler follows this order: 
        - class scope: first search the function scope, including function parameters and local variables. If not found, search outside of function scope but still within the class scope, essentially among class members. 
        - enclosing scope 

The reason that classes are processed in two phases is to make it easier to organization code in the same class.  
The two-phase processing *ONLY* applies to **member function definitions**. For all other cases, including member function declaration, the name must be declared before it can be used.   


### Examples
Example 1:  
```C++
typedef double Money;
string bal;

class Account {
    public: 
    Money balance() { return bal; }

    private: 
    Money bal = 0.0;
}
```  
Explanation:   
1. `Money balance()` is the member function declaration, and the general name lookup rule is applied. `{ return bal; }` is the member function definition, so the two-phase processing rule is applied.  
2. When the compiler sees the declaration of the member function: `Money balance()`, it looks for its declaration among the names declared in the current block before this use. The compiler cannot find it in the class body before this member function declaration, so it searches the enclosing scope, i.e., the global scope. It finds `typedef double Money;` and the name is resolved successfully. The general name lookup rule is applied. 
3. The member function body/defition `{ return bal; }` is processed ***only after*** all the class declarations are compiled. Thus, the `bal` returned in the member function is the data member, instead of the global variable. The two-phase processing is applied. A more detailed description in Example 2. 

Example 2:
```C++
int height;
class Screen{
    public: 
    typedef std::string::size_type pos;

    void f1(pos height) { cursor = width * height; }
    void f2(pos height) { cursor = width * this -> height; }
    void f3(pos height) { cursor = width * Screen::height; }
    void f4(pos height) { cursor = width * ::height; }

    private:
    pos cursor = 0;
    pos height = 0, width = 0;
}
```

Explanation:   
1. By the time the compiler starts processing the member function definitions of `f1`, `f2`, `f3` and `f4`, all the member declarations have been compiled already in the first phase.   
2. `f1`: When the compiler processes the expression `cursor = width * height;`, it first looks for the names used in the narrowest local scope, i.e. the scope of that member function. **As a function's parameters are in the function's scope**, the name `height` is resolved to be the function parameter. In this case, the parameter hides the class member. 
3. `f2` and `f3`: Adding `this ->` or `Screen::`explicitly asks the compiler to look for the class's scope. The class member `height` is used.
4. `f4`: Adding `::` explicitly asks the compiler to search in the global scope.  


#### Addition Note: 
When a member is defined outside the class, the scope where this definition resides is also searched during name lookup.  

Example:  
```C++
const int MAX_HEIGHT = 10;
class Screen() {
    public:
    tyepdef std::string::size_type pos;
    void set_height (pos); // declartion

    private:
    pos height = 0;
}

Screen::pos limit(Screen::pos height){
    return min(height, MAX_HEIGHT);
}

void Screen::set_height (pos h) {
    height = limit(h);
}
```  
Explanation:  
The declaration of global function `limit` is not visible before the definition of class `Screen`. However, the scope at which the definition of `set_height()` appears is also searched during name lookup. The declaration of `limit` in global scope appeard before its use in `set_height()` and thus can be used.   

### Summary  
1. Compilation phase for class: member declarations before member definitions.  
2. Two casesfor name lookup: member function definitions and others.   
    - Member function definitions:  
    Class scope -> Enclosing scope -> Scope where definition outside class appears.  
    - Other cases:  
    Names must be declared before it can be used.  
    If the name is within a class (including data member definitions, member function declarations, excluding member function definitions):  
    Class scope *before this name appears* -> Enclosing scope.  


## `constexpr` Variables
Compared to `constexpr`, `const` is fairly straightforward. It tells the compiler that this object must not be modified after initialization, and also askes compiler to guarantee this. This also allows compiler to do some optimization work.   

#### 1. Concept
A constant expression is an expression **whose value cannot change** and that can be **evaluated at compile time**, so as to reduce running time. A literal is a constant expression. A `const` object initialized from a `constant expression` is also a constant expression.  

Whether an object/expression is a constant expression depends on its **types** and **initializers**. Actually, those types that are be used as `constexpr` are called `literal type`s, which we'll discuss later:  
```C++
const int max_files = 20; 
const int limit = max_files + 1;
int staff_size = 27; 
const int sz = fn();
```
- `max_files`: a `const` object initialized from literal, i.e., a constant expression. It is a constant expression.  
- `limit`: a `const` expression initialized from another constant expression. It is a constant expression. 
- `staff_size`: initialized from constant expression but is non`const`. It is not a constant expression.  
- `sz`: a `const` object initialized with a function, whose value is not known until runtime. It is not a constant expression.   

#### 2. `constexpr`  
Declaring a variable as `constexpr` makes compiler checks if that object is indeed a constant expression. Variables declared as `constexpr` are **implicitly `const`** and **must be initialized with constant expression**.  
```C++
constexpr int mf = 20; // Legal
constexpr int limit = mf + 1; // Legal
constexpr int sz = size(); // Legal, IF: size() is a constexpr function
```  
Although we cannot use ordinary function as the initializer for `constexpr`, we can use `constexpr` functions instead.  

#### 3. Literal types  
As constant expressions should be evaluated at compile time, the type of a `constexpr` is limited. The types eligible for a `constexpr` is knows as `literal type`s since they are simple enough to have literal values.  

**Arithmetic**, **reference** and **pointer** types are literal types. User-defined class, IO object and `string` types are not literal types.   
In addition, even though we can define both pointers and reference as `constexpr`s, the objects we use to initialize them are strictly limited.  
**For pointer**: we can only initialize a `constexpr` pointer from the `nullptr` literal or the literal `0`.  
**For reference**: we can only bind/refer to an object that remains at a fixed address.   
For examples, local variables in functions are not `constexpr`s as they are created and destroyed at runtime. In contrast, an object defined in global scope is allocated a fixed address and thus is a constant expression. Local `static` variables for functions, like global variables, are also constant expressions.  

#### 4. Pointers and `constexpr`  
Different from `const`, when we define a pointer in a `constexpr` declaration, the `constexpr` specifier applies to the pointer, not the type to which the pointer points:
```C++
const int *p = nullptr;     // p is a pointer to a const int
constexpr int *q = nullptr; // q is a const pointer to int
```
Reason: `constexpr` imposes a top-level const on the objects it defines.  

Like any other constant pointer, a `constexpr` pointer may point to a `const` or a
non`const` type:  
```C++
constexpr int *np = nullptr; // np is a constant pointer to int that is null
// Assume i and j are defined outside any function
int j = 0;
constexpr int i = 42; // type of i is const int
constexpr const int *p = &i; // p is a constant pointer to the const int i
constexpr int *p1 = &j; // p1 is a constant pointer to the int j
```   

#### 5. Sidenote  
The dimension of an array must be a const expression. though might not declared to be `constexpr`.  
```C++
int valid1[5]; 
int size1 = 5;
const int size2 = 5;
constexpr int size3 = 5;
int invalid[size1]; 
int valid2[size2];
int valid3[size3];
```  
Explanation: 
1. `5`: an `int` literal and is therefore a constant expression.  
2. `size1`: a non`const` object, cannot be a constant expression.
3. `size2`: a `const` object initialized from a constant expression. It is essentially a `constexpr`.  
4. `size3`: a explicit `constexpr`.    

## `constexpr` Functions  
A `constexpr` function is a function that can be used in a constant expression.   

A constexpr function is defined like any other function but have certain
restrictions: 
-  The return type and the parameter type must be **literal type**;  
- The function body must contain exactly one `return` statement.  

Example:  
```C++
constexpr int get_constexpr() { return 42; }
constexpr int foo = get_constexpr(); // ok
```  
The compiler will replace a call to a `constexpr` function with its resulting value during compilation time. A `constexpr` function is implicitly `inline`.

A `constexpr` function body may contain other statements so long as those statements generate no actions at run time. For example, a `constexpr` function may contain null statements, type aliases, and using declarations.  

A `constexpr` function is permitted to return a value that is not a `const`: 
```C++
constexpr int get_constexpr() { return 42; }
constexpr size_t multiply(size_t cnt) { return get_constexpr() * cnt; }
int arr1[multiply(2)]; // ok 
int i = 2;
int arr2[multiply(i)]; // error
```  
The `multiply` is a `constexpr` function if its argument `cnt` is a constant expression. If we call `multiply` with a expression that is not a constant expression, the result would not be a constant expression. If we use that result in a context that requires a constant expression, error is generated by the compiler.   

#### My Summary for `constexpr` function  
Keep in mind the meaning of constant expression: its value can be evaluated at compile time.  So:  
1. the input (parameters) and output (return value) of a `constexpr` function must be `literal type`s, **for the return value of the function to be a constant expression**. (You can use non`constexpr` as arguments, though the output would not be `constexpr`):   
    ```C++
    constexpr int get_two() { return 2; }
    constexpr int get_double(int n) { return get_two() * n; }
    constexpr int ce_i = get_double(2); // ok, input&output are constexpr
    int i = 2;
    int j = get_double(2);              // ok, input&output are NOT constexpr
    ```
2. The function body should contain only operations that can be evaluated at compile time, like null statement, type alias and using declarations.   
3. The compiler checks the validity of the return value of a `constexpr` function only in the context where a `constexpr` is expected. When the arguments to a `constexpr` function are not constant expressions, the return type is not either. 
    ```C++
    constexpr int get_two() { return 2; }
    constexpr int get_double(int n) { return get_two() * n; }
    int i = 2;
    int j = get_n(i);  // ok, as constant expression is not expected
    int arr[get_n(i)]; // error, as constant expression is expected
    ```
4. A `constexpr` function does not have to return `const` object.   


## Sequential Containers  
Sequential containers, **6** in total:  `vector`, `string`, `deque`, `list`, `forward_list`, `array`.  
Note:  
`string` can be considered a specialized version of `vector` that can only store `char`. All operations appliable to `vector` is appliable to `string`.  

#### Characteristics  
`vector`: Fast random access. Fast insertion/deletion at back.  
`string`: Can be regarded as a specialized `vector`. Fast random access. Fast insertion/deletion at back.  
`deque`: `d`ouble-`e`nded `que`ue. Fast random access. Fast insertion/deletion at front&back. More detail: https://stackoverflow.com/a/24483402/9057530  
`list`: doubly linked list. Supports bi-directional sequential access but no random access. Fast insertiion/deletion at all placess.  
`forward_list`: singly linked list. Supports only uni-directional sequential access. Fast insertiion/deletion at all placess.   
`array`: fixed-size array. Fast random access. Cannot add or remove element.  

#### Constraints on element type  
No constraints, with one exception: some operation on containers rely on performing certain operations on the element type.  
Two examples. **(1)** `==` and `!=` operations are defined for containers. However, this operation relies on apply `==` and `!=` among elements. This requires operator overloading for user_defined class. **(2)** Containers provide a constructor for initialization that only take one argument, which is the size of the container. In the initialization, the default constructor for the element type would be called. If the class, e.g. a user-defined class, does not have a default-constructor, then error occurs.  

#### Iterator operations for containers  
1. With one exception, sequential containers iterators support the following operations:

    `*`(dereference), `->`(dereference and dot), `++`, `--`, `==`, `!=`  

    Exception: `forward_list` does not support `--`, as it only supports one-directional sequential access.  

2. Iterator arithmetics only apply to `vector`, `string`, `deque` and `array`:  
    `iter + n`, `iter - n`, `iter += n`, `iter -= n`, `iter1 - iter2`, `>`, `<`, `>=`, `<=`  
    Reason: Unlike the four types, elements in `list` and `forward_list` are not allocated contigous memory address, thus does not support iterator arithmetics.  

#### Iterator range  
Iterator range is a **left-inclusive interval**, i.e., `[begin, end)`.  

#### Container definition and initialization  
1. With the exception of `array`, each container defines a default construtor. The default constructor creats an empty container(size 0) of the specified type.   
    Example: `vector<int> v;`  
    PS: For an `array` object, its type info includes: `container type(array)` + `element type` + `size`. For other 5 kinds of container, type infor includes: `container type` + `element type`. The size for an `array` is always specified at initialization for `array`: `array<int, 5> array;`.  

2. With the exception of `array`, another constructor is defined that takes the size of the container and initial value for the elements.   
    Example: `vector<int> v(5, -1); `.

    We can also use the constructor that takes only a size argument, **IF** the element type is a built-in type or a class type with a default constructor.   
    Example: `vector<int> v(5); `.

3. Initialization as a copy of another container  
    - Approach 1: pass another container as argument.   
        Requirement: the argument must have **the same** type info: `container type` + `element type`.  
        ```C++
        list<string> original_list = {"Hi", "Hello"};
        list<string> new_list(original_list);      // ok, match  
        vector<string> new_vector(original_list);  // error, container type 
        list<char *> new_list2(original_list);     // error, element type
        ```  
    - Approach 2: pass a pair of iterators of another container  
        Requirement: container type can be different, element type can differ as long as conversion is possible.  
        ```C++
        list<char *> old = {"Hi", "Hello"};
        list<char *> new_list1(old.begin(), old.end());     // ok
        list<string> new_list2(old.begin(), old.end());     // ok
        vector<char *> new_vector1(old.begin(), old.end()); // ok
        vector<string> new_vector2(old.begin(), old.end()); // ok  
        ```  

4. `array` have fixed size  
    The size of an `array` is part of its type info.  
    ```C++
    array<int, 10> = i_arr;
    array<int, 10>::size_type sz;
    ```  
    You can copy and assign library `array`, though you cannot do so with built-in array.

5. Assignment with `=` and `assign()`  

#### iterators involved in `erase()` and `insert()`  


## Generic Algorithms  
Generic algorithms are defined in the `<algorithm>` header.   
Library algorithms do not execute container operations. They operate solely with iterators and iterator operations.   

*Implication 1*: algorithms do not change the size of the container.  
*Implication 2*: algorithms are container-independent, but do depend on element type.    
*Implication 3*: algorithms can work on built-in array as they provide iterators.  

PS: When algorithms operate on some iterator types, e.g. `back_inserter`, that can change the size of the underlying container, keep in mind that this is the effect by the iterator, not algorithm.     

Algorithms that take 1 input range use the first 2 parameters to denote the range.

Algorithms can be divided into 3 categories by whether they:   
(1) read element,   
(2) write element, or   
(3) rearrange the order of the elements.   

#### 1.1 Read-only algorithm   
Can use `const` iterator to denote the range.  
Example: `find`, `count`, `accumulate`.  
```C++
int sum = accumulate(vec.cbegin(), vec.cend(), 0);          // ok
string sum = accumulate(v.cbegin(), v.cend(), "");          // error 
string sum = accumulate(v.cbegin(), v.cend(), string(""));  // ok
```
`accumulate` uses the 3rd argument as the staring point for summation. Thus, make sure that we can add element type to it.  


#### 1.2 Writing algorithm  
Cannot use `const` iterator to denote the range.   
Algorithms that take 2 input ranges use the first 2 parameters to denote the 1st range, and the 3rd parameter to denote the first element in the 2nd range. In this case, the algorithm **assumes that:** second range is at least as long as the 1st one.    

Some algorithms take an input range and writes to it. These algorithms are not too dangerous as long as you provide valid input range;  
Some algorithms takes a single iterator, denoting the destination, and a number denoting the number of elements to be written to. For example, `fill_n(dest, n, val)`. It **assumes that** the `dest` refers to an element, and there are at least `n` elements in the range starting from `dest`.  
```C++
vector<int> vec;
fill_n(vec.begin(), vec.size(), -1); // ok
fill_n(vec.begin(), 10, -1);         // error, vec is empty  
```  

Takes a look at `back_inserter`.   

#### 1.3 Reordering algorithm   
Cannot use `const` iterator to denote the range.  

Consider eliminating duplicates in a container. Steps: use `sort` algorithm to group duplicates together -> use `uniq` algorithm to get a range with unique elements -> use *container operation*  `erase` to remove elements outside the unique range.  



#### 2. Provide `predicate` to algorithms  
Two kinds of predicates: **unary predicates** and **binary predicates**.  

#### 3 Lambda expression and `bind`  
Lambda expression provides a wrapping for functions to make it takes the required number of arguments.  

- Lambda expression  
    - Syntax: `[capture list] (parameter list) -> return type { function body }`. 
        - Capture list specifies the local variables of the enclosing scope the lambda will use.
        - You can omit both or either of parameter list and return type.  
        Omitting the parentheses and the parameter list is equivalent to specifying an empty parameter list.    
        If return type is omitted, a return type is inferred from the function body: if the function has only one `return` statement, the return type is inferred from the returned expression; otherwise the return type is `void`.  
        - Lambda can use local statics and variables *outside the enclosing scope* directly, without including them in the capture list.  
    - Capture by value/reference + Implicit/Explicit capture  
    - Mutable lambda  
- `bind`  


## Forward Declaration 
The *forward declration* `class StrBlob;` introduces the name `StrBlob` into the program and indicates that it's a class type. **After the declaration and before a definition is seen, the class is a incomplete type:** it is know that `StrBlob` is a class type but what members the type contains is unknown.  

We can use a incomplete type only in limited ways: 
1. we can define pointers or references to such type. 
2. We can declare, but not define, functions using the incomplete type as return or parameter type. 

A class must be defined before: 
1. we can create object of that type, otherwise the compiler does not know how much memory to allocate for the object. 
2. we can access the members of the class.
3. Being used as the member of another class. 


## `std::move`, move constructor, and move assignment operator  
https://stackoverflow.com/questions/3413470/what-is-stdmove-and-when-should-it-be-used

https://docs.microsoft.com/en-us/cpp/cpp/move-constructors-and-move-assignment-operators-cpp?view=vs-2019 The output of the program is pretty intersting.  

#### How move constructor and move assignment improves performance?   
- From the pespective of implementation: when a move constructor is called, a new object is created, whose data is **moved** from another object, instead of copied. Similarily for a move assignment operator.  

- From the perspective of invoking the move constructor and move assignment operator: if the move constructor and move assignment operator are not defined, the compiler makes copies whenever it needs to do a *copy initialization*. However, with the two move copy-controls defined, when a rvalue reference is encountered, the move operation would be performed instead of copy. 
































