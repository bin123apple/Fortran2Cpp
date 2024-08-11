#include <iostream>
#include <vector>

class NeutrinoInfoStorage {
private:
    struct NeutrinoInfo {
        bool flagOK = false;
        float value = 0.0f;
        float value_rec = 0.0f;
        float value_rec_2 = 0.0f;
    };

    std::vector<NeutrinoInfo> EXP_nuInfo;

public:
    // Constructor is not needed in this case as the vector will be default initialized

    void neutrinoInfoStorage_Init(int NumInitialEvents) {
        EXP_nuInfo.clear(); // Ensures the vector is empty before initialization
        EXP_nuInfo.resize(NumInitialEvents); // Resizes the vector to hold NumInitialEvents elements
        // Initialize each element in the vector
        for (auto& info : EXP_nuInfo) {
            info.flagOK = false;
            info.value = 0.0f;
            info.value_rec = 0.0f;
            info.value_rec_2 = 0.0f;
        }
    }

    void neutrinoInfoStorage_Clear() {
        EXP_nuInfo.clear(); // Clears the vector, effectively deallocating its memory
    }

    // Add a method to check the size of the vector for testing purposes
    size_t size() const {
        return EXP_nuInfo.size();
    }
};

int main() {
    NeutrinoInfoStorage storage;

    storage.neutrinoInfoStorage_Init(5);
    if (storage.size() == 5) {
        std::cout << "Test PASS: NeutrinoInfoStorage initialized with 5 events." << std::endl;
    } else {
        std::cout << "Test FAIL: NeutrinoInfoStorage not correctly initialized." << std::endl;
    }

    storage.neutrinoInfoStorage_Clear();
    if (storage.size() == 0) {
        std::cout << "Test PASS: NeutrinoInfoStorage cleared correctly." << std::endl;
    } else {
        std::cout << "Test FAIL: NeutrinoInfoStorage not cleared correctly." << std::endl;
    }

    return 0;
}