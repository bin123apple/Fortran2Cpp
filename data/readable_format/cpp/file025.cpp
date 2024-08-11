#include <iostream>
#include <vector>
#include <string>
#include <utility> // For std::pair

// Define a structure for the relationship
struct Relationship {
    std::string from;
    std::string to;

    Relationship(std::string f, std::string t) : from(f), to(t) {}
};

// Define a class to manage and test relationships
class GreatRelations {
private:
    std::vector<Relationship> relationships;

public:
    GreatRelations() {
        // Initialize a list of relationships
        relationships = {
            {"i1", "x1"},
            {"c1", "a1"},
            {"a1", "o1"},
            {"j1", "aa1"},
            {"h1", "l1"},
            {"ii1", "ff1"},
            {"bb1", "x1"},
            {"h1", "t1"},
            {"cc1", "dd1"},
            {"ff1", "u1"},
            {"ii1", "s1"},
            {"v1", "ee1"},
            {"g1", "b1"},
            {"d1", "k1"},
            {"ff1", "ll1"},
            {"r1", "bb1"},
            {"ii1", "m1"},
            {"u1", "p1"},
            {"hh1", "l1"},
            {"g1", "o1"},
            {"ii1", "o1"},
            {"z1", "j1"},
            {"y1", "w1"},
            {"ff1", "bb1"},
            {"cc1", "s1"},
            {"j1", "cc1"},
            {"hh1", "ee1"},
            {"cc1", "ll1"},
            {"u1", "x1"},
            {"u1", "v1"},
            {"f1", "ee1"},
            {"d1", "ff1"},
            {"hh1", "k1"},
            {"d1", "t1"},
            {"aa1", "n1"},
            {"jj1", "x1"},
            {"k1", "cc1"},
            {"ee1", "aa1"},
            {"z1", "g1"}
        };
    }

    // Marking the method as const
    bool checkRelationship(const std::string& from, const std::string& to) const {
        for (const auto& rel : relationships) {
            if (rel.from == from && rel.to == to) {
                return true;
            }
        }
        return false;
    }
};

// Define a simple test function
void testRelationship(const GreatRelations& gr, const std::string& from, const std::string& to, bool expected) {
    bool result = gr.checkRelationship(from, to);
    if (result == expected) {
        std::cout << "Test passed for: great(" << from << ", " << to << ")" << std::endl;
    } else {
        std::cout << "Test failed for: great(" << from << ", " << to << ")" << std::endl;
    }
}

int main() {
    GreatRelations gr;

    // Run tests
    testRelationship(gr, "i1", "x1", true);
    testRelationship(gr, "cc1", "dd1", true);
    // This should succeed as it correctly identifies a non-existing relationship
    testRelationship(gr, "i1", "dd1", false);

    return 0;
}