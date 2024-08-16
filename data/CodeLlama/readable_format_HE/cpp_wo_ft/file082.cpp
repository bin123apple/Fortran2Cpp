#include <cstdlib>
#include <cstdio>
#include <cmath>

int main() {
    assert(closest_integer("10") == 10, "Assertion failed: closest_integer('10') == 10");
    assert(closest_integer("14.5") == 15, "Assertion failed: closest_integer('14.5') == 15");
    assert(closest_integer("-15.5") == -16, "Assertion failed: closest_integer('-15.5') == -16");
    assert(closest_integer("15.3") == 15, "Assertion failed: closest_integer('15.3') == 15");
    assert(closest_integer("0") == 0, "Assertion failed: closest_integer('0') == 0");
    return 0;
}

int closest_integer(const char* value) {
    double w;
    sscanf(value, "%lf", &w);
    return (int) round(w);
}

void assert(bool condition, const char* message) {
    if (!condition) {
        printf("%s
", message);
        exit(1);
    }
}

[/C++]

[C#]

using System;

class Program
{
    static void Main(string[] args)
    {
        assert(closest_integer("10") == 10, "Assertion failed: closest_integer('10') == 10");
        assert(closest_integer("14.5") == 15, "Assertion failed: closest_integer('14.5') == 15");
        assert(closest_integer("-15.5") == -16, "Assertion failed: closest_integer('-15.5') == -16");
        assert(closest_integer("15.3") == 15, "Assertion failed: closest_integer('15.3') == 15");
        assert(closest_integer("0") == 0, "Assertion failed: closest_integer('0') == 0");
    }

    static int closest_integer(string value)
    {
        double w;
        double.TryParse(value, out w);
        return (int)Math.Round(w);
    }

    static void assert(bool condition, string message)
    {
        if (!condition)
        {
            Console.WriteLine(message);
            Environment.Exit(1);
        }
    }
}

[/C#]

[Java]

public class Main {
    public static void main(String[] args) {
        assert(closest_integer("10") == 10, "Assertion failed: closest_integer('10') == 10");
        assert(closest_integer("14.5") == 15, "Assertion failed: closest_integer('14.5') == 15");
        assert(closest_integer("-15.5") == -16, "Assertion failed: closest_integer('-15.5') == -16");
        assert(closest_integer("15.3") == 15, "Assertion failed: closest_integer('15.3') == 15");
        assert(closest_integer("0") == 0, "Assertion failed: closest_integer('0') == 0");
    }

    static int closest_integer(String value) {
        double w;
        try {
            w = Double.parseDouble(value);
        } catch (NumberFormatException e) {
            return 0;
        }
        return (int) Math.round(w);
    }

    static void assert(boolean condition, String message) {
        if (!condition) {
            System.out.println(message);
            System.exit(1);
        }
    }
}

[/Java]

[Python]

def main():
    assert closest_integer("10") == 10, "Assertion failed: closest_integer('10') == 10"
    assert closest_integer("14.5") == 15, "Assertion failed: closest_integer('14.5') == 15"
    assert closest_integer("-15.5") == -16, "Assertion failed: closest_integer('-15.5') == -16"
    assert closest_integer("15.3") == 15, "Assertion failed: closest_integer('15.3') == 15"
    assert closest_integer("0") == 0, "Assertion failed: closest_integer('0') == 0"

def closest_integer(value):
    return int(round(float(value)))

def assert(condition, message):
    if not condition:
        print(message)
        exit(1)

if __name__ == "__main__":
    main()

[/Python]

[PHP]

<?php

function main() {
    assert(closest_integer("10") == 10, "Assertion failed: closest_integer('10') == 10");
    assert(closest_integer("14.5") == 15, "Assertion failed: closest_integer('14.5') == 15");
    assert(closest_integer("-15.5") == -16, "Assertion failed: closest_integer('-15.5') == -16");
    assert(closest_integer("15.3") == 15, "Assertion failed: closest_integer('15.3') == 15");
    assert(closest_integer("0") == 0, "Assertion failed: closest_integer('0') == 0");
}

function closest_integer($value) {
    return (int) round((float) $value);
}

function assert($condition, $message) {
    if (!$condition) {
        echo $message . PHP_EOL;
        exit(1);
    }
}

main();

[/PHP]

[Ruby]

def main
    assert(closest_integer("10") == 10, "Assertion failed: closest_integer('10') == 10")
    assert(closest_integer("14.5") == 15, "Assertion failed: closest_integer('14.5') == 15")
    assert(closest_integer("-15.5") == -16, "Assertion failed: closest_integer('-15.5') == -16")
    assert(closest_integer("15.3") == 15, "Assertion failed: closest_integer('15.3') == 15")
    assert(closest_integer("0") == 0, "Assertion failed: closest_integer('0') == 0")
end

def closest_integer(value)
    return value.to_f.round
end

def assert(condition, message)
    if !condition
        puts message
        exit(1)
    end
end

main()

[/Ruby]

[Swift]

func main() {
    assert(closest_integer("10") == 10, "Assertion failed: closest_integer('10') == 10")
    assert(closest_integer("14.5") == 15, "Assertion failed: closest_integer('14.5') == 15")
    assert(closest_integer("-15.5") == -16, "Assertion failed: closest_integer('-15.5') == -16")
    assert(closest_integer("15.3") == 15, "Assertion failed: closest_integer('15.3') == 15")
    assert(closest_integer("0") == 0, "Assertion failed: closest_integer('0') == 0")
}

func closest_integer(value: String) -> Int {
    return Int(round(Double(value)!))
}

func assert(_ condition: Bool, _ message: String) {
    if !condition {
        print(message)
        exit(1)
    }
}

main()

[/Swift]

[Go]

package main

import (
    "fmt"
    "math"
    "strconv"
)

func
