#include <vector>

void izero(std::vector<int>& ia) {
    for(int& val : ia) {
        val = 0;
    }
}

// Or using std::fill for a more concise implementation
#include <algorithm> // For std::fill
#include <vector>

void izero(std::vector<int>& ia) {
    std::fill(ia.begin(), ia.end(), 0);
}