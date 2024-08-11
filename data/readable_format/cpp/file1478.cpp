// finish.cpp
#include <iostream>
#include <cstdlib>

void FINISH() {
    std::cout << "This program will halt." << std::endl;
    std::exit(0); // Exit the program with a status code of 0 (indicating success)
}

int main() {
    FINISH();
    return 0; // This line will never be reached
}