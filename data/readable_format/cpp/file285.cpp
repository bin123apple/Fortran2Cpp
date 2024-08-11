#include <iostream>
#include <complex>
#include <string>
#include <gtest/gtest.h>

class Foo {
public:
    static int n1(int a);
    static int n2(int b);
    static std::complex<double> z1(std::complex<double> u);
    static std::complex<double> z2(std::complex<double> v);
    static int n3(int d);
    static std::string c1(std::string a);
    static std::string c2(std::string b);

private:
    static int c; // Used to emulate the 'save' attribute in Fortran
};

int Foo::c = 0;

int Foo::n1(int a) {
    Foo::c = a;
    return c * c * c; // Equivalent to c**3 in Fortran
}

int Foo::n2(int b) {
    int n2 = Foo::c * b;
    return n2 * n2; // Equivalent to n2**2 in Fortran
}

std::complex<double> Foo::z1(std::complex<double> u) {
    return std::complex<double>(1.0, 2.0) * u;
}

std::complex<double> Foo::z2(std::complex<double> v) {
    return std::complex<double>(3.0, 4.0) * v;
}

int Foo::n3(int d) {
    return Foo::n2(d) * Foo::n1(d);
}

std::string Foo::c1(std::string a) {
    if (a == "abcd") return "ABCD";
    return a;
}

std::string Foo::c2(std::string b) {
    if (b == "wxyz") return "WXYZ";
    return b;
}

// Unit tests using Google Test framework
TEST(FooTest, TestN1) {
    EXPECT_EQ(Foo::n1(9), 729);
}

TEST(FooTest, TestN2) {
    EXPECT_EQ(Foo::n2(2), 324);
}

TEST(FooTest, TestN3) {
    EXPECT_EQ(Foo::n3(19), 200564019);
}

TEST(FooTest, TestC1) {
    EXPECT_EQ(Foo::c1("lmno"), "lmno");
    EXPECT_EQ(Foo::c1("abcd"), "ABCD");
}

TEST(FooTest, TestC2) {
    EXPECT_EQ(Foo::c2("lmno"), "lmno");
    EXPECT_EQ(Foo::c2("wxyz"), "WXYZ");
}

TEST(FooTest, TestZ1) {
    EXPECT_EQ(Foo::z1(std::complex<double>(3, 4)), std::complex<double>(-5, 10));
}

TEST(FooTest, TestZ2) {
    EXPECT_EQ(Foo::z2(std::complex<double>(5, 6)), std::complex<double>(-9, 38));
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}