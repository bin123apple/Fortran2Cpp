#include <gtest/gtest.h>
#include <cstdint> // For std::int32_t

// Assuming the translated C++ code starts here

namespace m {

struct bindc_t {
    std::int32_t x;
};

class sequence_t {
public:
    virtual ~sequence_t() = 0;
    std::int32_t x;
};

sequence_t::~sequence_t() {}

class abst_t {
public:
    abst_t() = default;
    virtual ~abst_t() = 0;
    int x = 0;
};

abst_t::~abst_t() {}

class concrete_t : public abst_t {
public:
    int y = 1;
};

class myt {
public:
    abst_t* comp; // Pointer to abstract class because we cannot instantiate abst_t directly.
};

class again_abst_t : public concrete_t {
public:
    again_abst_t() = default;
    virtual ~again_abst_t() = 0;
    int z = 2;
};

again_abst_t::~again_abst_t() {}

// Test code starts here.

// Test for concrete_t inheritance and member initialization.
TEST(ConcreteTTest, InheritsAbstTAndInitializesMembers) {
    concrete_t obj;
    EXPECT_EQ(obj.x, 0); // Check if `x` is initialized as per abst_t
    EXPECT_EQ(obj.y, 1); // Check if `y` is initialized as per concrete_t
}

// Since abst_t and again_abst_t are abstract, we can't instantiate them directly.
// However, we can test their behavior through derived classes.
class TestAgainAbstT : public again_abst_t {
public:
    TestAgainAbstT() = default;
};

// Test for again_abst_t inheritance and member initialization.
TEST(AgainAbstTTest, InheritsConcreteTAndInitializesMembers) {
    TestAgainAbstT obj;
    EXPECT_EQ(obj.x, 0); // Check if `x` is initialized as per abst_t
    EXPECT_EQ(obj.y, 1); // Check if `y` is initialized as per concrete_t
    EXPECT_EQ(obj.z, 2); // Check if `z` is initialized as per again_abst_t
}

} // namespace m

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}