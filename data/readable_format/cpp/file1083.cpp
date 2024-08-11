#include <iostream>
#include <cstdlib> // For std::exit

struct MyType {
    int a, b, c;
};

int main() {
    MyType myVar;
    myVar.a = 0;
    myVar.b = 0;
    myVar.c = 0;

    myVar.a = 1;
    myVar.b = 2;
    myVar.c = 3;

    if (myVar.a != 1) std::exit(1);
    if (myVar.b != 2) std::exit(2);
    if (myVar.c != 3) std::exit(3);

    return 0;
}