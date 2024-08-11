#include <iostream>
#include <vector>
#include <cassert>

class SfrDiversionType {
public:
    int id;
    float flowRate;

    SfrDiversionType(int id, float flowRate) : id(id), flowRate(flowRate) {}
};

class SfrDiversionModule {
public:
    static void addDiversion(std::vector<SfrDiversionType>& list, int id, float flowRate) {
        SfrDiversionType newDiversion(id, flowRate);
        list.push_back(newDiversion);
    }

    // Use a pointer to indicate presence or absence of the diversion (nullptr if not found)
    static SfrDiversionType* findDiversionById(std::vector<SfrDiversionType>& list, int id) {
        for (auto& diversion : list) {
            if (diversion.id == id) {
                return &diversion;
            }
        }
        return nullptr; // Return nullptr if not found
    }
};

void testSfrDiversionModule() {
    std::vector<SfrDiversionType> diversionList;

    // Test adding diversions
    SfrDiversionModule::addDiversion(diversionList, 1, 100.0f);
    SfrDiversionModule::addDiversion(diversionList, 2, 200.0f);
    assert(diversionList.size() == 2);

    // Test searching for a specific diversion by ID
    SfrDiversionType* found = SfrDiversionModule::findDiversionById(diversionList, 1);
    assert(found != nullptr && found->id == 1 && found->flowRate == 100.0f);

    // Additional assert to ensure the test for a non-existent ID
    found = SfrDiversionModule::findDiversionById(diversionList, 3);
    assert(found == nullptr);

    std::cout << "All tests passed successfully." << std::endl;
}

int main() {
    testSfrDiversionModule();
    return 0;
}