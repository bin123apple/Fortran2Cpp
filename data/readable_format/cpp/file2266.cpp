#include <iostream>
#include <vector>
#include <algorithm> // For std::any_of

class AllType {
public:
    double a;
    std::vector<double> b;

    // Constructor
    AllType() : a(0.0), b(2) {}

    // Copy assignment operator
    AllType& operator=(const AllType& other) {
        if (this != &other) {
            a = other.a;
            b = other.b;
        }
        return *this;
    }

    // Unary minus operator
    AllType operator-() const {
        AllType result;
        result.a = -a;
        result.b = std::vector<double>(b.size());
        std::transform(b.begin(), b.end(), result.b.begin(), [](double x) { return -x; });
        return result;
    }
};

int main() {
    AllType t1, t2, t3;

    t1.a = 0.5;
    t1.b[0] = 1.0;
    t1.b[1] = 2.0;

    t2 = -t1;

    if (t2.a != -0.5) return 1;
    if (std::any_of(t2.b.begin(), t2.b.end(), [](double x) { return x != -1.0 && x != -2.0; })) return 2;

    t1 = -t1;

    if (t1.a != -0.5) return 3;
    if (std::any_of(t1.b.begin(), t1.b.end(), [](double x) { return x != -1.0 && x != -2.0; })) return 4;

    std::cout << "All tests passed!" << std::endl;
    return 0;
}