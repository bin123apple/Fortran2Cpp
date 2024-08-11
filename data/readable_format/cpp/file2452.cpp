#include <iostream>
#include <sstream>
#include <string>
#include <cassert>

struct xyz_type {
    int x;
    std::string y;
    bool z;
};

struct abcdef_type {
    int a;
    bool b;
    xyz_type c;
    int d;
    float e;
    std::string f;
};

void test_routine(const xyz_type* xyz, const abcdef_type& abcdef) {
    std::cout << "Testing xyz(1)" << std::endl;
    std::cout << xyz[0].x << " " << xyz[0].y << " " << std::boolalpha << xyz[0].z << std::endl;
    std::cout << "Testing abcdef" << std::endl;
    std::cout << abcdef.a << " " << std::boolalpha << abcdef.b << " " <<
              abcdef.c.x << " " << abcdef.c.y << " " << abcdef.c.z << " " <<
              abcdef.d << " " << abcdef.e << " " << abcdef.f << std::endl;
}

int main() {
    xyz_type xyz[2] = {
        {11111, "hello world", true},
        {0, "go away", false}
    };

    abcdef_type abcdef = {
        0, true, xyz[0], 3, 4.0f, "kawabanga"
    };

    test_routine(xyz, abcdef);

    return 0;
}