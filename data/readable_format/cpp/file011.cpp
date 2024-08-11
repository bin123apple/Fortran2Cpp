#include <iostream>

int G01PBL(int NCHARS, int NBYTES) {
    int LEN = 1 + NCHARS + NBYTES;

    if (NCHARS > 254) {
        LEN += 2;
    }

    return LEN;
}

// Example usage
int main() {
    int NCHARS = 255;
    int NBYTES = 10;
    int result = G01PBL(NCHARS, NBYTES);
    std::cout << "Result: " << result << std::endl;
    return 0;
}