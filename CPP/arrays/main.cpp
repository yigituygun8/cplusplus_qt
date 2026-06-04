#include <iostream>
#include <algorithm> // for fill and fill_n
#include <format> // for std::format (C++20 feature)

using namespace std;

int main()
{
    // Raw C-style arrays are discouraged!!!

    string cars[] = {"Corvette", "Mustang", "Clio"};

    cout << cars << endl; // displays memory address of the array
    cout << cars + 1 << endl;

    cars[0] = "Ford";
    cout << cars[0] << "-" << *(cars + 1) << endl;
    cout << "-----------------------" << endl;

    size_t n = 5;
    string lateAssignment[n];

    lateAssignment[0] = "Ford";
    lateAssignment[1] = "Mustang";
    lateAssignment[2] = "Clio";

    for(string car : lateAssignment) {
        if(!car.empty()) {
            cout << car << endl;
        }
    }

    // or

    for(size_t i = 0; i < n; ++i) {
        if(!lateAssignment[i].empty()) {
            cout << lateAssignment[i] << endl;
        }
    }

    lateAssignment[2] = "Ford";

    // String equality
    if(lateAssignment[0].compare(lateAssignment[2]) == 0) cout << "Equal!" << endl;
    // or you can check directly with str1 == str2. Totally valid. compare method gives < 0 | == 0 | > 0
    else cout << "Not Equal!" << endl;

    // Sort the array - Bubble Sort : O(n^2) - not efficient for large datasets
    int numbers[] = {5, 2, 9, 1, 5};
    int size = sizeof(numbers) / sizeof(numbers[0]);

    for(size_t i = 0; i < size - 1; ++i) {
        for(size_t j = 0; j < size - i - 1; ++j) {
            if(numbers[j] > numbers[j + 1]) {
                // Swap
                int temp = numbers[j];
                numbers[j] = numbers[j + 1];
                numbers[j + 1] = temp;
            }
        }
    }

    cout << "Sorted numbers: " << endl;
    for(size_t i = 0; i < size; ++i) {
        cout << numbers[i] << " ";
    }

    cout << endl;

    // fill the array with a specific value
    string arrToFill[10];

    fill(arrToFill, arrToFill + 10, "Hello");
    // or for a specific number
    fill_n(arrToFill, 5, "First 5");

    for(string el : arrToFill) cout << el << endl;

    // 2D array
    int matrix[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    // you don't need to specify the size of the first dimension when initializing
    cout << sizeof(matrix[0]) << endl; // size of one row (3 integers) = 12 bytes
    cout << sizeof(matrix) << endl; // total size of the matrix (3 rows * 12 bytes) = 36 bytes

    cout << format("{:<5} {:>5.2f}", matrix[0][0], 3.98765) << endl; // left-align integer and right-align float with 2 decimal places

    return 0;
}
