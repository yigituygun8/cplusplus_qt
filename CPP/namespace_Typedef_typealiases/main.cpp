#include <iostream>
#include <vector>

namespace first {
int x = 10;
}

namespace second {
int x = 20;
}

// typedef example
typedef std::vector<std::pair<std::string, int>> pairlist_t; // creates an alias for a vector of pairs of string and int

typedef std::string text_t;

int main()
{
    /*
    Namespace is a container used to organize identifiers like variables, functions and classes.
    Helps prevent naming conflicts when the same names are used in different parts of a program

    Groups related code, classes, objects and functions together.
    Prevents collisions between identifiers having the same name.
    Improves code organization and readability.

    std::cout - :: is called the scope resolution operator, it is used to access members of a namespace. In this case, cout is a member of the std namespace.
    or to prevent having to write std:: before every standard library object or function, we can use the using directive:
    using namespace std; -> write only cout without prefixing it with std::.

    P.S.: Function vs Method:
    A function is a block of code that performs a specific task and can be called from anywhere in the program.
    It is not associated with any object or class. Can live directly in a namespace or in the global scope.

    A method is a function that is associated with an object or class.
    It operates on data that belongs to the object or class and can access its properties and other methods.
    Lives inside a class and is called on an instance of that class (object) or on the class itself if it's a static method.


    In C++, std namespace is the part of standard library, which contains most of the standard functions, objects, and classes like cin, cout, vector, etc.
    It also avoids conflicts between user-defined and library-defined functions or variables.

    Global namespace is the default namespace for all identifiers that are not declared inside any namespace. It is the outermost scope and can be accessed from anywhere in the program by using the scope resolution operator (::) without a namespace name, like ::identifier. It is used for identifiers that are meant to be globally accessible and not part of any specific namespace.

    Extending a namespace: You can extend a namespace by adding new declarations to it in different parts of the program.
    This is done by reopening the namespace and adding new members to it. For example:
    namespace MyNamespace {
        void myFunction() {
            cout << "Hello from MyNamespace!" << endl;
        }
    }
    // Later in the program, we can extend MyNamespace with more functions or variables:
    namespace MyNamespace {
        void anotherFunction() {
            cout << "Another function in MyNamespace!" << endl;
        }
    }

    Namespace vs Class:
    A namespace is a declarative region that provides a scope to the identifiers inside it.
    It is used to organize code and prevent name conflicts in large projects.
    It does not have any data members or member functions.
    Does not encapsulate data or behavior; it only provides scope. Does not have access modifiers.
    Cannot be inherited.
    Does not directly consume memory; it only provides scope for identifiers.

    A class is a user-defined data type that encapsulates data and behavior.
    It can have data members (variables) and member functions (methods) that operate on the data, encapsulating them.
    Has access modifiers (public, private, protected) to control the visibility of members
    Can be inherited to create new classes based on existing ones.
    A class is instantiated to create objects.
    Consumes memory as objects are created from a class.

    RULE: Never put using namespace namespace_name; in a header file, because it can lead to name conflicts and unintended consequences for any source file that includes that header. It can cause ambiguity and make it difficult to manage namespaces effectively.

    RULE2: if you load all namespaces into the global namespace using "using namespace std;", it can lead to name conflicts if there are identifiers in the std namespace that have the same name as identifiers in your code or other libraries you are using. This can cause ambiguity and make it difficult to determine which identifier is being referred to, leading to compilation errors or unexpected behavior. It is generally recommended to use specific using declarations (e.g., using std::cout;) or to prefix standard library identifiers with std:: to avoid such conflicts. For example there is data type called "string" in the std namespace, if you have a variable named "string" in your code and you use "using namespace std;", it can cause a conflict and lead to compilation errors or unexpected behavior when you try to use the "string" variable or the "std::string" type. This is why it's important to be cautious when using "using namespace std;" and to consider using specific using declarations or prefixing with std:: to avoid such conflicts.
    */

    std::cout << first::x << std::endl; // Accessing x from the first namespace
    std::cout << second::x << std::endl; // Accessing x from the second namespace

    using namespace first;
    std::cout << x << std::endl; // Accessing x from the first namespace without prefix

    using std::cout;
    using std::endl;
    using std::string;

    string name = "Osman";
    cout << "Hello, " << name << "!\n";

    /*
    typedef: used to create an alias for a data type, making it easier to read and write complex types.
    New identifier for an existing type
    Helps with readability and reduces typos.
    */

    pairlist_t pairlist;

    text_t lastName = "Uygun";

    cout << "Last name: " << lastName << endl;

    /*
    typedef vs using:
    typedef is the traditional way to create type aliases in C++. It can be used to create aliases for simple types, pointers, function pointers, and more. However, it has some limitations when it comes to template aliases.

    using is a newer syntax introduced in C++11 that can be used to create type aliases, including template aliases. It provides a more concise and readable syntax for creating type aliases, especially when dealing with templates.

    MODERN WAY -> USING keyword
    */

    using pairlist_t2 = std::vector<std::pair<std::string, int>>;
    pairlist_t2 pairlist2;

    using funcPtr = void(*)(int); // alias for a pointer to a function that takes an int and returns void
    funcPtr myFunctionPointer = nullptr; // initialize the function pointer to null

    /*
    type conversion:
        -implicit: automatically performed by the compiler when it can safely convert one type to another (e.g., int to double).
        -explicit: performed by the programmer using a cast operator (e.g., static_cast<double>(myInt)) when the conversion is not safe or when you want to be explicit about it.
    */
    int x = 3.14;
    cout << "x: " << x << endl; // implicit conversion from double to int, x will be 3

    double y = (int)3.14; // explicit conversion using C-style cast, y will be 3.0
    cout << "y: " << y << endl;

    // static_cast: used for well-defined and safe conversions between types, such as numeric conversions or pointer conversions within an inheritance hierarchy. Performed at compile time and does not allow for unsafe conversions.
    int z = static_cast<int>(3.14); // z will be 3
    cout << "z: " << z << endl;

    // char c = 100; // after printing, it does implicitly convert the integer 100 to its corresponding ASCII character, which is 'd'. So, c will be 'd'.
    char c = static_cast<char>(100); // c will be 'd'. explicitly converting the integer 100 to a char using static_cast, which results in 'd' as well.
    cout << c << endl;

    int correctQuestions = 8;
    int questions = 10;

    double percentage = static_cast<double>(correctQuestions) / questions * 100;
    cout << "Percentage: " << percentage << "%" << endl;

    /*
    static_cast: used for well-defined and safe conversions between types, such as numeric conversions or pointer conversions within an inheritance hierarchy. Performed at compile time and does not allow for unsafe conversions.
    dynamic_cast: used for safe downcasting in an inheritance hierarchy, allowing you to check at runtime if the cast is valid. It returns a null pointer if the cast fails.
    const_cast: used to add or remove the const qualifier from a variable, allowing you to modify a variable that was originally declared as const. It should be used with caution, as it can lead to undefined behavior if used improperly.
    reinterpret_cast: used for low-level casts that can reinterpret the bit pattern of a value as a different type. It should be used with extreme caution, as it can lead to undefined behavior if used improperly.
    */

    return 0;
}
