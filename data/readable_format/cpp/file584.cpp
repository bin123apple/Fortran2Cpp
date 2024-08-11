#include <gtest/gtest.h>
#include <string>

// Assuming global definitions are similar to those in the Fortran version
constexpr double rb = 8.0;
constexpr double zero = 0.0;

class cModel {
public:
    std::string name = "";
    virtual ~cModel() = default;
};

class cAngleModel : public cModel {
public:
    virtual void compute(double& Ea, double& Fa, double theta) = 0;
};

class angle_none : public cAngleModel {
public:
    void setup() {
        name = "none";
    }

    void compute(double& Ea, double& Fa, double theta) override {
        Ea = zero;
        Fa = zero;
    }
};

// Test fixture for angle_none
class angle_none_Test : public ::testing::Test {
protected:
    angle_none* model = nullptr;

    void SetUp() override {
        model = new angle_none();
        model->setup();
    }

    void TearDown() override {
        delete model;
    }
};

// Test setup method
TEST_F(angle_none_Test, TestSetup) {
    EXPECT_EQ(model->name, "none");
}

// Test compute method
TEST_F(angle_none_Test, TestCompute) {
    double Ea, Fa;
    double theta = 1.0;

    model->compute(Ea, Fa, theta);

    EXPECT_DOUBLE_EQ(Ea, zero);
    EXPECT_DOUBLE_EQ(Fa, zero);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}