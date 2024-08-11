#include <iostream>

// Define the type for the function pointer
typedef int (*ExtrnFunc)(int, int, int, int, int, int, int, int, int, int,
                         int, int, int, int, int, int, int, int, int, int,
                         int, int, int, int, int, int, int, int, int, int,
                         int, int, int, int, int, int, int, int, int, int, int);

// Define the qqqcall function
int qqqcall(ExtrnFunc extrn,
            int p1, int p2, int p3, int p4, int p5, int p6, int p7, int p8, int p9, int p10,
            int p11, int p12, int p13, int p14, int p15, int p16, int p17, int p18, int p19, int p20,
            int p21, int p22, int p23, int p24, int p25, int p26, int p27, int p28, int p29, int p30,
            int p31, int p32, int p33, int p34, int p35, int p36, int p37, int p38, int p39, int p40, int p41) {
    // Call the function pointer with all the parameters and return the result
    return extrn(p1, p2, p3, p4, p5, p6, p7, p8, p9, p10,
                 p11, p12, p13, p14, p15, p16, p17, p18, p19, p20,
                 p21, p22, p23, p24, p25, p26, p27, p28, p29, p30,
                 p31, p32, p33, p34, p35, p36, p37, p38, p39, p40, p41);
}

// Example function matching the ExtrnFunc signature
int sum41(int p1, int p2, int p3, int p4, int p5, int p6, int p7, int p8, int p9, int p10,
          int p11, int p12, int p13, int p14, int p15, int p16, int p17, int p18, int p19, int p20,
          int p21, int p22, int p23, int p24, int p25, int p26, int p27, int p28, int p29, int p30,
          int p31, int p32, int p33, int p34, int p35, int p36, int p37, int p38, int p39, int p40, int p41) {
    return p1 + p2 + p3 + p4 + p5 + p6 + p7 + p8 + p9 + p10 +
           p11 + p12 + p13 + p14 + p15 + p16 + p17 + p18 + p19 + p20 +
           p21 + p22 + p23 + p24 + p25 + p26 + p27 + p28 + p29 + p30 +
           p31 + p32 + p33 + p34 + p35 + p36 + p37 + p38 + p39 + p40 + p41;
}

int main() {
    // Test the qqqcall function with sum41 and 41 integers
    int result = qqqcall(sum41, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                         1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                         1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1);
    std::cout << "Test sum41 via qqqcall: " << result << std::endl; // Expected output: 41

    return 0;
}