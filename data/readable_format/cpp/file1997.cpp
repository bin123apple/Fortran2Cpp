#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath> // for fabs function

class SoopStars {
public:
    std::vector<float> position, velocity;

    SoopStars() = default;
    SoopStars(const std::vector<float>& pos, const std::vector<float>& vel) : position(pos), velocity(vel) {}

    SoopStars operator+(const SoopStars& rhs) const {
        std::vector<float> newPos(position.size()), newVel(velocity.size());
        std::transform(position.begin(), position.end(), rhs.position.begin(), newPos.begin(), std::plus<>());
        std::transform(velocity.begin(), velocity.end(), rhs.velocity.begin(), newVel.begin(), std::plus<>());
        return {newPos, newVel};
    }

    SoopStars operator*(float rhs) const {
        std::vector<float> newPos(position.size()), newVel(velocity.size());
        std::transform(position.begin(), position.end(), newPos.begin(), [rhs](float val) { return val * rhs; });
        std::transform(velocity.begin(), velocity.end(), newVel.begin(), [rhs](float val) { return val * rhs; });
        return {newPos, newVel};
    }
};

// A simple testing framework
void test(const std::string& testName, bool condition) {
    std::cout << "Test " << testName << ": " << (condition ? "PASSED" : "FAILED") << std::endl;
}

// Function to compare two vectors for approximate equality
bool vectorsAreEqual(const std::vector<float>& v1, const std::vector<float>& v2, float tolerance = 1e-5) {
    if (v1.size() != v2.size()) return false;
    for (size_t i = 0; i < v1.size(); ++i) {
        if (std::fabs(v1[i] - v2[i]) > tolerance) return false;
    }
    return true;
}

int main() {
    // Test instances
    SoopStars star1({1, 2, 3}, {4, 5, 6});
    SoopStars star2({0.5, 1, 1.5}, {2, 2.5, 3});
    float factor = 2.0f;

    SoopStars sumResult = star1 + star2;
    SoopStars productResult = star1 * factor;

    // Testing +
    test("+ operator",
         vectorsAreEqual(sumResult.position, {1.5, 3, 4.5}) &&
         vectorsAreEqual(sumResult.velocity, {6, 7.5, 9}));

    // Testing *
    test("* operator",
         vectorsAreEqual(productResult.position, {2, 4, 6}) &&
         vectorsAreEqual(productResult.velocity, {8, 10, 12}));

    return 0;
}