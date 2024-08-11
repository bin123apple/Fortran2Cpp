#include <iostream>
#include <array>
using namespace std;

int main() {
    array<array<float, 10>, 10> b, c{};
    array<float, 10> a, d;

    // Initialize arrays with test values
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            b[i][j] = static_cast<float>((i + 1) * (j + 1));
        }
        d[i] = static_cast<float>(i + 1);
    }

    // Execute the code
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            if (i == 0) {
                a[i] = b[i][j]; // Adjusted to use the first row for the first element
            } else {
                a[i] = b[i - 1][j];
            }
            if (i < 9) {
                c[i + 1][j] = d[i + 1];
            }
        }
    }

    // Print the results
    cout << "Array a: ";
    for (const auto& elem : a) {
        cout << elem << " ";
    }
    cout << endl; // Corrected line break handling

    cout << "Array c: " << endl;
    for (const auto& row : c) {
        for (const auto& elem : row) {
            cout << elem << " ";
        }
        cout << endl;
    }

    return 0;
}