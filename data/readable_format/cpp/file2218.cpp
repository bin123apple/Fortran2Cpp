#include <iostream>
#include <vector>
#include <memory>

// Assuming MemoryType is a simple class with an integer value
class MemoryType {
public:
    int value;
    explicit MemoryType(int v) : value(v) {}
};

class MemoryListType {
public:
    void add(std::shared_ptr<MemoryType> mt) {
        list.push_back(mt);
    }

    std::shared_ptr<MemoryType> get(int ipos) const {
        if (ipos < 0 || ipos >= list.size()) {
            throw std::out_of_range("Index out of range");
        }
        return list[ipos];
    }

    int count() const {
        return list.size();
    }

    void clear() {
        list.clear();
    }

private:
    std::vector<std::shared_ptr<MemoryType>> list;
};

// Simple test framework
class TestMemoryListType {
public:
    static void runTests() {
        testAdd();
        testGet();
        testCount();
        testClear();
    }

private:
    static void testAdd() {
        MemoryListType list;
        list.add(std::make_shared<MemoryType>(42));
        std::cout << "Test Add: " << ((list.count() == 1) ? "Passed" : "Failed") << std::endl;
    }

    static void testGet() {
        MemoryListType list;
        auto item = std::make_shared<MemoryType>(42);
        list.add(item);
        std::cout << "Test Get: " << ((list.get(0)->value == 42) ? "Passed" : "Failed") << std::endl;
    }

    static void testCount() {
        MemoryListType list;
        list.add(std::make_shared<MemoryType>(42));
        std::cout << "Test Count: " << ((list.count() == 1) ? "Passed" : "Failed") << std::endl;
    }

    static void testClear() {
        MemoryListType list;
        list.add(std::make_shared<MemoryType>(42));
        list.clear();
        std::cout << "Test Clear: " << ((list.count() == 0) ? "Passed" : "Failed") << std::endl;
    }
};

int main() {
    TestMemoryListType::runTests();
    return 0;
}