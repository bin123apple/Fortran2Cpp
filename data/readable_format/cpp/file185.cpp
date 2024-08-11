#include <gtest/gtest.h>
#include <string>
#include <vector>

// Definition of the Person struct
struct Person {
    std::string forename;
    int age;

    Person() : forename(""), age(0) {}
    Person(const std::string& name, int ageVal) : forename(name), age(ageVal) {}
};

// Definition of the Color enum class
enum class Color : int {
    red = 4,
    blue = 9,
    yellow // 10, automatically increments
};

// Definition of the SolveInterface
class SolveInterface {
public:
    virtual std::vector<double> solve(int n, std::vector<double>* pmatrix, int key) = 0;
};

// Dummy implementation of SolveInterface
class SolveImpl : public SolveInterface {
public:
    std::vector<double> solve(int n, std::vector<double>* pmatrix, int key) override {
        // Dummy implementation
        std::vector<double> result(n, 0.0); // Just return a vector of zeros for demonstration
        return result;
    }
};

// Unit tests

// Test the Person struct
TEST(PersonTest, Initialization) {
    Person p("John", 30);
    EXPECT_EQ(p.forename, "John");
    EXPECT_EQ(p.age, 30);
}

// Test the enum class Color
TEST(ColorTest, Values) {
    EXPECT_EQ(static_cast<int>(Color::red), 4);
    EXPECT_EQ(static_cast<int>(Color::blue), 9);
    EXPECT_EQ(static_cast<int>(Color::yellow), 10);
}

// Test the dummy SolveImpl class
TEST(SolveImplTest, DummySolve) {
    SolveImpl solver;
    std::vector<double> matrix = {1.0, 2.0, 3.0, 4.0};
    auto result = solver.solve(4, &matrix, 1);

    EXPECT_EQ(result.size(), 4);
    for (const auto& val : result) {
        EXPECT_EQ(val, 0.0);
    }
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}