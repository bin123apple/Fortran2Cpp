#include <iostream>
#include <vector>

const int len_line_opt = 100; // Assuming len_line_opt is defined in 'plt_basic_defn.inc'

void graphic_copy_line_opt(const std::vector<int> &line_style_from, std::vector<int> &line_style_to, int s) {
    if (s != 0) return;

    for (int l = 0; l < len_line_opt; ++l) {
        line_style_to[l] = line_style_from[l];
    }
}

int main() {
    std::vector<int> line_style_from(len_line_opt, 0); // Example initialization
    std::vector<int> line_style_to(len_line_opt, 0);   // Example initialization

    int s = 0; // Example value for 's'

    // Call the function
    graphic_copy_line_opt(line_style_from, line_style_to, s);

    // Output the result for verification
    for (int i = 0; i < len_line_opt; ++i) {
        std::cout << line_style_to[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}