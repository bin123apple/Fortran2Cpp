#include <vector>
#include <cassert>
#include <cmath>
#include <iostream> // Ensure this header is included for std::cout and std::endl

using namespace std;

void offset(float off, float scale, vector<float>& crd) {
    for (int i = 0; i < crd.size(); ++i) {
        crd[i] = scale * crd[i] + off;
    }
}

int main() {
    vector<float> coordinates = {1.0, 2.0, 3.0};
    vector<float> expected = {5.0, 8.0, 11.0}; // Expected results after applying offset and scale
    float off = 2.0;
    float scale = 3.0;

    offset(off, scale, coordinates);

    for (int i = 0; i < coordinates.size(); i++) {
        assert(fabs(coordinates[i] - expected[i]) < 1e-6); // Using floating point comparison
    }

    cout << "All tests passed." << endl;

    return 0;
}