#include <vector>

// Assuming DATA_TYPE is a placeholder for some type, e.g., double.
// You should replace it with the actual data type you're using.
using DATA_TYPE = double;

void init_array(int maxgrid, std::vector<std::vector<DATA_TYPE>>& sumTang, std::vector<std::vector<DATA_TYPE>>& mean, std::vector<std::vector<DATA_TYPE>>& path) {
    // Resize the vectors to match the dimensions of the Fortran arrays
    sumTang.resize(maxgrid, std::vector<DATA_TYPE>(maxgrid));
    mean.resize(maxgrid, std::vector<DATA_TYPE>(maxgrid));
    path.resize(maxgrid, std::vector<DATA_TYPE>(maxgrid));

    for (int i = 0; i < maxgrid; ++i) {
        for (int j = 0; j < maxgrid; ++j) {
            sumTang[j][i] = (i + 1) * (j + 1); // Adjusted for 0-based indexing
            mean[j][i] = (i - j) / static_cast<DATA_TYPE>(maxgrid);
            path[j][i] = ((i - 1) * (j - 2)) / static_cast<DATA_TYPE>(maxgrid); // Adjusted for 0-based indexing
        }
    }
}
