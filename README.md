# CPP Primer Note

This README contains important/hard points while reading the book.  

## Reference in C++ 

### 1. No rebinding
#### From the book: 
> A reference defines an alternative name for an object.   

> When we define a reference, instead of copying the initializer's value, we **bind** the reference to ins initializer. There is no way to rebind a reference to refer to a different object. Thus, references **must** be initialized. 

#### From Tensorflow:  

https://stackoverflow.com/a/728272
> The reason that C++ does not allow you to rebind references is given in Stroustrup's "Design and Evolution of C++" :
>> It is not possible to change what a reference refers to after initialization. That is, once a C++ reference is initialized it cannot be made to refer to a different object later; it cannot be re-bound. I had in the past been bitten by Algol68 references where r1=r2 can either assign through r1 to the object referred to or assign a new reference value to r1 (re-binding r1) depending on the type of r2. I wanted to avoid such problems in C++.  


https://stackoverflow.com/a/728249
> In C++, it is often said that "the reference is the object". In one sense, it is true: though references are handled as pointers when the source code is compiled, **the reference is intended to signify an object that is not copied when a function is called.** Since references are not directly addressable (for example, references have no address, & returns the address of the object), it would not semantically make sense to reassign them. Moreover, C++ already has pointers, which handles the semantics of re-setting.    

### 2. Reference is not an object  
#### From the book
> A reference is not an object. Instead, a reference is just another name for an already existing object.  

> When we assign to a reference, we are assigning to the object bound with the reference.  
> When we fetch the value of a reference, we are really fetching the value of the object bound with the reference.  
> Similarly, when we use a reference as an initializer, we are really using the object bound with the reference.  

https://stackoverflow.com/a/728299  
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
-  For built-in type(int, double, char, etc.), initializaed to `0` if not defined within any function, otherwise initialized to `undefined`.  
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
    







