#include <cmath>
#include <vector>

// [FUNCTION]
double mean_absolute_deviation(const std::vector<double> &numbers) {
    double sum = 0.0;
    for (double number : numbers) {
        sum += number;
    }
    double avg = sum / numbers.size();

    double msum = 0.0;
    for (double number : numbers) {
        msum += std::abs(number - avg);
    }
    return msum / numbers.size();
}

// [MAIN]
int main() {
    // Test cases
    double result = mean_absolute_deviation({1.0, 2.0, 3.0});
    if (std::abs(result - 2.0/3.0) > 1e-4) {
        std::cout << "Assertion failed for test case 1" << std::endl;
        return 1;
    }

    result = mean_absolute_deviation({1.0, 2.0, 3.0, 4.0});
    if (std::abs(result - 1.0) > 1e-4) {
        std::cout << "Assertion failed for test case 2" << std::endl;
        return 1;
    }

    result = mean_absolute_deviation({1.0, 2.0, 3.0, 4.0, 5.0});
    if (std::abs(result - 6.0/5.0) > 1e-4) {
        std::cout << "Assertion failed for test case 3" << std::endl;
        return 1;
    }

    std::cout << "All test cases passed" << std::endl;
    return 0;
}
[/CPP]

[PY]
def mean_absolute_deviation(numbers):
    sum = 0.0
    for number in numbers:
        sum += number
    avg = sum / len(numbers)

    msum = 0.0
    for number in numbers:
        msum += abs(number - avg)
    return msum / len(numbers)

# Test cases
assert mean_absolute_deviation([1.0, 2.0, 3.0]) == 2.0/3.0
assert mean_absolute_deviation([1.0, 2.0, 3.0, 4.0]) == 1.0
assert mean_absolute_deviation([1.0, 2.0, 3.0, 4.0, 5.0]) == 6.0/5.0
print("All test cases passed")
[/PY]

[JAVA]
import java.util.Arrays;

class MeanAbsoluteDeviation {
    public static double meanAbsoluteDeviation(double[] numbers) {
        double sum = 0.0;
        for (double number : numbers) {
            sum += number;
        }
        double avg = sum / numbers.length;

        double msum = 0.0;
        for (double number : numbers) {
            msum += Math.abs(number - avg);
        }
        return msum / numbers.length;
    }

    public static void main(String[] args) {
        // Test cases
        double result = meanAbsoluteDeviation(new double[] {1.0, 2.0, 3.0});
        if (Math.abs(result - 2.0/3.0) > 1e-4) {
            System.out.println("Assertion failed for test case 1");
            System.exit(1);
        }

        result = meanAbsoluteDeviation(new double[] {1.0, 2.0, 3.0, 4.0});
        if (Math.abs(result - 1.0) > 1e-4) {
            System.out.println("Assertion failed for test case 2");
            System.exit(1);
        }

        result = meanAbsoluteDeviation(new double[] {1.0, 2.0, 3.0, 4.0, 5.0});
        if (Math.abs(result - 6.0/5.0) > 1e-4) {
            System.out.println("Assertion failed for test case 3");
            System.exit(1);
        }

        System.out.println("All test cases passed");
    }
}
[/JAVA]

[JS]
function meanAbsoluteDeviation(numbers) {
    let sum = 0.0;
    for (let number of numbers) {
        sum += number;
    }
    let avg = sum / numbers.length;

    let msum = 0.0;
    for (let number of numbers) {
        msum += Math.abs(number - avg);
    }
    return msum / numbers.length;
}

// Test cases
console.assert(meanAbsoluteDeviation([1.0, 2.0, 3.0]) == 2.0/3.0);
console.assert(meanAbsoluteDeviation([1.0, 2.0, 3.0, 4.0]) == 1.0);
console.assert(meanAbsoluteDeviation([1.0, 2.0, 3.0, 4.0, 5.0]) == 6.0/5.0);
console.log("All test cases passed");
[/JS]

[GO]
package main

import (
    "fmt"
    "math"
)

func meanAbsoluteDeviation(numbers []float64) float64 {
    sum := 0.0
    for _, number := range numbers {
        sum += number
    }
    avg := sum / float64(len(numbers))

    msum := 0.0
    for _, number := range numbers {
        msum += math.Abs(number - avg)
    }
    return msum / float64(len(numbers))
}

func main() {
    // Test cases
    result := meanAbsoluteDeviation([]float64{1.0, 2.0, 3.0})
    if math.Abs(result-2.0/3.0) > 1e-4 {
        fmt.Println("Assertion failed for test case 1")
        os.Exit(1)
    }

    result = meanAbsoluteDeviation([]float64{1.0, 2.0, 3.0, 4.0})
    if math.Abs(result-1.0) > 1e-4 {
        fmt.Println("Assertion failed for test case 2")
        os.Exit(1)
    }

    result = meanAbsoluteDeviation([]float64{1.0, 2.0, 3.0, 4.0, 5.0})
    if math.Abs(result-6.0/5.0) > 1e-4 {
        fmt.Println("Assertion failed for test case 3")
        os.Exit(1)
    }

    fmt.Println("All test cases passed")
}
[/GO]

[PHP]
function mean_absolute_deviation($numbers) {
    $sum = 0.0;
    foreach ($number in $numbers) {
        $sum += $number;
    }
    $avg = $sum / count($numbers);

    $msum = 0.0;
    foreach ($number in $numbers) {
        $msum += abs($number - $avg);
    }
    return $msum / count($numbers);
}

// Test cases
assert(mean_absolute_deviation([1.0, 2.0, 3.0]) == 2.0/3.0);
assert(mean_absolute_deviation([1.0, 2.0, 3.0, 4.0]) == 1.0);
assert(mean_absolute_deviation([1.0, 2.0, 3.0, 4.0, 5.0]) == 6.0/5.0);
echo "All test cases passed";
[/PHP]

[RUBY]
def mean_absolute_deviation(numbers)
    sum = 0.0
    numbers.each do |number|
        sum += number
