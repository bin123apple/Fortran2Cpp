#include<iostream>
using namespace std;

// Translated foo function
void foo(int a) {
    cout << "Hello from Fortran!!" << endl;
    cout << "input value a=" << a << endl;
}

// Translated foovec function
void foovec(int a[], int size) {
    cout << "Hello from Fortran!!" << endl;
    cout << "input value avec=";
    for (int i = 0; i < size; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

// Simple testing mechanism without Google Test
int main() {
    // Test foo
    cout << "Testing foo with input 5:" << endl;
    foo(5);

    // Test foovec
    cout << "Testing foovec with input {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}:" << endl;
    int avec[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    foovec(avec, 10);

    // Normally, you would check the output manually or devise a way to automatically verify it
    // Since we're not using a unit testing framework here, automatic verification would require additional implementation

    return 0;
}