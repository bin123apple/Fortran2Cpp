#include <iostream>
#include <memory>

class LinkedNode {
    // Base class for linked nodes.
    // This should contain the common functionality for linked nodes.
    // For simplicity, it is left empty here.
};

class BidirNode : public LinkedNode {
private:
    std::shared_ptr<BidirNode> prev;

public:
    BidirNode() : prev(nullptr) {}

    bool has_prev() const {
        return prev != nullptr;
    }

    std::shared_ptr<BidirNode> get_prev() const {
        if (has_prev()) {
            return prev;
        } else {
            return nullptr;
        }
    }

    void set_prev(const std::shared_ptr<BidirNode>& new_prev, bool deallocate_old = false) {
        unset_prev(deallocate_old);
        prev = new_prev;
    }

    void unset_prev(bool deallocate_old = false) {
        if (!has_prev()) return;

        if (deallocate_old) {
            if (prev) {
                prev->unset_prev(true);
                prev.reset();
            }
        } else {
            prev.reset();
        }
    }
};

int main() {
    auto node1 = std::make_shared<BidirNode>();
    auto node2 = std::make_shared<BidirNode>();

    node1->set_prev(node2);
    std::cout << "Node1 has prev: " << node1->has_prev() << std::endl;
    node1->unset_prev();
    std::cout << "Node1 has prev: " << node1->has_prev() << std::endl;

    return 0;
}