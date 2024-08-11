#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <gtest/gtest.h>

class a {
protected:
    std::vector<float> x;
public:
    a() {}
    a(std::initializer_list<float> list) : x(list) {}
    // Accessor for x to facilitate testing
    std::vector<float> getX() const { return x; }
};

class b {
private:
    std::vector<float> x;
    int i;
public:
    b() {}
    b(std::initializer_list<float> list, int ini) : x(list), i(ini) {}
    friend b set_b();
    friend void check_b(const b&);
    // Accessors for testing
    std::vector<float> getX() const { return x; }
    int getI() const { return i; }
};

b set_b() {
    b res({10.0, 20.0}, 1);
    return res;
}

void check_b(const b& arg) {
    if (std::any_of(arg.x.begin(), arg.x.end(), [](float val) { return val != 10.0 && val != 20.0; })) {
        std::abort();
    }
    if (arg.i != 1) {
        std::abort();
    }
}

class f : public a {
private:
    int if_;
public:
    f(std::initializer_list<float> list, int ini) : a(list), if_(ini) {}
    int getIf() const { return if_; }
};

class d : public b {
private:
    int id;
public:
    d(b base, int ini) : b(base), id(ini) {}
    int getId() const { return id; }
};

// Unit Tests with Google Test
TEST(MyModuleTest, TestTypeF) {
    f p({1.0, 2.0}, 3);
    ASSERT_EQ(p.getX().size(), 2);
    ASSERT_FLOAT_EQ(p.getX()[0], 1.0);
    ASSERT_FLOAT_EQ(p.getX()[1], 2.0);
    ASSERT_EQ(p.getIf(), 3);
}

TEST(MyModuleTest, TestTypeD) {
    d q(set_b(), 99);
    check_b(q); // This function calls std::abort() upon failure, so no need for an ASSERT here.
    ASSERT_EQ(q.getId(), 99);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}