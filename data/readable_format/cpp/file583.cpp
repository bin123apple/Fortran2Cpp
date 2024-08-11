#include <iostream>
#include <vector>

// Function prototype
void DPOPRemap(std::vector<double>& dst_array,
               const std::vector<std::vector<double>>& map_wts,
               const std::vector<int>& dst_add,
               const std::vector<int>& src_add,
               const std::vector<double>& src_array,
               int ndst, int nlink, int nw, int nsrc, double xmsg);

// Function definition
void DPOPRemap(std::vector<double>& dst_array,
               const std::vector<std::vector<double>>& map_wts,
               const std::vector<int>& dst_add,
               const std::vector<int>& src_add,
               const std::vector<double>& src_array,
               int ndst, int nlink, int nw, int nsrc, double xmsg) {
    // Initialize dst_array with xmsg
    for (int n = 0; n < ndst; ++n) {
        dst_array[n] = xmsg;
    }

    // Remapping loop
    for (int n = 0; n < nlink; ++n) {
        if (src_array[src_add[n] - 1] != xmsg) { // Adjust for 0-based indexing
            if (dst_array[dst_add[n] - 1] == xmsg) { // Adjust for 0-based indexing
                dst_array[dst_add[n] - 1] = src_array[src_add[n] - 1] * map_wts[0][n];
            } else {
                dst_array[dst_add[n] - 1] += src_array[src_add[n] - 1] * map_wts[0][n];
            }
        }
    }
}

// Test function
void testDPOPRemap() {
    int ndst = 5, nlink = 3, nw = 1, nsrc = 5;
    double xmsg = 0.0;
    std::vector<double> dst_array(ndst, xmsg);
    std::vector<std::vector<double>> map_wts = {{0.5, 2.0, 1.0}};
    std::vector<int> dst_add = {1, 3, 4};
    std::vector<int> src_add = {2, 4, 5};
    std::vector<double> src_array = {0.0, 100.0, 0.0, 50.0, 20.0};

    DPOPRemap(dst_array, map_wts, dst_add, src_add, src_array, ndst, nlink, nw, nsrc, xmsg);

    std::cout << "Resulting DST_ARRAY:" << std::endl;
    for (const auto& val : dst_array) {
        std::cout << val << std::endl;
    }
}

// Main function
int main() {
    testDPOPRemap();
    return 0;
}