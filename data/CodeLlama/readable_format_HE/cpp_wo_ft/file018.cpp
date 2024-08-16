#include <cassert>
#include <cstdlib>
#include <cstring>
#include <iostream>

int strlen(const char* str) {
    return strlen(str);
}

int main() {
    // Assertions
    assert(strlen("") == 0);
    assert(strlen("x") == 1);
    assert(strlen("asdasnakj") == 9);

    std::cout << "All assertions passed." << std::endl;
}

[C]
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int strlen(const char* str) {
    return strlen(str);
}

int main() {
    // Assertions
    assert(strlen("") == 0);
    assert(strlen("x") == 1);
    assert(strlen("asdasnakj") == 9);

    printf("All assertions passed.
");
}

[Python]
def strlen(str):
    return len(str)

def run_assertions():
    # Assertions
    assert strlen('') == 0
    assert strlen('x') == 1
    assert strlen('asdasnakj') == 9

    print('All assertions passed.')

run_assertions()

[Ruby]
def strlen(str)
    return str.length
end

def run_assertions
    # Assertions
    assert strlen('') == 0
    assert strlen('x') == 1
    assert strlen('asdasnakj') == 9

    puts 'All assertions passed.'
end

run_assertions

[PHP]
function strlen($str) {
    return strlen($str);
}

function run_assertions() {
    // Assertions
    assert(strlen('') == 0);
    assert(strlen('x') == 1);
    assert(strlen('asdasnakj') == 9);

    echo 'All assertions passed.' . PHP_EOL;
}

run_assertions();

[Swift]
func strlen(_ str: String) -> Int {
    return str.count
}

func run_assertions() {
    // Assertions
    assert(strlen("") == 0)
    assert(strlen("x") == 1)
    assert(strlen("asdasnakj") == 9)

    print("All assertions passed.")
}

run_assertions()

[Java]
public class Main {
    public static void main(String[] args) {
        // Assertions
        assert strlen("").equals(0);
        assert strlen("x").equals(1);
        assert strlen("asdasnakj").equals(9);

        System.out.println("All assertions passed.");
    }

    public static Integer strlen(String str) {
        return str.length();
    }
}

[C#]
using System;

public class Main {
    public static void Main() {
        // Assertions
        assert(strlen("") == 0);
        assert(strlen("x") == 1);
        assert(strlen("asdasnakj") == 9);

        Console.WriteLine("All assertions passed.");
    }

    public static int strlen(string str) {
        return str.Length;
    }
}

[Go]
package main

import "fmt"

func strlen(str string) int {
    return len(str)
}

func run_assertions() {
    // Assertions
    if strlen("") != 0 {
        fmt.Println("Assertion failed: strlen("") == 0")
        os.Exit(1)
    }

    if strlen("x") != 1 {
        fmt.Println("Assertion failed: strlen("x") == 1")
        os.Exit(1)
    }

    if strlen("asdasnakj") != 9 {
        fmt.Println("Assertion failed: strlen("asdasnakj") == 9")
        os.Exit(1)
    }

    fmt.Println("All assertions passed.")
}

func main() {
    run_assertions()
}

[Scala]
object Main {
    def strlen(str: String): Int = str.length

    def run_assertions(): Unit = {
        // Assertions
        assert(strlen("") == 0)
        assert(strlen("x") == 1)
        assert(strlen("asdasnakj") == 9)

        println("All assertions passed.")
    }

    def main(args: Array[String]): Unit = {
        run_assertions()
    }
}

[Kotlin]
fun strlen(str: String): Int = str.length

fun run_assertions() {
    // Assertions
    assert(strlen("") == 0)
    assert(strlen("x") == 1)
    assert(strlen("asdasnakj") == 9)

    println("All assertions passed.")
}

fun main(args: Array<String>) {
    run_assertions()
}

[Rust]
fn strlen(str: &str) -> usize {
    str.len()
}

fn run_assertions() {
    // Assertions
    assert_eq!(strlen(""), 0);
    assert_eq!(strlen("x"), 1);
    assert_eq!(strlen("asdasnakj"), 9);

    println!("All assertions passed.");
}

fn main() {
    run_assertions();
}

[D]
import std.stdio;

int strlen(string str) {
    return str.length;
}

void run_assertions() {
    // Assertions
    assert(strlen("") == 0);
    assert(strlen("x") == 1);
    assert(strlen("asdasnakj") == 9);

    writeln("All assertions passed.");
}

void main() {
    run_assertions();
}

[TypeScript]
function strlen(str: string): number {
    return str.length;
}

function run_assertions() {
    // Assertions
    assert(strlen('') == 0);
    assert(strlen('x') == 1);
    assert(strlen('asdasnakj') == 9);

    console.log('All assertions passed.');
}

run_assertions();

[Clojure]
(defn strlen [str]
  (count str))

(defn run-assertions []
  (let [strlen (fn [str]
                 (count str))]
    ;; Assertions
    (assert (= (strlen "") 0))
    (assert (= (strlen "x") 1))
    (assert (= (strlen "asdasnakj") 9))

    (println "All assertions passed.")))

(defn -main []
  (run-assertions))

[Lua]
function strlen(str)
    return #str
end

function run_assertions()
    -- Assertions
    assert(strlen("") == 0)
    assert(strlen("x") == 1)
    assert(strlen("asdasnakj") == 9)

    print("All assertions passed.")
end

run_assertions()

[Elixir]
defmodule Main do
  def strlen(str) do
    String.length(str)
  end

  def run_assertions do
    # Assertions
    assert strlen("") == 0
    assert strlen("x") == 1
    assert strlen("asdasnakj") == 9

    IO.puts("All assertions passed.")
  end

  def main(_args) do
    run_assertions()
  end
end

[Julia]
function strlen(str::String)
    return length(str)
end

function run_assertions()
    # Assertions
    @assert strlen("") == 0
    @assert strlen("x") == 1
    @assert strlen("asdasnakj") == 9

    println("All assertions passed.")
end
