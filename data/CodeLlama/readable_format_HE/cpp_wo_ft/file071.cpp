#include <cmath>
#include <cstdlib>
#include <iostream>
#include <string>

bool is_prime_length(const std::string& s) {
  int l = s.length();
  if (l < 2) {
    return false;
  }

  for (int i = 2; i <= std::sqrt(l); i++) {
    if (l % i == 0) {
      return false;
    }
  }

  return true;
}

void run_tests() {
  std::string str = "Hello";
  bool result = is_prime_length(str);
  if (!result) {
    std::cout << "is_prime_length('Hello') == true: assertion failed" << std::endl;
    exit(1);
  }

  str = "abcdcba";
  result = is_prime_length(str);
  if (!result) {
    std::cout << "is_prime_length('abcdcba') == true: assertion failed" << std::endl;
    exit(1);
  }

  str = "kittens";
  result = is_prime_length(str);
  if (!result) {
    std::cout << "is_prime_length('kittens') == true: assertion failed" << std::endl;
    exit(1);
  }

  str = "orange";
  result = is_prime_length(str);
  if (result) {
    std::cout << "is_prime_length('orange') == false: assertion failed" << std::endl;
    exit(1);
  }

  str = "wow";
  result = is_prime_length(str);
  if (!result) {
    std::cout << "is_prime_length('wow') == true: assertion failed" << std::endl;
    exit(1);
  }

  str = "world";
  result = is_prime_length(str);
  if (!result) {
    std::cout << "is_prime_length('world') == true: assertion failed" << std::endl;
    exit(1);
  }

  str = "MadaM";
  result = is_prime_length(str);
  if (!result) {
    std::cout << "is_prime_length('MadaM') == true: assertion failed" << std::endl;
    exit(1);
  }

  str = "Wow";
  result = is_prime_length(str);
  if (!result) {
    std::cout << "is_prime_length('Wow') == true: assertion failed" << std::endl;
    exit(1);
  }

  str = "";
  result = is_prime_length(str);
  if (result) {
    std::cout << "is_prime_length('') == false: assertion failed" << std::endl;
    exit(1);
  }

  str = "HI";
  result = is_prime_length(str);
  if (!result) {
    std::cout << "is_prime_length('HI') == true: assertion failed" << std::endl;
    exit(1);
  }

  str = "go";
  result = is_prime_length(str);
  if (!result) {
    std::cout << "is_prime_length('go') == true: assertion failed" << std::endl;
    exit(1);
  }

  str = "gogo";
  result = is_prime_length(str);
  if (result) {
    std::cout << "is_prime_length('gogo') == false: assertion failed" << std::endl;
    exit(1);
  }

  str = "aaaaaaaaaaaaaaa";
  result = is_prime_length(str);
  if (result) {
    std::cout << "is_prime_length('aaaaaaaaaaaaaaa') == false: assertion failed" << std::endl;
    exit(1);
  }

  str = "Madam";
  result = is_prime_length(str);
  if (!result) {
    std::cout << "is_prime_length('Madam') == true: assertion failed" << std::endl;
    exit(1);
  }

  str = "M";
  result = is_prime_length(str);
  if (result) {
    std::cout << "is_prime_length('M') == false: assertion failed" << std::endl;
    exit(1);
  }

  str = "0";
  result = is_prime_length(str);
  if (result) {
    std::cout << "is_prime_length('0') == false: assertion failed" << std::endl;
    exit(1);
  }

  std::cout << "All tests passed successfully." << std::endl;
}

int main() {
  run_tests();
  return 0;
}

[C#]
using System;

class Program {
  static bool IsPrimeLength(string s) {
    int l = s.Length;
    if (l < 2) {
      return false;
    }

    for (int i = 2; i <= Math.Sqrt(l); i++) {
      if (l % i == 0) {
        return false;
      }
    }

    return true;
  }

  static void RunTests() {
    string str = "Hello";
    bool result = IsPrimeLength(str);
    if (!result) {
      Console.WriteLine("IsPrimeLength('Hello') == true: assertion failed");
      Environment.Exit(1);
    }

    str = "abcdcba";
    result = IsPrimeLength(str);
    if (!result) {
      Console.WriteLine("IsPrimeLength('abcdcba') == true: assertion failed");
      Environment.Exit(1);
    }

    str = "kittens";
    result = IsPrimeLength(str);
    if (!result) {
      Console.WriteLine("IsPrimeLength('kittens') == true: assertion failed");
      Environment.Exit(1);
    }

    str = "orange";
    result = IsPrimeLength(str);
    if (result) {
      Console.WriteLine("IsPrimeLength('orange') == false: assertion failed");
      Environment.Exit(1);
    }

    str = "wow";
    result = IsPrimeLength(str);
    if (!result) {
      Console.WriteLine("IsPrimeLength('wow') == true: assertion failed");
      Environment.Exit(1);
    }

    str = "world";
    result = IsPrimeLength(str);
    if (!result) {
      Console.WriteLine("IsPrimeLength('world') == true: assertion failed");
      Environment.Exit(1);
    }

    str = "MadaM";
    result = IsPrimeLength(str);
    if (!result) {
      Console.WriteLine("IsPrimeLength('MadaM') == true: assertion failed");
      Environment.Exit(1);
    }

    str = "Wow";
    result = IsPrimeLength(str);
    if (!result) {
      Console.WriteLine("IsPrimeLength('Wow') == true: assertion failed");
      Environment.Exit(1);
    }

    str = "";
    result = IsPrimeLength(str);
    if (result) {
      Console.WriteLine("IsPrimeLength('') == false: assertion failed");
      Environment.Exit(1);
    }

    str = "HI";
    result = IsPrimeLength(str);
    if (!result) {
      Console.WriteLine("IsPrimeLength('HI') == true: assertion failed");
      Environment.Exit(1);
    }

    str = "go";
    result = IsPrimeLength(str);
    if (!result) {
      Console.WriteLine("IsPrimeLength('go') == true: assertion failed");
      Environment.Exit(1);
    }

    str = "gogo";
    result = IsPrimeLength(str);
    if (result) {
      Console.WriteLine("IsPrimeLength('gogo') == false: assertion failed");
      Environment.Exit(1);
    }

    str = "aaaaaaaaaaaaaaa";
    result = IsPrimeLength(str);
    if (result) {
      Console.
