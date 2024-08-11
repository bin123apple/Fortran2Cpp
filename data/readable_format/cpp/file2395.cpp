#include <iostream>
#include <optional>

void s1_c1107() {
    std::cout << "s1_c1107 executed." << std::endl;
}

void s2_c1107() {
    std::cout << "s2_c1107 executed." << std::endl;
}

void s3_c1107(int x_in, int& x_out) {
    x_out = x_in * 2;
    std::cout << "s3_c1107 executed with x_out = " << x_out << std::endl;
}

void s4_c1107() {
    std::cout << "s4_c1107 executed." << std::endl;
}

void s5_c1107(int x, int& y) {
    y = x * 2;
    std::cout << "s5_c1107 executed with y = " << y << std::endl;
}

void s6_c1107() {
    std::cout << "s6_c1107 executed without arguments." << std::endl;
}

void s7_c1107() {
    std::cout << "s7_c1107 executed." << std::endl;
}

int main() {
    int x_out, y;
    s1_c1107();
    s2_c1107();
    s3_c1107(5, x_out);
    s4_c1107();
    s5_c1107(10, y);
    s6_c1107();
    s7_c1107();
    return 0;
}