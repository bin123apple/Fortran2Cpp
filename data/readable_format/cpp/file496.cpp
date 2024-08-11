#include <iostream>
using namespace std;

// Prototype for the fill_array function
void fill_array(int a[], int size);

int main() {
    const int size = 10;
    int a[size];

    fill_array(a, size);

    for(int i = 0; i < size; ++i) {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}

// Definition of the fill_array function
void fill_array(int a[], int size) {
    for(int i = 0; i < size; ++i) {
        a[i] = i + 1;
    }
}