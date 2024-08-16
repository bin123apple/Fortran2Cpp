#include <cmath>
#include <cstdlib>
#include <iostream>

bool is_prime(int n) {
  if (n < 2) {
    return false;
  }

  for (int i = 2; i <= std::sqrt(n); i++) {
    if (n % i == 0) {
      return false;
    }
  }

  return true;
}

int main() {
  if (!is_prime(6)) {
    std::cout << "Assertion failed: is_prime(6) == false" << std::endl;
    std::exit(1);
  }

  if (!is_prime(101)) {
    std::cout << "Assertion failed: is_prime(101) == true" << std::endl;
    std::exit(1);
  }

  if (!is_prime(11)) {
    std::cout << "Assertion failed: is_prime(11) == true" << std::endl;
    std::exit(1);
  }

  if (!is_prime(13441)) {
    std::cout << "Assertion failed: is_prime(13441) == true" << std::endl;
    std::exit(1);
  }

  if (!is_prime(61)) {
    std::cout << "Assertion failed: is_prime(61) == true" << std::endl;
    std::exit(1);
  }

  if (!is_prime(4)) {
    std::cout << "Assertion failed: is_prime(4) == false" << std::endl;
    std::exit(1);
  }

  if (!is_prime(1)) {
    std::cout << "Assertion failed: is_prime(1) == false" << std::endl;
    std::exit(1);
  }

  if (!is_prime(5)) {
    std::cout << "Assertion failed: is_prime(5) == true" << std::endl;
    std::exit(1);
  }

  if (!is_prime(11)) {
    std::cout << "Assertion failed: is_prime(11) == true" << std::endl;
    std::exit(1);
  }

  if (!is_prime(17)) {
    std::cout << "Assertion failed: is_prime(17) == true" << std::endl;
    std::exit(1);
  }

  if (!is_prime(5 * 17)) {
    std::cout << "Assertion failed: is_prime(5 * 17) == false" << std::endl;
    std::exit(1);
  }

  if (!is_prime(11 * 7)) {
    std::cout << "Assertion failed: is_prime(11 * 7) == false" << std::endl;
    std::exit(1);
  }

  if (!is_prime(13441 * 19)) {
    std::cout << "Assertion failed: is_prime(13441 * 19) == false" << std::endl;
    std::exit(1);
  }

  std::cout << "All assertions passed." << std::endl;
}
[/SOLUTION]

[CHECK]

[/CHECK]

[META]
name = Prime Check
function = is_prime
[/META]

[/PROBLEM]

[PROBLEM]

[DESCRIPTION]

[/DESCRIPTION]

[INPUT]

[/INPUT]

[OUTPUT]

[/OUTPUT]

[SOLUTION]

[/SOLUTION]

[/PROBLEM]

[PROBLEM]

[DESCRIPTION]

[/DESCRIPTION]

[INPUT]

[/INPUT]

[OUTPUT]

[/OUTPUT]

[SOLUTION]

[/SOLUTION]

[/PROBLEM]

[PROBLEM]

[DESCRIPTION]

[/DESCRIPTION]

[INPUT]

[/INPUT]

[OUTPUT]

[/OUTPUT]

[SOLUTION]

[/SOLUTION]

[/PROBLEM]

[PROBLEM]

[DESCRIPTION]

[/DESCRIPTION]

[INPUT]

[/INPUT]

[OUTPUT]

[/OUTPUT]

[SOLUTION]

[/SOLUTION]

[/PROBLEM]

[PROBLEM]

[DESCRIPTION]

[/DESCRIPTION]

[INPUT]

[/INPUT]

[OUTPUT]

[/OUTPUT]

[SOLUTION]

[/SOLUTION]

[/PROBLEM]

[PROBLEM]

[DESCRIPTION]

[/DESCRIPTION]

[INPUT]

[/INPUT]

[OUTPUT]

[/OUTPUT]

[SOLUTION]

[/SOLUTION]

[/PROBLEM]

[PROBLEM]

[DESCRIPTION]

[/DESCRIPTION]

[INPUT]

[/INPUT]

[OUTPUT]

[/OUTPUT]

[SOLUTION]

[/SOLUTION]

[/PROBLEM]

[PROBLEM]

[DESCRIPTION]

[/DESCRIPTION]

[INPUT]

[/INPUT]

[OUTPUT]

[/OUTPUT]

[SOLUTION]

[/SOLUTION]

[/PROBLEM]

[PROBLEM]

[DESCRIPTION]

[/DESCRIPTION]

[INPUT]

[/INPUT]

[OUTPUT]

[/OUTPUT]

[SOLUTION]

[/SOLUTION]

[/PROBLEM]

[PROBLEM]

[DESCRIPTION]

[/DESCRIPTION]

[INPUT]

[/INPUT]

[OUTPUT]

[/OUTPUT]

[SOLUTION]

[/SOLUTION]

[/PROBLEM]

[PROBLEM]

[DESCRIPTION]

[/DESCRIPTION]

[INPUT]

[/INPUT]

[OUTPUT]

[/OUTPUT]

[SOLUTION]

[/SOLUTION]

[/PROBLEM]

[PROBLEM]

[DESCRIPTION]

[/DESCRIPTION]

[INPUT]

[/INPUT]

[OUTPUT]

[/OUTPUT]

[SOLUTION]

[/SOLUTION]

[/PROBLEM]

[PROBLEM]

[DESCRIPTION]

[/DESCRIPTION]

[INPUT]

[/INPUT]

[OUTPUT]

[/OUTPUT]

[SOLUTION]

[/SOLUTION]

[/PROBLEM]

[PROBLEM]

[DESCRIPTION]

[/DESCRIPTION]

[INPUT]

[/INPUT]

[OUTPUT]

[/OUTPUT]

[SOLUTION]

[/SOLUTION]

[/PROBLEM]

[PROBLEM]

[DESCRIPTION]

[/DESCRIPTION]

[INPUT]

[/INPUT]

[OUTPUT]

[/OUTPUT]

[SOLUTION]

[/SOLUTION]

[/PROBLEM]

[PROBLEM]

[DESCRIPTION]

[/DESCRIPTION]

[
