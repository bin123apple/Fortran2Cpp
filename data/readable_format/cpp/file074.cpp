#include <iostream>
#include <cstdlib>

struct T {
    int X;
    int Y;
};

int main() {
    T S;

    S.X = 1;
    S.Y = 2;

    {
        struct T {
            int X;
            int Y;
        };

        T S;

        S.X = 3;
        S.Y = 4;
    }

    {
        struct T {
            int X;
            int Y;
        };

        T S;

        S.X = 5;
        S.Y = 6;
    }

    // Since the inner structs T and their instances S are scoped within their blocks,
    // they do not affect the outer S. Thus, the condition checks the state of the outer S.
    if (S.X != 1 || S.X != 2) {
        std::exit(1);
    }

    return 0;
}