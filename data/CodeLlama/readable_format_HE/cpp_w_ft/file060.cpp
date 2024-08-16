Translating the provided Fortran code to C++ involves several steps, including adapting the array handling, the sorting algorithm, and the testing framework. Below is a C++ translation of the Fortran code, including unit tests using the Google Test framework.

First, ensure you have Google Test set up in your project. The following C++ code is a direct translation of the Fortran code, including the sorting logic and the unit tests.

```cpp
#include <gtest/gtest.h>
#include <vector>
#include <algorithm>

// Function to sort the list in the strange order
void strange_sort_list(const std::vector<int>& lst, std::vector<int>& out) {
    int n = lst.size();
    if (n == 0) {
        out.clear();
        return;
    }

    std::vector<int> sorted_lst = lst;
    // Bubble sort
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (sorted_lst[j] > sorted_lst[j + 1]) {
                std::swap(sorted_lst[j], sorted_lst[j + 1]);
            }
        }
    }

    out.resize(n);
    int l = 0, r = n - 1;
    for (int i = 0; i < n; ++i) {
        if (i % 2 == 0) {
            out[i] = sorted_lst[l];
            ++l;
        } else {
            out[i] = sorted_lst[r];
            --r;
        }
    }
}

// Function to check if two vectors are the same
bool issame(const std::vector<int>& a, const std::vector<int>& b) {
    if (a.size() != b.size()) {
        return false;
    }

    for (size_t i = 0; i < a.size(); ++i) {
        if (a[i] != b[i]) {
            return false;
        }
    }

    return true;
}

// Unit tests
TEST(StrangeSortTest, HandlesEmptyArray) {
    std::vector<int> out;
    strange_sort_list(std::vector<int>(), out);
    EXPECT_TRUE(out.empty());
}

TEST(StrangeSortTest, HandlesOddSizeArray) {
    std::vector<int> out;
    std::vector<int> lst = {1, 2, 3, 4, 5};
    strange_sort_list(lst, out);
    std::vector<int> expected = {1, 5, 2, 4, 3};
    EXPECT_TRUE(issame(out, expected));
}

TEST(StrangeSortTest, HandlesEvenSizeArray) {
    std::vector<int> out;
    std::vector<int> lst = {5, 6, 7, 8, 9, 1};
    strange_sort_list(lst, out);
    std::vector<int> expected = {1, 9, 5, 8, 6, 7};
    EXPECT_TRUE(issame(out, expected));
}

TEST(StrangeSortTest, HandlesRepeatedElements) {
    std::vector<int> out;
    std::vector<int> lst = {5, 5, 5, 5};
    strange_sort_list(lst, out);
    std::vector<int> expected = {5, 5, 5, 5};
    EXPECT_TRUE(issame(out, expected));
}

TEST(StrangeSortTest, HandlesSingleElement) {
    std::vector<int> out;
    std::vector<int> lst = {111111};
    strange_sort_list(lst, out);
    std::vector<int> expected = {111111};
    EXPECT_TRUE(issame(out, expected));
}

TEST(StrangeSortTest, HandlesMixedElements) {
    std::vector<int> out;
    std::vector<int> lst = {0, 2, 2, 2, 5, 5, -5, -5};
    strange_sort_list(lst, out);
    std::vector<int> expected = {-5, 5, -5, 5, 0, 2, 2, 2};
    EXPECT_TRUE(issame(out, expected));
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
```

This C++ code includes the `strange_sort_list` function, which sorts the input array in a peculiar way, and a series of unit tests to verify the correctness of this sorting function. The unit tests cover various scenarios, including empty arrays, arrays of odd and even lengths, arrays with repeated elements, and arrays with a single element.

To compile and run this code, you'll need to link against the Google Test library. The exact command depends on your setup, but it might look something like this:

```sh
g++ -std=c++11 -o test_strange_sort test_strange_sort.cpp -lgtest -lgtest_main -pthread
./test_strange_sort
```

This command compiles the C++ code into an executable named `test_strange_sort`, linking against the Google Test libraries, and then runs the executable. The output will show the results of the unit tests.
