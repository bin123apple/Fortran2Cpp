#include <iostream>
#include <gtest/gtest.h>

// FluidModelToy class definition and implementation
class FluidModelToy {
public:
    double density;
    double velocity;
    double pressure;

    FluidModelToy() : density(0.0), velocity(0.0), pressure(0.0) {}

    void initialize() {
        density = 1.0;
        velocity = 2.0;
        pressure = 101.3;
    }

    void calculate() {
        pressure = density * velocity * 2.0;
    }

    void deleteModel() {
        density = 0.0;
        velocity = 0.0;
        pressure = 0.0;
    }
};

// Unit tests for FluidModelToy
TEST(FluidModelToyTest, Initialization) {
    FluidModelToy model;
    model.initialize();
    EXPECT_DOUBLE_EQ(1.0, model.density);
    EXPECT_DOUBLE_EQ(2.0, model.velocity);
    EXPECT_DOUBLE_EQ(101.3, model.pressure);
}

TEST(FluidModelToyTest, Calculation) {
    FluidModelToy model;
    model.initialize();
    model.calculate();
    EXPECT_DOUBLE_EQ(4.0, model.pressure);
}

TEST(FluidModelToyTest, Deletion) {
    FluidModelToy model;
    model.initialize();
    model.deleteModel();
    EXPECT_DOUBLE_EQ(0.0, model.density);
    EXPECT_DOUBLE_EQ(0.0, model.velocity);
    EXPECT_DOUBLE_EQ(0.0, model.pressure);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}