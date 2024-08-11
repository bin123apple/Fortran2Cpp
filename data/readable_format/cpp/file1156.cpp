#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

struct CommonBlock {
    char s3[2][3]; // 2 elements of 3 characters each
    char s8[8];    // 8 characters
};

union Equivalence {
    CommonBlock com;
    char s6[6];
    char s2[3][2];
    char s4[2][4];
    char s8e[8];
    char s1[5];
};

int main() {
    ofstream outFile("output_cpp.txt");
    Equivalence eq;

    strncpy(eq.com.s3[0], "AbC", 3);
    strncpy(eq.com.s3[1], "dEf", 3);

    // Note: std::endl is used to insert a newline and flush the stream
    outFile.write(eq.s6, 6) << std::endl;

    strncpy(eq.s6, "PqrStu", 6);

    for (int i = 0; i < 3; ++i) {
        outFile.write(eq.s2[i], 2) << std::endl;
    }

    strncpy(eq.s2[0], "gH", 2);
    strncpy(eq.s2[1], "Ij", 2);
    strncpy(eq.s2[2], "kL", 2);

    for (int i = 0; i < 2; ++i) {
        outFile.write(eq.com.s3[i], 3) << std::endl;
    }

    strncpy(eq.s8e, "AbcdefgH", 8);

    for (int i = 0; i < 2; ++i) {
        outFile.write(eq.s4[i], 4) << std::endl;
    }

    for (int i = 0; i < 5; ++i) {
        outFile << eq.s1[i] << std::endl;
    }

    outFile.close();
    return 0;
}