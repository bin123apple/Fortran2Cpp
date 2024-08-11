#include <iostream>
#include <cassert>

class UpdateVelocElasticNewmark {
public:
    static float updateVelocElasticNewmark(float old_velocity, float acceleration, float time) {
        return old_velocity + acceleration * time;
    }
};

// A simple function to test UpdateVelocElasticNewmark::updateVelocElasticNewmark
void testUpdateVelocElasticNewmark() {
    float old_velocity = 5.0f;
    float acceleration = 2.0f;
    float time = 3.0f;
    float expected_new_velocity = 11.0f; // Expected result based on the given inputs

    float new_velocity = UpdateVelocElasticNewmark::updateVelocElasticNewmark(old_velocity, acceleration, time);

    assert(new_velocity == expected_new_velocity && "Test failed: The new velocity calculation is incorrect.");
    std::cout << "Test passed: The new velocity calculation is correct." << std::endl;
}

int main() {
    // Call the test function
    testUpdateVelocElasticNewmark();

    return 0;
}