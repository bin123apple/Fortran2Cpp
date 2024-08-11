#include <iostream>
#include <vector>
#include <algorithm>

class Vector {
private:
    int index_;
    int length_real_ = 0;
    std::vector<int> nodes_;

public:
    Vector() {}

    void set(int index) {
        index_ = index;
    }

    void deleteAll() {
        nodes_.clear();
        length_real_ = 0;
    }

    void addWithSort(int node0) {
        if (index_ > node0) return;

        auto it = std::lower_bound(nodes_.begin(), nodes_.end(), node0);
        if (it != nodes_.end() && *it == node0) return; // Avoid duplicates

        nodes_.insert(it, node0);
        length_real_++;
    }

    void print() const {
        for (int i = 0; i < length_real_; ++i) {
            std::cout << nodes_[i] << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    Vector vec;

    vec.set(10);
    vec.addWithSort(5);
    vec.addWithSort(3);
    vec.addWithSort(7);

    std::cout << "Elements after adding: ";
    vec.print();

    vec.deleteAll();

    std::cout << "Elements after deleting (should be empty): ";
    vec.print();

    return 0;
}