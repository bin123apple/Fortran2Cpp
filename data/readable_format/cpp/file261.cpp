#include <cstdlib>
#include <iostream>
#include <string>

void a1() {
    std::exit(-1);
}

void a2() {
    std::exit(-2);
}

void a3() {
    std::exit(3);
}

void a4() {
    std::exit(4);
}

void a5() {
    std::exit(true ? 5 : 6); // Using the ternary operator as a substitute for Fortran's merge
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <test_number>" << std::endl;
        return 1;
    }

    int test_number = std::stoi(argv[1]);

    switch (test_number) {
    case 1:
        a1();
        break;
    case 2:
        a2();
        break;
    case 3:
        a3();
        break;
    case 4:
        a4();
        break;
    case 5:
        a5();
        break;
    default:
        std::cerr << "Invalid test number" << std::endl;
        return 1;
    }

    return 0; // This will never be reached due to std::exit calls
}