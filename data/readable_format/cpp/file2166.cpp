#include <iostream>
#include <vector>
#include <memory>

struct RealData_t {
    double value;
    std::shared_ptr<RealData_t> next = nullptr;
};

class RealDataLinkedList_t {
private:
    std::shared_ptr<RealData_t> head = nullptr;
    int no_of_entries = 0;

public:
    void Append(double value) {
        if (!head) {
            head = std::make_shared<RealData_t>();
            head->value = value;
            no_of_entries = 1;
        } else {
            auto current = head;
            while (current->next) {
                current = current->next;
            }
            current->next = std::make_shared<RealData_t>();
            current->next->value = value;
            no_of_entries++;
        }
    }

    std::vector<double> Load() const {
        std::vector<double> values;
        auto current = head;
        while (current) {
            values.push_back(current->value);
            current = current->next;
        }
        return values;
    }
};

// Example usage and simple test
int main() {
    RealDataLinkedList_t list;
    list.Append(1.0);
    list.Append(2.0);
    list.Append(3.0);

    std::vector<double> data = list.Load();

    std::cout << "List contents:" << std::endl;
    for (const auto& val : data) {
        std::cout << val << std::endl;
    }

    // Simple test to verify the contents
    std::vector<double> expected = {1.0, 2.0, 3.0};
    bool testPassed = data == expected;
    std::cout << "Test " << (testPassed ? "PASSED" : "FAILED") << std::endl;

    return 0;
}