#include <iostream>

using namespace std; // allows us to use names from the standard library without prefixing them with "std::"

int main()
{
    // Comments are ignored by the compiler and are used to explain the code to humans.
    cout << "Hello World!" << endl;

    int age = 25; // declaration
    age = 30; // assignment

    cout << "My age is: " << age << endl;

    double cgpa = 3.9;
    cout << "My CGPA is: " << cgpa << endl;

    char sex = 'M';
    cout << "My gender is: " << sex << endl;

    bool student = true;
    cout << "Am I a student? " << (student ? "Yes" : "No") << endl;

    // std has string class for handling text
    string name = "Osman";
    cout << "My name is: " << name << endl;

    // You can also concatenate strings using the + operator
    string greeting = "Hello, " + name + "!";
    cout << greeting << endl;

    // const keyword: used to declare variables whose value cannot be changed after initialization
    const double PI = 3.14159;
    double radius = 10;
    double area = PI * radius * radius;

    cout << "The area of the circle with radius " << radius << " is: " << area << endl;

    return 0;
}
