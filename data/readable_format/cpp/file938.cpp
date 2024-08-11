#include <iostream>
#include <memory>

class person {
public:
    int ss = 1;
};

class education : public person {
public:
    int attainment = 0;
};

class service : public education {
public:
    int personnel_number = 0;
};

class person_record : public service {
public:
    std::unique_ptr<person_record> supervisor = nullptr;
};

// Test function declaration
void test_person_record_initialization();

int main() {
    // Run tests
    test_person_record_initialization();

    return 0;
}

// Test function definition
void test_person_record_initialization() {
    person_record recruit;

    recruit.ss = 2; // This should change 'ss' to 2.
    recruit.personnel_number = 6; // This should change 'personnel_number' to 6.

    bool test_passed = true;

    // Check if values are as expected
    if (recruit.ss != 2) {
        std::cout << "Test failed: 'ss' was not correctly set to 2." << std::endl;
        test_passed = false;
    }
    if (recruit.personnel_number != 6) {
        std::cout << "Test failed: 'personnel_number' was not correctly set to 6." << std::endl;
        test_passed = false;
    }

    if (test_passed) {
        std::cout << "Test passed: person_record initialization is correct." << std::endl;
    }
}