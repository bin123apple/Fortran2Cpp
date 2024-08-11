#include <deque>
#include <memory>
#include <iostream>
#include <cassert>

// Assuming Container is an abstract class you wanted to use.
class Container {
public:
    virtual ~Container() = default;
};

class IntContainer : public Container {
public:
    int value;
    explicit IntContainer(int val) : value(val) {}
};

class Deque {
public:
    virtual ~Deque() = default;
    virtual void pushLeft(std::shared_ptr<Container> item) = 0;
    virtual void pushRight(std::shared_ptr<Container> item) = 0;
    virtual std::shared_ptr<Container> popLeft() = 0;
    virtual std::shared_ptr<Container> popRight() = 0;
    virtual std::shared_ptr<Container> peekLeft() const = 0;
    virtual std::shared_ptr<Container> peekRight() const = 0;
};

class SimpleDeque : public Deque {
private:
    std::deque<std::shared_ptr<Container>> data;
public:
    void pushLeft(std::shared_ptr<Container> item) override {
        data.push_front(item);
    }

    void pushRight(std::shared_ptr<Container> item) override {
        data.push_back(item);
    }

    std::shared_ptr<Container> popLeft() override {
        if (data.empty()) return nullptr;
        auto item = data.front();
        data.pop_front();
        return item;
    }

    std::shared_ptr<Container> popRight() override {
        if (data.empty()) return nullptr;
        auto item = data.back();
        data.pop_back();
        return item;
    }

    std::shared_ptr<Container> peekLeft() const override {
        if (data.empty()) return nullptr;
        return data.front();
    }

    std::shared_ptr<Container> peekRight() const override {
        if (data.empty()) return nullptr;
        return data.back();
    }
};

void testDeque() {
    SimpleDeque dq;
    dq.pushLeft(std::make_shared<IntContainer>(10));
    dq.pushLeft(std::make_shared<IntContainer>(20));

    assert(dynamic_cast<IntContainer*>(dq.peekLeft().get())->value == 20);
    std::cout << "Test peekLeft passed" << std::endl;

    assert(dynamic_cast<IntContainer*>(dq.popLeft().get())->value == 20);
    std::cout << "Test popLeft passed" << std::endl;

    // Add more tests for pushRight, popRight, and peekRight as needed.
}

int main() {
    testDeque();
    return 0;
}