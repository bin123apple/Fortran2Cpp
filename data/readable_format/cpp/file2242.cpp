#include <iostream>
#include <vector>
#include <memory>
#include <stdexcept>

class Foo {
public:
    int i = 2;

    virtual ~Foo() = default;
};

class Foo1 : public Foo {
public:
    float r[2];
};

void subpr(Foo& x) {
    x.i = 3;
}

void subpr_elem(Foo& x) {
    x.i = 3;
}

void subpr_array(std::vector<std::shared_ptr<Foo>>& x) {
    for (auto& xi : x) {
        xi->i = 3;
    }
}

void subpr2(const Foo& x) {
    if (x.i != 55) {
        std::abort();
    }
}

void subpr2_array(const std::vector<std::shared_ptr<Foo>>& x) {
    for (const auto& xi : x) {
        if (xi->i != 55) {
            std::abort();
        }
    }
}

std::shared_ptr<Foo> f() {
    auto result = std::make_shared<Foo>();
    result->i = 55;
    return result;
}

std::vector<std::shared_ptr<Foo>> g() {
    std::vector<std::shared_ptr<Foo>> result(3);
    for (auto& res : result) {
        res = std::make_shared<Foo>();
        res->i = 55;
    }
    return result;
}

int main() {
    std::shared_ptr<Foo> xx;
    std::vector<std::shared_ptr<Foo>> yy;

    xx = std::make_shared<Foo1>();
    xx->i = 33;
    subpr(*xx);
    if (xx->i != 3) {
        std::abort();
    }

    xx->i = 33;
    subpr_elem(*xx);
    if (xx->i != 3) {
        std::abort();
    }

    subpr(*f());

    yy.resize(2);
    for (auto& y : yy) {
        y = std::make_shared<Foo1>();
        y->i = 33;
    }
    for (auto& y : yy) {
        subpr_elem(*y);
    }
    for (const auto& y : yy) {
        if (y->i != 3) {
            std::abort();
        }
    }

    for (auto& y : yy) {
        y->i = 33;
    }
    subpr_elem(*yy[0]);
    if (yy[0]->i != 3) {
        std::abort();
    }

    for (auto& y : yy) {
        y->i = 33;
    }
    subpr_array(yy);
    for (const auto& y : yy) {
        if (y->i != 3) {
            std::abort();
        }
    }

    for (auto& y : yy) {
        y->i = 33;
    }
    subpr_array(yy);
    for (const auto& y : yy) {
        if (y->i != 3) {
            std::abort();
        }
    }

    subpr2_array(g());

    return 0;
}