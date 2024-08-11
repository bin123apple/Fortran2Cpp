#include <iostream>
#include <cassert>
#include <vector>

// Assuming the definitions of Foo and Foo1 classes are properly included or declared above...
class Foo {
public:
    int num;
    Foo(int n = 0) : num(n) {}
    void setNum(int newNum) {
        num = newNum;
    }
};

Foo createFoo(int val) {
    return Foo(val);
}

class Foo1 : public Foo {
public:
    std::vector<float> arr;
    Foo1(int n = 0, std::initializer_list<float> a = {}) : Foo(n), arr(a) {}
};

void testCreateFoo() {
    Foo f = createFoo(10);
    assert(f.num == 10);
    std::cout << "testCreateFoo PASSED" << std::endl;
}

void testSetNum() {
    Foo f(5);
    f.setNum(20);
    assert(f.num == 20);
    std::cout << "testSetNum (Foo) PASSED" << std::endl;

    Foo1 f1;
    f1.setNum(30);
    assert(f1.num == 30);
    std::cout << "testSetNum (Foo1) PASSED" << std::endl;
}

void testFoo1Array() {
    Foo1 f1(0, {1.0, 2.0, 3.0});
    assert(f1.arr.size() == 3);
    assert(f1.arr[1] == 2.0); // Checking one element, as an example
    std::cout << "testFoo1Array PASSED" << std::endl;
}

int main() {
    testCreateFoo();
    testSetNum();
    testFoo1Array();

    std::cout << "All tests PASSED" << std::endl;
    return 0;
}