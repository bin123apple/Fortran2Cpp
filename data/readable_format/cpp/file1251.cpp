#include <iostream>
#include <cmath> // For fabs in case of floating-point comparisons

class GreatRSD {
public:
    void swap(int &a, int &b) {
        int temp = a;
        a = b;
        b = temp;
    }

    void swap(double &a, double &b) {
        double temp = a;
        a = b;
        b = temp;
    }

    void addTen(int &a) {
        a += 10;
    }
};

// Simple test framework
class Test {
public:
    static void assertEquals(int expected, int actual, const std::string& testName) {
        if (expected == actual) {
            std::cout << testName << " passed." << std::endl;
        } else {
            std::cout << testName << " failed. Expected " << expected << " but got " << actual << "." << std::endl;
        }
    }

    static void assertEquals(double expected, double actual, const std::string& testName) {
        if (fabs(expected - actual) < 0.0001) { // Floating point comparison
            std::cout << testName << " passed." << std::endl;
        } else {
            std::cout << testName << " failed. Expected " << expected << " but got " << actual << "." << std::endl;
        }
    }
};

int main() {
    GreatRSD obj;

    // Test swapping integers
    int i1 = 10, i2 = 20;
    obj.swap(i1, i2);
    Test::assertEquals(20, i1, "Test swapping integers i1");
    Test::assertEquals(10, i2, "Test swapping integers i2");

    // Test swapping doubles
    double d1 = 1.1, d2 = 2.2;
    obj.swap(d1, d2);
    Test::assertEquals(2.2, d1, "Test swapping doubles d1");
    Test::assertEquals(1.1, d2, "Test swapping doubles d2");

    // Test adding ten
    int value = 15;
    obj.addTen(value);
    Test::assertEquals(25, value, "Test adding ten");

    return 0;
}