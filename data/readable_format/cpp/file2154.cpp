#include <iostream>
#include <memory>

// Define the Test class
class Test {
public:
    int i;
    Test(int value) : i(value) {}
};

// Define the TestReference class
class TestReference {
public:
    std::shared_ptr<Test> test;
    TestReference(std::shared_ptr<Test> t) : test(t) {}
};

int main() {
    // Create instances of Test and TestReference
    std::shared_ptr<Test> x = std::make_shared<Test>(99);
    TestReference testList(x);

    // Access the test member from testList
    std::shared_ptr<Test> y = testList.test;

    // Check if the values are equal
    if (x->i != y->i) {
        std::cerr << "STOP 1" << std::endl;
        return 1;
    }

    // Following the logic of the select type construct
    if (y) {
        if (x->i != y->i) {
            std::cerr << "STOP 1" << std::endl;
            return 1;
        }
    } else {
        std::cerr << "STOP 2" << std::endl;
        return 2;
    }

    return 0;
}