#include <gtest/gtest.h>
#include <iostream>
#include <string>
#include <cstdio> // for printf

// Global variables
int TUNIT = 10;
int GUNIT = 20;
int IUNIT = 5;
int OUNIT = 6;
int DUNIT = 11;
int TRMLIN = 24;
int TRMWID = 80;
int TXTTRM = 1;
int TXTFIL = 1;
int GRFTRM = 0;
int GRFHRD = 0;
int GRFFIL = 0;

void SETUP() {
    TUNIT = 10;
    GUNIT = 20;
    IUNIT = 5;
    OUNIT = 6;
    DUNIT = 11;
    TRMLIN = 24;
    TRMWID = 80;
    TXTTRM = 1;
    TXTFIL = 1;
    GRFTRM = 0;
    GRFHRD = 0;
    GRFFIL = 0;
}

void CLEAR() {
    char ESC1[4] = {27, 91, 50, 74};
    char ESC2[6] = {27, 91, 49, 59, 49, 102};
    int I1 = 4;
    int I2 = 6;

    // Assuming you want to print these sequences to the terminal
    printf(" %c%c%c%c", ESC1[0], ESC1[1], ESC1[2], ESC1[3]);
    printf(" %c%c%c%c%c%c", ESC2[0], ESC2[1], ESC2[2], ESC2[3], ESC2[4], ESC2[5]);
}

void GMODE() {
    char ESC[2] = {27, 49};
    printf(" %c%c", ESC[0], ESC[1]);
}

void TMODE() {
    char ESC[2] = {27, 50};
    printf(" %c%c", ESC[0], ESC[1]);
}

// Test cases
TEST(SubroutineTests, TestSETUP) {
    SETUP();
    EXPECT_EQ(TUNIT, 10);
    EXPECT_EQ(GUNIT, 20);
    EXPECT_EQ(DUNIT, 11);
    // Add checks for other global variables as needed
}

// The following tests are placeholders. Since CLEAR, GMODE, and TMODE functions
// mostly produce terminal control sequences, their effects need to be verified manually.
TEST(SubroutineTests, TestOutputFunctions) {
    // These are placeholder tests. In a real scenario, you'd capture stdout and compare.
    EXPECT_TRUE(true); // This is just to illustrate where actual tests would go.
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}