#include <iostream>
#include <vector>
#include <memory>
#include <cassert>

// Equivalent to the `ele_numbering_type` in Fortran
struct EleNumberingType {
    std::shared_ptr<std::vector<std::vector<int>>> number2count;
};

// Equivalent to the `element_type` in Fortran
struct ElementType {
    std::shared_ptr<EleNumberingType> numbering;
};

// Equivalent to the `global_numbering` module in Fortran
class GlobalNumbering {
public:
    static std::vector<float> elementLocalCoords(const ElementType& element) {
        std::vector<float> coords(element.numbering->number2count->size(), 0.0f);
        return coords;
    }
};

int main() {
    // Setup
    auto ent = std::make_shared<EleNumberingType>();
    ent->number2count = std::make_shared<std::vector<std::vector<int>>>(2, std::vector<int>(2, 0));
    (*ent->number2count)[0] = {1, 2};
    (*ent->number2count)[1] = {3, 4};

    ElementType e;
    e.numbering = ent;

    // Test dynamic allocation and structure contents
    assert((*e.numbering->number2count)[0][0] == 1 && "Test failed: Incorrect array contents.");
    assert((*e.numbering->number2count)[0][1] == 2 && "Test failed: Incorrect array contents.");
    assert((*e.numbering->number2count)[1][0] == 3 && "Test failed: Incorrect array contents.");
    assert((*e.numbering->number2count)[1][1] == 4 && "Test failed: Incorrect array contents.");
    
    // Test elementLocalCoords function
    std::vector<float> coords = GlobalNumbering::elementLocalCoords(e);
    assert(coords.size() == 2 && "Test failed: Incorrect vector size.");
    assert(coords[0] == 0.0f && "Test failed: Incorrect coordinate value.");
    assert(coords[1] == 0.0f && "Test failed: Incorrect coordinate value.");

    std::cout << "All tests passed." << std::endl;

    return 0;
}