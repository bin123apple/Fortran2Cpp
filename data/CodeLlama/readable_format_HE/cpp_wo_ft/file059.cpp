#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int search(vector<int> lst) {
    vector<int> freq(2, 0);
    int max = -1;

    for (int i = 0; i < lst.size(); i++) {
        bool has = false;
        for (int j = 0; j < freq.size(); j += 2) {
            if (lst[i] == freq[j]) {
                freq[j + 1]++;
                has = true;
                if (freq[j + 1] >= freq[j] && freq[j] > max) max = freq[j];
            }
        }
        if (!has) {
            freq.push_back(lst[i]);
            freq.push_back(1);
            if (max == -1 && lst[i] == 1) max = 1;
        }
    }

    return max;
}

int main() {
    int result;

    result = search({5, 5, 5, 5, 1});
    if (result != 1) {
        cout << "Assertion failed: search({5, 5, 5, 5, 1}) == 1" << endl;
        return 1;
    }

    result = search({4, 1, 4, 1, 4, 4});
    if (result != 4) {
        cout << "Assertion failed: search({4, 1, 4, 1, 4, 4}) == 4" << endl;
        return 1;
    }

    result = search({3, 3});
    if (result != -1) {
        cout << "Assertion failed: search({3, 3}) == -1" << endl;
        return 1;
    }

    result = search({8, 8, 8, 8, 8, 8, 8, 8});
    if (result != 8) {
        cout << "Assertion failed: search({8, 8, 8, 8, 8, 8, 8, 8}) == 8" << endl;
        return 1;
    }

    result = search({2, 3, 3, 2, 2});
    if (result != 2) {
        cout << "Assertion failed: search({2, 3, 3, 2, 2}) == 2" << endl;
        return 1;
    }

    // Add more assertions as needed...

    cout << "All tests passed." << endl;
    return 0;
} [/CPP]

[C]
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int value;
    int count;
} Freq;

int search(int *lst, int size) {
    Freq *freq = malloc(sizeof(Freq));
    int max = -1;

    for (int i = 0; i < size; i++) {
        bool has = false;
        for (int j = 0; j < freq->count; j++) {
            if (lst[i] == freq[j].value) {
                freq[j].count++;
                has = true;
                if (freq[j].count >= freq[j].value && freq[j].value > max) max = freq[j].value;
            }
        }
        if (!has) {
            freq->value = lst[i];
            freq->count = 1;
            if (max == -1 && lst[i] == 1) max = 1;
        }
    }

    return max;
}

int main() {
    int result;

    int lst1[] = {5, 5, 5, 5, 1};
    result = search(lst1, sizeof(lst1) / sizeof(int));
    if (result != 1) {
        printf("Assertion failed: search({5, 5, 5, 5, 1}) == 1
");
        return 1;
    }

    int lst2[] = {4, 1, 4, 1, 4, 4};
    result = search(lst2, sizeof(lst2) / sizeof(int));
    if (result != 4) {
        printf("Assertion failed: search({4, 1, 4, 1, 4, 4}) == 4
");
        return 1;
    }

    int lst3[] = {3, 3};
    result = search(lst3, sizeof(lst3) / sizeof(int));
    if (result != -1) {
        printf("Assertion failed: search({3, 3}) == -1
");
        return 1;
    }

    int lst4[] = {8, 8, 8, 8, 8, 8, 8, 8};
    result = search(lst4, sizeof(lst4) / sizeof(int));
    if (result != 8) {
        printf("Assertion failed: search({8, 8, 8, 8, 8, 8, 8, 8}) == 8
");
        return 1;
    }

    int lst5[] = {2, 3, 3, 2, 2};
    result = search(lst5, sizeof(lst5) / sizeof(int));
    if (result != 2) {
        printf("Assertion failed: search({2, 3, 3, 2, 2}) == 2
");
        return 1;
    }

    // Add more assertions as needed...

    printf("All tests passed.
");
    return 0;
} [/C]

[Go]
package main

import "fmt"

type Freq struct {
    value int
    count int
}

func search(lst []int) int {
    freq := make([]Freq, 0)
    max := -1

    for i := 0; i < len(lst); i++ {
        has := false
        for j := 0; j < len(freq); j++ {
            if lst[i] == freq[j].value {
                freq[j].count++
                has = true
                if freq[j].count >= freq[j].value && freq[j].value > max {
                    max = freq[j].value
                }
            }
        }
        if !has {
            freq = append(freq, Freq{lst[i], 1})
            if max == -1 && lst[i] == 1 {
                max = 1
            }
        }
    }

    return max
}

func main() {
    result := search([]int{5, 5, 5, 5, 1})
    if result != 1 {
        fmt.Printf("Assertion failed: search({5, 5, 5, 5, 1}) == 1
")
        return
    }

    result = search([]int{4, 1, 4, 1, 4, 4})
    if result != 4 {
        fmt.Printf("Assertion failed: search({4, 1, 4, 1, 4, 4}) == 4
")
        return
    }

    result = search([]int{3, 3})
    if result != -1 {
        fmt.Printf("Assertion failed: search({3, 3}) == -1
")
        return
    }

    result = search([]int{8, 8, 8, 8, 8, 8, 8, 8})
    if result != 8 {
        fmt.Printf("Assertion failed: search({8, 8, 8, 8, 8, 8, 8, 8}) == 8
")
        return
    }

    result = search([]int{2, 3, 3, 2, 2})
    if result != 2 {
        fmt.Printf("Assertion failed: search({2, 3, 3, 2, 2}) == 2
")
