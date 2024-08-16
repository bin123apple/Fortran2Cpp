#include <iostream>
#include <vector>
#include <algorithm>

bool pairs_sum_to_zero(std::vector<int> &l) {
    for (int i = 0; i < l.size(); i++) {
        for (int j = i + 1; j < l.size(); j++) {
            if (l[i] + l[j] == 0) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    std::vector<int> l = {1, 3, 5, 0};
    if (pairs_sum_to_zero(l)) {
        std::cout << "Test case 1 failed" << std::endl;
        return 1;
    }

    l = {1, 3, -2, 1};
    if (pairs_sum_to_zero(l)) {
        std::cout << "Test case 2 failed" << std::endl;
        return 1;
    }

    l = {1, 2, 3, 7};
    if (pairs_sum_to_zero(l)) {
        std::cout << "Test case 3 failed" << std::endl;
        return 1;
    }

    l = {2, 4, -5, 3, 5, 7};
    if (!pairs_sum_to_zero(l)) {
        std::cout << "Test case 4 failed" << std::endl;
        return 1;
    }

    l = {1};
    if (pairs_sum_to_zero(l)) {
        std::cout << "Test case 5 failed" << std::endl;
        return 1;
    }

    l = {-3, 9, -1, 3, 2, 30};
    if (!pairs_sum_to_zero(l)) {
        std::cout << "Test case 6 failed" << std::endl;
        return 1;
    }

    l = {-3, 9, -1, 3, 2, 31};
    if (!pairs_sum_to_zero(l)) {
        std::cout << "Test case 7 failed" << std::endl;
        return 1;
    }

    l = {-3, 9, -1, 4, 2, 30};
    if (pairs_sum_to_zero(l)) {
        std::cout << "Test case 8 failed" << std::endl;
        return 1;
    }

    l = {-3, 9, -1, 4, 2, 31};
    if (pairs_sum_to_zero(l)) {
        std::cout << "Test case 9 failed" << std::endl;
        return 1;
    }

    std::cout << "All test cases passed" << std::endl;
    return 0;
} [/CPP]

[C]
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool pairs_sum_to_zero(int *l, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (l[i] + l[j] == 0) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    int l[] = {1, 3, 5, 0};
    if (pairs_sum_to_zero(l, sizeof(l) / sizeof(l[0]))) {
        printf("Test case 1 failed
");
        return 1;
    }

    l = (int[]) {1, 3, -2, 1};
    if (pairs_sum_to_zero(l, sizeof(l) / sizeof(l[0]))) {
        printf("Test case 2 failed
");
        return 1;
    }

    l = (int[]) {1, 2, 3, 7};
    if (pairs_sum_to_zero(l, sizeof(l) / sizeof(l[0]))) {
        printf("Test case 3 failed
");
        return 1;
    }

    l = (int[]) {2, 4, -5, 3, 5, 7};
    if (!pairs_sum_to_zero(l, sizeof(l) / sizeof(l[0]))) {
        printf("Test case 4 failed
");
        return 1;
    }

    l = (int[]) {1};
    if (pairs_sum_to_zero(l, sizeof(l) / sizeof(l[0]))) {
        printf("Test case 5 failed
");
        return 1;
    }

    l = (int[]) {-3, 9, -1, 3, 2, 30};
    if (!pairs_sum_to_zero(l, sizeof(l) / sizeof(l[0]))) {
        printf("Test case 6 failed
");
        return 1;
    }

    l = (int[]) {-3, 9, -1, 3, 2, 31};
    if (!pairs_sum_to_zero(l, sizeof(l) / sizeof(l[0]))) {
        printf("Test case 7 failed
");
        return 1;
    }

    l = (int[]) {-3, 9, -1, 4, 2, 30};
    if (pairs_sum_to_zero(l, sizeof(l) / sizeof(l[0]))) {
        printf("Test case 8 failed
");
        return 1;
    }

    l = (int[]) {-3, 9, -1, 4, 2, 31};
    if (pairs_sum_to_zero(l, sizeof(l) / sizeof(l[0]))) {
        printf("Test case 9 failed
");
        return 1;
    }

    printf("All test cases passed
");
    return 0;
} [/C]

[JAVA]
import java.util.Arrays;

public class Main {
    public static void main(String[] args) {
        int[] l = {1, 3, 5, 0};
        if (pairsSumToZero(l)) {
            System.out.println("Test case 1 failed");
            System.exit(1);
        }

        l = new int[] {1, 3, -2, 1};
        if (pairsSumToZero(l)) {
            System.out.println("Test case 2 failed");
            System.exit(1);
        }

        l = new int[] {1, 2, 3, 7};
        if (pairsSumToZero(l)) {
            System.out.println("Test case 3 failed");
            System.exit(1);
        }

        l = new int[] {2, 4, -5, 3, 5, 7};
        if (!pairsSumToZero(l)) {
            System.out.println("Test case 4 failed");
            System.exit(1);
        }

        l = new int[] {1};
        if (pairsSumToZero(l)) {
            System.out.println("Test case 5 failed");
            System.exit(1);
        }

        l = new int[] {-3, 9, -1, 3, 2, 30};
        if (!pairsSumToZero(l)) {
            System.out.println("Test case 6 failed");
            System.exit(1);
        }

        l = new int[] {-3, 9, -1, 3, 2, 31};
        if (!pairsSumToZero(l)) {
            System.out.println("Test case 7 failed");
            System.exit(1);
        }

        l = new int[] {-3, 9, -1, 4, 2, 30};
        if (pairsSumToZero(l)) {
            System.out.println("Test case 8 failed");
            System.exit(1);
        }

        l =
