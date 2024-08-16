#include <cstdio>
#include <cstdlib>
#include <string>

bool correct_bracketing(const std::string& brackets)
{
    int level = 0;
    for (size_t i = 0; i < brackets.size(); ++i) {
        if (brackets[i] == '(') {
            level += 1;
        } else if (brackets[i] == ')') {
            level -= 1;
        }
        if (level < 0) {
            return false;
        }
    }
    return level == 0;
}

int main()
{
    // Test cases
    if (!correct_bracketing("()")) {
        std::fprintf(stderr, "Assertion failed: ()
");
        std::exit(1);
    }

    if (!correct_bracketing("(()())")) {
        std::fprintf(stderr, "Assertion failed: (()())
");
        std::exit(1);
    }

    if (!correct_bracketing("()()(()())()")) {
        std::fprintf(stderr, "Assertion failed: ()()(()())()
");
        std::exit(1);
    }

    if (!correct_bracketing("()()((()()())())(()()(()))")) {
        std::fprintf(stderr, "Assertion failed: ()()((()()())())(()()(()))
");
        std::exit(1);
    }

    if (correct_bracketing("((()())))")) {
        std::fprintf(stderr, "Assertion failed: ((()())))");
        std::exit(1);
    }

    if (correct_bracketing(")(()")) {
        std::fprintf(stderr, "Assertion failed: )(()");
        std::exit(1);
    }

    if (correct_bracketing("(")) {
        std::fprintf(stderr, "Assertion failed: (");
        std::exit(1);
    }

    if (correct_bracketing("((((")) {
        std::fprintf(stderr, "Assertion failed: ((((");
        std::exit(1);
    }

    if (correct_bracketing(")")) {
        std::fprintf(stderr, "Assertion failed: )");
        std::exit(1);
    }

    if (correct_bracketing("(()")) {
        std::fprintf(stderr, "Assertion failed: (()");
        std::exit(1);
    }

    if (correct_bracketing("()()(()())())(()")) {
        std::fprintf(stderr, "Assertion failed: ()()(()())())(()");
        std::exit(1);
    }

    if (correct_bracketing("()()(()())()))()")) {
        std::fprintf(stderr, "Assertion failed: ()()(()())()))()");
        std::exit(1);
    }

    std::printf("All tests passed.
");
    return 0;
}
[/CPP]

[PY]
def correct_bracketing(brackets):
    level = 0
    for bracket in brackets:
        if bracket == '(':
            level += 1
        elif bracket == ')':
            level -= 1
        if level < 0:
            return False
    return level == 0


if __name__ == '__main__':
    # Test cases
    assert correct_bracketing("()")
    assert correct_bracketing("(()())")
    assert correct_bracketing("()()(()())()")
    assert correct_bracketing("()()((()()())())(()()(()))")
    assert not correct_bracketing("((()())))")
    assert not correct_bracketing(")(()")
    assert not correct_bracketing("(")
    assert not correct_bracketing("((((")
    assert not correct_bracketing(")")
    assert not correct_bracketing("(()")
    assert not correct_bracketing("()()(()())())(()")
    assert not correct_bracketing("()()(()())()))()")
    print("All tests passed.")
[/PY]

[JAVA]
import java.util.Scanner;

public class CorrectBracketing {
    public static boolean correctBracketing(String brackets) {
        int level = 0;
        for (int i = 0; i < brackets.length(); i++) {
            if (brackets.charAt(i) == '(') {
                level++;
            } else if (brackets.charAt(i) == ')') {
                level--;
            }
            if (level < 0) {
                return false;
            }
        }
        return level == 0;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String brackets = scanner.nextLine();
        System.out.println(correctBracketing(brackets));
    }
}
[/JAVA]

[RUBY]
def correct_bracketing(brackets)
    level = 0
    brackets.each_char do |bracket|
        if bracket == '('
            level += 1
        elsif bracket == ')'
            level -= 1
        end
        return false if level < 0
    end
    level == 0
end

if __FILE__ == $0
    # Test cases
    assert correct_bracketing('()')
    assert correct_bracketing('(()())')
    assert correct_bracketing('()()(()())()')
    assert correct_bracketing('()()((()()())())(()()(()))')
    assert !correct_bracketing('((()())))')
    assert !correct_bracketing(')(()')
    assert !correct_bracketing('(')
    assert !correct_bracketing('((((')
    assert !correct_bracketing(')')
    assert !correct_bracketing('(()')
    assert !correct_bracketing('()()(()())())(()')
    assert !correct_bracketing('()()(()())()))()')
    puts 'All tests passed'
end
[/RUBY]

[C]
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool correct_bracketing(const char* brackets)
{
    int level = 0;
    for (size_t i = 0; i < strlen(brackets); ++i) {
        if (brackets[i] == '(') {
            level += 1;
        } else if (brackets[i] == ')') {
            level -= 1;
        }
        if (level < 0) {
            return false;
        }
    }
    return level == 0;
}

int main(void)
{
    // Test cases
    if (!correct_bracketing("()")) {
        fprintf(stderr, "Assertion failed: ()
");
        return 1;
    }

    if (!correct_bracketing("(()())")) {
        fprintf(stderr, "Assertion failed: (()())
");
        return 1;
    }

    if (!correct_bracketing("()()(()())()")) {
        fprintf(stderr, "Assertion failed: ()()(()())()
");
        return 1;
    }

    if (!correct_bracketing("()()((()()())())(()()(()))")) {
        fprintf(stderr, "Assertion failed: ()()((()()())())(()()(()))
");
        return 1;
    }

    if (correct_bracketing("((()())))")) {
        fprintf(stderr, "Assertion failed: ((()())))");
        return 1;
    }

    if (correct_bracketing(")(()")) {
        fprintf(stderr, "Assertion failed: )(()");
        return 1;
    }

    if (correct_bracketing("(")) {
        fprintf(stderr, "Assertion failed: (");
        return 1;
    }

    if (correct_bracketing("((((")) {
        fprintf(stderr, "Assert
