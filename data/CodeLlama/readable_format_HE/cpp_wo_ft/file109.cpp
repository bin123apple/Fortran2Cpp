#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<int> input_array;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;
        input_array.push_back(value);
    }

    int max_neg = 0;
    int min_pos = 0;
    for (int i = 0; i < n; i++) {
        if (input_array[i] < 0) {
            if (max_neg == 0 || input_array[i] > max_neg) {
                max_neg = input_array[i];
            }
        } else {
            if (min_pos == 0 || input_array[i] < min_pos) {
                min_pos = input_array[i];
            }
        }
    }

    cout << max_neg << " " << min_pos << endl;
    return 0;
}

[CHECK]

#include <cstdio>
#include <algorithm>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

void run_tests() {
    vector<int> input_array;
    int n;
    int max_neg = 0;
    int min_pos = 0;

    // Test case #1
    n = 6;
    input_array = {2, 4, 1, 3, 5, 7};
    max_neg = 0;
    min_pos = 1;
    printf("Test case #1
");
    printf("Expected: %d %d
", max_neg, min_pos);
    printf("Got:      ");
    print_array(input_array);
    printf("
");

    // Test case #2
    n = 7;
    input_array = {2, 4, 1, 3, 5, 7, 0};
    max_neg = 0;
    min_pos = 1;
    printf("Test case #2
");
    printf("Expected: %d %d
", max_neg, min_pos);
    printf("Got:      ");
    print_array(input_array);
    printf("
");

    // Test case #3
    n = 7;
    input_array = {1, 3, 2, 4, 5, 6, -2};
    max_neg = -2;
    min_pos = 1;
    printf("Test case #3
");
    printf("Expected: %d %d
", max_neg, min_pos);
    printf("Got:      ");
    print_array(input_array);
    printf("
");

    // Test case #4
    n = 7;
    input_array = {4, 5, 3, 6, 2, 7, -7};
    max_neg = -7;
    min_pos = 2;
    printf("Test case #4
");
    printf("Expected: %d %d
", max_neg, min_pos);
    printf("Got:      ");
    print_array(input_array);
    printf("
");

    // Test case #5
    n = 8;
    input_array = {7, 3, 8, 4, 9, 2, 5, -9};
    max_neg = -9;
    min_pos = 2;
    printf("Test case #5
");
    printf("Expected: %d %d
", max_neg, min_pos);
    printf("Got:      ");
    print_array(input_array);
    printf("
");

    // Test case #6
    n = 1;
    input_array = {0};
    max_neg = 0;
    min_pos = 0;
    printf("Test case #6
");
    printf("Expected: %d %d
", max_neg, min_pos);
    printf("Got:      ");
    print_array(input_array);
    printf("
");

    // Test case #7
    n = 4;
    input_array = {-1, -3, -5, -6};
    max_neg = -1;
    min_pos = 0;
    printf("Test case #7
");
    printf("Expected: %d %d
", max_neg, min_pos);
    printf("Got:      ");
    print_array(input_array);
    printf("
");

    // Test case #8
    n = 5;
    input_array = {-1, -3, -5, -6, 0};
    max_neg = -1;
    min_pos = 0;
    printf("Test case #8
");
    printf("Expected: %d %d
", max_neg, min_pos);
    printf("Got:      ");
    print_array(input_array);
    printf("
");

    // Test case #9
    n = 5;
    input_array = {-6, -4, -4, -3, 1};
    max_neg = -3;
    min_pos = 1;
    printf("Test case #9
");
    printf("Expected: %d %d
", max_neg, min_pos);
    printf("Got:      ");
    print_array(input_array);
    printf("
");

    // Test case #10
    n = 6;
    input_array = {-6, -4, -4, -3, -100, 1};
    max_neg = -3;
    min_pos = 1;
    printf("Test case #10
");
    printf("Expected: %d %d
", max_neg, min_pos);
    printf("Got:      ");
    print_array(input_array);
    printf("
");

    // Test case #11
    n = 0;
    input_array = {};
    max_neg = 0;
    min_pos = 0;
    printf("Test case #11
");
    printf("Expected: %d %d
", max_neg, min_pos);
    printf("Got:      ");
    print_array(input_array);
    printf("
");
}

void print_array(vector<int> input_array) {
    for (int i = 0; i < input_array.size(); i++) {
        printf("%d ", input_array[i]);
    }
}

int main() {
    run_tests();
    return 0;
}

[CHECK]

#include <cstdio>
#include <algorithm>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

void run_tests() {
    vector<int> input_array;
    int n;
    int max_neg = 0;
    int min_pos = 0;

    // Test case #1
    n = 6;
    input_array = {2, 4, 1, 3, 5, 7};
    max_neg = 0;
    min_pos = 1;
    printf("Test case #1
");
    printf("Expected: %d %d
", max_neg, min_pos);
    printf("Got:      ");
    print_array(input_array);
    printf("
");

    // Test case #2
    n = 7;
    input_array = {2, 4, 1, 3, 5, 7, 0};
    max_neg = 0;
    min_pos = 1;
    printf("Test case #2
");
    printf("Expected: %d %d
", max_neg, min_pos);
    printf("Got:      ");
    print_array(input_array);
    printf("
");

    // Test case #3
    n = 7;
    input_array = {1, 3, 2, 4, 5, 6, -2};
    max_neg = -2;
