#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

int main() {
    std::vector<int> a = {1, 2};
    std::vector<std::vector<bool>> lo = {{true}, {true}};
    std::vector<bool> lo2 = {true, true, false}; // Adjusted for size difference.

    // Helper lambda to filter elements by a mask and apply a function.
    auto apply_mask_and_function = [](const std::vector<int>& v, const std::vector<bool>& mask, auto func) {
        std::vector<int> filtered;
        for (size_t i = 0; i < v.size(); ++i) {
            if (i < mask.size() && mask[i]) {
                filtered.push_back(v[i]);
            }
        }
        return func(filtered.begin(), filtered.end());
    };

    // Assuming lo means a vertical mask for the 1D array 'a'.
    // In lo2's case, the excess elements are ignored due to size difference.

    // For minloc and maxloc, we don't have direct equivalents in C++.
    // We could use std::min_element or std::max_element, but these return iterators.
    // For simplicity, let's print the min/max values instead.

    // Min/Max using lo mask
    std::cout << *apply_mask_and_function(a, lo[0], std::min_element) << std::endl;
    std::cout << *apply_mask_and_function(a, lo[0], std::max_element) << std::endl;

    // MinVal/MaxVal, Sum, Product using lo mask
    std::cout << *apply_mask_and_function(a, lo[0], std::min_element) << std::endl;
    std::cout << *apply_mask_and_function(a, lo[0], std::max_element) << std::endl;
    std::cout << std::accumulate(a.begin(), a.end(), 0) << std::endl; // Sum
    std::cout << std::accumulate(a.begin(), a.end(), 1, std::multiplies<int>()) << std::endl; // Product

    // Min/Max using lo2 mask
    std::cout << *apply_mask_and_function(a, lo2, std::min_element) << std::endl;
    std::cout << *apply_mask_and_function(a, lo2, std::max_element) << std::endl;

    // MinVal/MaxVal, Sum, Product using lo2 mask
    std::cout << *apply_mask_and_function(a, lo2, std::min_element) << std::endl;
    std::cout << *apply_mask_and_function(a, lo2, std::max_element) << std::endl;
    std::cout << apply_mask_and_function(a, lo2, [](auto begin, auto end) { return std::accumulate(begin, end, 0); }) << std::endl; // Sum with mask
    std::cout << apply_mask_and_function(a, lo2, [](auto begin, auto end) { return std::accumulate(begin, end, 1, std::multiplies<int>()); }) << std::endl; // Product with mask

    return 0;
}