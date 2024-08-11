#include <iostream>
#include <string>

// Using a function pointer array to emulate the computed GOTO
// and assigning specific functions to labels
void label1();
void label2();
void label3();
void label4();
void label666();

// Approximating the Fortran WRITE statement with ostream in C++
void write(const std::string &fmt) {
    std::cout << fmt << std::endl;
}

void test(int n) {
    // Emulating the computed GOTO with a switch statement
    // Although the original Fortran code doesn't clearly specify
    // how 'lab' is chosen based on 'n', this is an approximation.
    // The original code's logic regarding 'lab' is unclear and seems incorrect.
    // Actual logic might need adjustments.
    switch (n) {
        case 1:
            label1();
            break;
        // Including case 666 and others as needed based on the Fortran ASSIGN statements
        // Since the original logic for assigning and using 'lab' is not clear,
        // these cases are illustrative and might not exactly match the original intent.
        case 666:
            label666();
            break;
        default:
            // Assuming default behavior due to lack of clarity in original code
            label3();
            break;
    }
}

void label1() {
    write("Label 1 executed");
}

void label2() {
    write("no");
}

void label3() {
    write("yes");
}

void label4() {
    // Placeholder for label 4 logic
}

void label666() {
    // Placeholder for label 666 logic
}

int main() {
    test(0); // example usage
    return 0;
}