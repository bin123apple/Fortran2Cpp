#include <vector>

void fixMap(std::vector<int>& map) {
    for (size_t i = 0; i < map.size(); ++i) {
        if (map[i] == 0) map[i] = i + 1; // +1 to match Fortran 1-based indexing
    }
}