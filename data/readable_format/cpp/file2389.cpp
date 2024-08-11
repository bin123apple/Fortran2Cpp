#include <iostream>
#include <string>
#include <memory> // for std::unique_ptr

// Define the A type
struct A {
    int X;
    std::unique_ptr<int> y;
    std::unique_ptr<std::string> c;

    // Constructor to initialize A
    A(int x = 0, int y_val = 0, const std::string& c_val = "") : X(x) {
        if (y_val != 0) {
            y = std::make_unique<int>(y_val);
        }
        if (!c_val.empty()) {
            c = std::make_unique<std::string>(c_val);
        }
    }
};

// Utility function to stop the program with a specific code
void stop(int code) {
    std::cerr << "STOP " << code << std::endl;
    std::exit(code);
}

int main() {
    A Me(1, 2, "correctly allocated");
    A Ea;

    // Test Me
    if (Me.X != 1) stop(1);
    if (!Me.y || *Me.y != 2) stop(2);
    if (!Me.c) stop(3);
    if (Me.c->length() != 19) stop(4);
    if (*Me.c != "correctly allocated") stop(5);

    // Test Ea
    Ea.X = 9;
    Ea.y = std::make_unique<int>(42);
    Ea.c = std::make_unique<std::string>("13 characters");

    if (Ea.X != 9) stop(6);
    if (!Ea.y || *Ea.y != 42) stop(7);
    if (!Ea.c) stop(8);
    if (Ea.c->length() != 13) stop(9);
    if (*Ea.c != "13 characters") stop(10);

    // Deallocate
    Ea.y.reset();
    Ea.c.reset();
    if (Ea.y) stop(11);
    if (Ea.c) stop(12);

    return 0;
}