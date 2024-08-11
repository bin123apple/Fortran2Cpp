#include <iostream>

// Template function to swap values of any type (int, float, double, etc.)
template<typename T>
void swap(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}

int main() {
    int i = 10, j = 60;
    float x = 40.567f, y = 38.678f;

    std::cout << "Before swapping: i= " << i << " j= " << j << " x= " << x << " y= " << y << std::endl;

    swap(i, j); // Swap integers
    swap(x, y); // Swap floating-point numbers

    std::cout << "After swapping: i= " << i << " j= " << j << " x= " << x << " y= " << y << std::endl;

    return 0;
}