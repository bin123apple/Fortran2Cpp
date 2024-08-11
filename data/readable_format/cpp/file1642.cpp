#include <iostream>

class Particle {
public:
    // Constructor
    Particle() {
        // Initialize particle properties here
    }

    // Add necessary particle properties and methods here
};

class ParticleListNode {
public:
    Particle* V; // Pointer to Particle
    ParticleListNode* next; // Pointer to the next node

    // Constructor
    ParticleListNode() : V(nullptr), next(nullptr) {}

    // Destructor to automatically clean up
    ~ParticleListNode() {
        delete V; // Assuming ownership of Particle*
        // No need to delete 'next' as it is handled elsewhere
    }
};

class ParticleList {
public:
    ParticleListNode* first; // Pointer to the first node
    ParticleListNode* last;  // Pointer to the last node
    int nEntries;            // Number of entries in the list

    // Constructor
    ParticleList() : first(nullptr), last(nullptr), nEntries(0) {}

    // Destructor
    ~ParticleList() {
        while (first != nullptr) {
            ParticleListNode* temp = first;
            first = first->next;
            delete temp;
        }
    }

    // Method to add a particle to the list
    void addParticle(Particle* p) {
        ParticleListNode* newNode = new ParticleListNode();
        newNode->V = p;
        if (first == nullptr) {
            first = last = newNode;
        } else {
            last->next = newNode;
            last = newNode;
        }
        nEntries++;
    }
};

int main() {
    ParticleList list;
    Particle* p1 = new Particle();
    Particle* p2 = new Particle();

    list.addParticle(p1);
    list.addParticle(p2);

    std::cout << "Number of entries in the list: " << list.nEntries << std::endl;

    if (list.nEntries == 2) {
        std::cout << "Test passed: 2 particles added." << std::endl;
    } else {
        std::cout << "Test failed." << std::endl;
    }

    // Cleanup is handled by the ParticleList destructor
    return 0;
}