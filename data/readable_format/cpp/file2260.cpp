#include <cmath> // For atan function

class Circle {
public:
    static constexpr double pi = 4.0 * std::atan(1.0);
    double radius;

    Circle() : radius(0) {} // Constructor to initialize radius to 0
};

int main() {
    Circle circle;
    circle.radius = 5.0; // Example usage, set radius to 5.0
    return 0;
}