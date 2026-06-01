#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int age;
    string name;

    cin >> age; // cin does not take whitespace, so it will read only the first word of the input. If you want to read a full line of input, you can use getline() function instead.

    // cin.ignore or use ws:
    cin >> ws; // This will ignore any leading whitespace characters before reading the name, allowing you to read the full name even if it contains spaces.

    getline(cin, name); // This will read the remaining input after reading age, including any whitespace, and store it in the name variable.
    cout  << "Your age is: " << age << endl;
    cout << "Your name is: " << name << endl;

    // math functions
    double num = -5.7;
    cout << "Absolute value of num: " << abs(num) << endl; // returns the absolute value of num

    cout << max(1, 2) << " " << min(1, 2) << endl; // returns the maximum and minimum of the two numbers
    cout << sqrt(16) << " " << pow(2, 4) << endl; // returns the square root of 16 and 2 raised to the power of 4

    cout << round(3.14) << " " << ceil(3.14) << " " << floor(3.14) << endl; // returns the rounded value, the smallest integer greater than or equal to 3.14, and the largest integer less than or equal to 3.14

    double a, b, c;
    cin >> a >> b;

    double hypo = sqrt(pow(a, 2) + pow(b, 2));
    cout << "The hypotenuse of the right triangle with sides " << a << " and " << b << " is: " << hypo << endl;

    return 0;
}
