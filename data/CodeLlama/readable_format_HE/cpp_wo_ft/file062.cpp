#include <iostream>
#include <vector>

bool will_it_fly(std::vector<int> q, int w)
{
    int sum = 0;
    int n = q.size();

    for (int i = 0; i < n; i++)
    {
        if (q[i] != q[n - 1 - i])
            return false;
        sum += q[i];
    }

    return sum <= w;
}

int main()
{
    std::vector<int> q;
    int w;

    // Test cases
    q = {3, 2, 3};
    w = 9;
    if (!will_it_fly(q, w))
    {
        std::cout << "Test case 1 failed" << std::endl;
        return 1;
    }

    q = {1, 2};
    w = 5;
    if (will_it_fly(q, w))
    {
        std::cout << "Test case 2 failed" << std::endl;
        return 1;
    }

    q = {3};
    w = 5;
    if (!will_it_fly(q, w))
    {
        std::cout << "Test case 3 failed" << std::endl;
        return 1;
    }

    q = {3, 2, 3};
    w = 1;
    if (will_it_fly(q, w))
    {
        std::cout << "Test case 4 failed" << std::endl;
        return 1;
    }

    q = {1, 2, 3};
    w = 6;
    if (will_it_fly(q, w))
    {
        std::cout << "Test case 5 failed" << std::endl;
        return 1;
    }

    q = {5};
    w = 5;
    if (!will_it_fly(q, w))
    {
        std::cout << "Test case 6 failed" << std::endl;
        return 1;
    }

    std::cout << "All test cases passed" << std::endl;
    return 0;
} [/CPP]

[C]
#include <stdio.h>
#include <stdbool.h>

bool will_it_fly(int *q, int w, int n)
{
    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        if (q[i] != q[n - 1 - i])
            return false;
        sum += q[i];
    }

    return sum <= w;
}

int main()
{
    int q[] = {3, 2, 3};
    int w = 9;
    if (!will_it_fly(q, w, 3))
    {
        printf("Test case 1 failed
");
        return 1;
    }

    int q2[] = {1, 2};
    int w2 = 5;
    if (will_it_fly(q2, w2, 2))
    {
        printf("Test case 2 failed
");
        return 1;
    }

    int q3[] = {3};
    int w3 = 5;
    if (!will_it_fly(q3, w3, 1))
    {
        printf("Test case 3 failed
");
        return 1;
    }

    int q4[] = {3, 2, 3};
    int w4 = 1;
    if (will_it_fly(q4, w4, 3))
    {
        printf("Test case 4 failed
");
        return 1;
    }

    int q5[] = {1, 2, 3};
    int w5 = 6;
    if (will_it_fly(q5, w5, 3))
    {
        printf("Test case 5 failed
");
        return 1;
    }

    int q6[] = {5};
    int w6 = 5;
    if (!will_it_fly(q6, w6, 1))
    {
        printf("Test case 6 failed
");
        return 1;
    }

    printf("All test cases passed
");
    return 0;
} [/C]

[JAVA]
import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] q = new int[n];
        for (int i = 0; i < n; i++) {
            q[i] = sc.nextInt();
        }
        int w = sc.nextInt();
        sc.close();

        int sum = 0;
        for (int i = 0; i < n; i++) {
            if (q[i] != q[n - 1 - i]) {
                System.out.println("false");
                return;
            }
            sum += q[i];
        }

        if (sum > w) {
            System.out.println("false");
        } else {
            System.out.println("true");
        }
    }
} [/JAVA]

[PYTHON]
import sys

def will_it_fly(q, w):
    sum = 0
    for i in range(len(q)):
        if q[i] != q[len(q) - 1 - i]:
            return False
        sum += q[i]
    return sum <= w

if __name__ == "__main__":
    q = list(map(int, input().split()))
    w = int(input())
    print(will_it_fly(q, w)) [/PYTHON]

[PHP]
<?php
$q = explode(' ', readline());
$w = (int) readline();

$sum = 0;
for ($i = 0; $i < count($q); $i++) {
    if ($q[$i] != $q[count($q) - 1 - $i]) {
        echo "false";
        exit;
    }
    $sum += $q[$i];
}

if ($sum > $w) {
    echo "false";
} else {
    echo "true";
}
?> [/PHP]

[RUBY]
#!/usr/bin/env ruby

def will_it_fly(q, w)
    sum = 0
    n = q.length
    for i in 0..n-1
        if q[i] != q[n - 1 - i]
            return false
        end
        sum += q[i]
    end
    return sum <= w
end

q = gets.split.map(&:to_i)
w = gets.to_i
puts will_it_fly(q, w) [/RUBY]

[SWIFT]
import Foundation

func willItFly(_ q: [Int], _ w: Int) -> Bool {
    var sum = 0
    for i in 0..<q.count {
        if q[i] != q[q.count - 1 - i] {
            return false
        }
        sum += q[i]
    }
    return sum <= w
}

let q = readLine()!.split(separator: " ").map{ Int(String($0))! }
let w = Int(readLine()!)!
print(willItFly(q, w)) [/SWIFT]

[GO]
package main

import (
    "fmt"
    "strings"
)

func willItFly(q []int, w int) bool {
    sum := 0
    for i := 0; i < len(q); i++ {
        if q[i] != q[len(q)-1-i] {
            return false
        }
        sum += q[i]
    }
    return sum <= w
}

func main() {
    var q []int
    var w int
    fmt.Scan(&q, &w)
    q = strings.Split(q, " ")
    for i := 0; i
