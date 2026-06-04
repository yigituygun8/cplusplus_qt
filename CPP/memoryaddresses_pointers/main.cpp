#include <iostream>
#include <functional>

using namespace std;

// !!! In C++, & sign not only means "address of" but also can be used to declare reference variables.
// A reference variable is an alias for another variable. When you declare a reference variable, it must be initialized to refer to an existing variable.
// After that, you can use the reference variable as if it were the original variable.
// Reference vars avoid the need for pointers and make code easier to read and maintain. They also allow you to modify the original variable directly without needing to return a value from a function.
void swap(string &str1, string &str2) { // The parameters str1 and str2 are reference variables. They refer to the original variables passed to the function.
    std::swap(str1, str2); // using the built-in swap function to swap the values of str1 and str2. Since str1 and str2 are references to the original variables, the changes will affect the original variables passed to the function.
}

void swap(int &num1, int &num2) {
    std::swap(num1, num2);
}

// Or instead use template function to swap any type of variables:
template <typename T>
void templateSwap(T &a, T &b) {
    T temp = a;
    a = b;
    b = temp;
}

/*
const parameters: When you declare a function parameter as const, it means that the value of that parameter cannot be modified within the function.
This is useful for ensuring that certain data remains unchanged and can help prevent bugs. For example:
void printMessage(const string &message) {
    cout << message << endl; // This is fine, we are just reading the value of message.
    message = "New message"; // This will cause a compile-time error, because we cannot modify a const parameter.
}
*/

int add(int a, int b) { return a + b; }

int main()
{
    /*
    Memory addresses: a location in memory where data is stored. Can be accessed with & operator.
    Each variable has a unique memory address.
    */

    string name = "yigit";
    cout << "Name: " << name << endl;
    cout << "Memory address of name with hexadecimal: " << &name << endl;
    cout << "Size of address: " << sizeof(&name) << endl; // The size of a pointer (memory address) is typically 8 bytes on a 64-bit system and 4 bytes on a 32-bit system.

    string name1 = "Yigit";
    string name2 = "Osman";

    cout << "Before swap: " << endl;
    cout << "Name1: " << name1 << endl;
    cout << "Name2: " << name2 << endl;

    swap(name1, name2);

    cout << "After swap: " << endl;
    cout << "Name1: " << name1 << endl;
    cout << "Name2: " << name2 << endl;

    int x = 1;
    int y = 9;
    swap(x, y);

    cout << "Swapped: x = " << x << " | y = " << y << endl;

    templateSwap(x, y);

    cout << "Swapped: x = " << x << " | y = " << y << endl;

    /*
    Pointers: A pointer is a variable that stores the memory address of another variable.
    It allows you to indirectly access and manipulate the value of the variable it points to.
    Pointers are declared using the * operator.

    Types of Pointers in C++:
    1. Null Pointer: A pointer that does not point to any valid memory location. It is often used to indicate that a pointer is not currently pointing to anything.
    2. Void Pointer: A pointer that can point to any data type. It is often used for generic programming and can be cast to other pointer types as needed.
    3. Function Pointer: A pointer that points to a function instead of a variable. It allows you to call a function indirectly through the pointer.
    4. Smart Pointer: A pointer that automatically manages the memory it points to. It helps prevent memory leaks and dangling pointers by automatically deallocating memory when it is no longer needed.
    5. Raw Pointer: A traditional pointer that requires manual memory management. It can point to any type of data and is not automatically deallocated, so it can lead to memory leaks if not used carefully.
    6. Dangling Pointer: A pointer that points to a memory location that has been deallocated. Accessing a dangling pointer can lead to undefined behavior, including crashes and data corruption.
        - Not a separate "type" but a critical concept. It's one of the most common bugs in C++. Smart pointers exist specifically to eliminate this problem.
    */

    // Null Pointer
    int *nullPtrEx = nullptr; // Modern C++
    int *oldNullPtr = NULL; // Old C, avoid because NULL is typically defined as 0, which can lead to confusion when used in pointer contexts.
    // Dereferencing a null pointer -> undefined behavior, crash

    // Void Pointer
    int num1 = 42;
    void *voidPtr = &num1; // void pointer can point to any type of data

    cout << "Address of voidPtr: " << &voidPtr << endl; // This will print the memory address of the void pointer itself, not the address it points to.
    cout << "Address of x through void pointer: " << static_cast<int*>(voidPtr) << " OR just use: " << voidPtr << endl; // This will print the memory address stored in voidPtr, which is the address of x.
    cout << "Value of x through void pointer: " << *(static_cast<int*>(voidPtr)) << endl; // Need to cast void pointer to the correct type before dereferencing
    // However, using void pointers can be dangerous because they do not have type information, so template functions or smart pointers are often preferred for type safety and better code readability.

    // Function Pointer
    int (*funcPtr)(int, int) = &add; // Function pointer declaration and initialization. It points to the add function which takes two integers and returns an integer.
    int result = funcPtr(5, 7); // Calling the function through the function pointer. This will call the add function with arguments 5 and 7, and store the result in the variable result.
    cout << result << endl;

    /*
    ABOUT FUNCTION POINTERS:
    Raw function pointers are ideal for low-level tasks like C-API interoperability, dynamic DLL loading, and embedded systems because they introduce zero memory or runtime overhead.
    However, they suffer from complex syntax and cannot capture local state variables. In contrast, modern C++ alternatives like lambdas and std::function provide vastly superior flexibility by allowing inline logic definitions and capturing local scope variables on the fly.
    While lambdas create highly readable code for standard algorithms, and std::function offers a uniform wrapper to store raw functions, lambdas, and functors interchangeably, they can introduce minor performance trade-offs such as virtual call overhead or dynamic memory allocation.
    Ultimately, you should stick to raw function pointers for high-performance low-level bridging, but default to modern callables for standard application logic.
    */

    // Syntax: std::function<Return_Type(Parameter_Types...)> name;
    std::function<int(int, int)> funcWrapper = add; // std::function can store any callable object with a compatible signature. Here, it is storing the add function.
    int wrappedResult = funcWrapper(5, 7); // Calling the function through the std::function wrapper. This will call the add function with arguments 10 and 20, and store the result in wrappedResult.
    cout << wrappedResult << endl;

    funcWrapper = [](int a, int b) { return a * b; }; // you can assign lambdas to std::function as well, allowing for inline function definitions without needing a separate named function.
    cout << funcWrapper(5, 7) << endl;

    // Smart Pointer: we will come to this

    // Dangling Pointer:
    int *dangPtr = new int(5); // dynamically allocate an integer and assign its address to dangPtr
    cout << "dangPtr points to: " << *dangPtr << endl; // Output: 5
    delete dangPtr; // deallocate the memory that dangPtr points to
    // Now dangPtr is a dangling pointer because it still points to the memory location that has been deallocated.
    cout << *dangPtr << endl; // Accessing a dangling pointer results in undefined behavior. This may print garbage value, cause a crash, or even seem to work correctly in some cases, which is why it's important to avoid using dangling pointers.
    dangPtr = nullptr; // To prevent accidental use of the dangling pointer, it's a good practice to set it to nullptr after deleting the memory it points to.




    return 0;
}


