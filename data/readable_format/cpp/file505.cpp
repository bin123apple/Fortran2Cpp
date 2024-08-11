#include <iostream>
#include <ctime>

void mycpu_time(double &poo) {
    // clock() returns the processor time consumed by the program.
    poo = static_cast<double>(clock()) / CLOCKS_PER_SEC;
}

int main() {
    double poo = 0;
    mycpu_time(poo);
    std::cout << "CPU Time: " << poo << " seconds" << std::endl;
    return 0;
}