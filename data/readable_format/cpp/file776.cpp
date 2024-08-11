#include <iostream>
#include <vector>
#include <cassert>

class PpmModuleDataState {
public:
    int ppm_map_type_state;
    int ppm_nrecvlist_state;
    int ppm_nsendlist_state;
    int ppm_nsendbuffer_state;
    int ppm_buffer_set_state;

    std::vector<int> ppm_psendbuffer_state;
    std::vector<int> ppm_buffer2part_state;
    std::vector<int> ppm_irecvlist_state;
    std::vector<int> ppm_isendlist_state;

    // Constructor
    PpmModuleDataState()
        : ppm_map_type_state(0), ppm_nrecvlist_state(0), ppm_nsendlist_state(0),
          ppm_nsendbuffer_state(0), ppm_buffer_set_state(0) {
    }
};

void testInitialization() {
    PpmModuleDataState ppmState;

    assert(ppmState.ppm_map_type_state == 0);
    assert(ppmState.ppm_nrecvlist_state == 0);
    assert(ppmState.ppm_nsendlist_state == 0);
    assert(ppmState.ppm_nsendbuffer_state == 0);
    assert(ppmState.ppm_buffer_set_state == 0);

    std::cout << "Initialization tests passed." << std::endl;
}

void testDynamicArrays() {
    PpmModuleDataState ppmState;

    // Test resizing and adding elements
    ppmState.ppm_psendbuffer_state.push_back(5);
    ppmState.ppm_psendbuffer_state.push_back(10);

    assert(ppmState.ppm_psendbuffer_state.size() == 2);
    assert(ppmState.ppm_psendbuffer_state[0] == 5);
    assert(ppmState.ppm_psendbuffer_state[1] == 10);

    std::cout << "Dynamic arrays tests passed." << std::endl;
}

int main() {
    testInitialization();
    testDynamicArrays();

    std::cout << "All tests passed." << std::endl;

    return 0;
}