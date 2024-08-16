#include <iostream>
#include <string>

int vowels_count(std::string s) {
    int count = 0;
    std::string vowels = "aeiouAEIOU";
    for (int i = 0; i < s.length(); i++) {
        if (vowels.find(s[i]) != std::string::npos) {
            count++;
        }
    }
    if (s[s.length() - 1] == 'y' || s[s.length() - 1] == 'Y') {
        count++;
    }
    return count;
}

int main() {
    std::string s = "abcde";
    int count = vowels_count(s);
    if (count != 2) {
        std::cout << "Assertion failed for 'abcde'" << std::endl;
        return 1;
    }

    s = "Alone";
    count = vowels_count(s);
    if (count != 3) {
        std::cout << "Assertion failed for 'Alone'" << std::endl;
        return 1;
    }

    s = "key";
    count = vowels_count(s);
    if (count != 2) {
        std::cout << "Assertion failed for 'key'" << std::endl;
        return 1;
    }

    s = "bye";
    count = vowels_count(s);
    if (count != 1) {
        std::cout << "Assertion failed for 'bye'" << std::endl;
        return 1;
    }

    s = "keY";
    count = vowels_count(s);
    if (count != 2) {
        std::cout << "Assertion failed for 'keY'" << std::endl;
        return 1;
    }

    s = "bYe";
    count = vowels_count(s);
    if (count != 1) {
        std::cout << "Assertion failed for 'bYe'" << std::endl;
        return 1;
    }

    s = "ACEDY";
    count = vowels_count(s);
    if (count != 3) {
        std::cout << "Assertion failed for 'ACEDY'" << std::endl;
        return 1;
    }

    std::cout << "All tests passed successfully." << std::endl;
    return 0;
}
```

### 2.1.2. í¨ì í¸ì¶

```
[Fortran]
program main
    implicit none
    integer :: i

    i = 10
    call print_i(i)

contains

    subroutine print_i(i)
        implicit none
        integer, intent(in) :: i

        write(*,*) i
    end subroutine print_i

end program main

[C++]
#include <iostream>

void print_i(int i) {
    std::cout << i << std::endl;
}

int main() {
    int i = 10;
    print_i(i);
    return 0;
}
```

### 2.1.3. í¨ì í¸ì¶ ë° ë°í

```
[Fortran]
program main
    implicit none
    integer :: i

    i = 10
    i = add_i(i, 20)
    call print_i(i)

contains

    function add_i(i, j) result(sum)
        implicit none
        integer, intent(in) :: i, j
        integer :: sum

        sum = i + j
    end function add_i

    subroutine print_i(i)
        implicit none
        integer, intent(in) :: i

        write(*,*) i
    end subroutine print_i

end program main

[C++]
#include <iostream>

int add_i(int i, int j) {
    return i + j;
}

void print_i(int i) {
    std::cout << i << std::endl;
}

int main() {
    int i = 10;
    i = add_i(i, 20);
    print_i(i);
    return 0;
}
```

### 2.1.4. í¨ì í¸ì¶ ë° ë°í 2

```
[Fortran]
program main
    implicit none
    integer :: i

    i = 10
    i = add_i(i, 20)
    call print_i(i)

contains

    function add_i(i, j) result(sum)
        implicit none
        integer, intent(in) :: i, j
        integer :: sum

        sum = i + j
    end function add_i

    subroutine print_i(i)
        implicit none
        integer, intent(in) :: i

        write(*,*) i
    end subroutine print_i

end program main

[C++]
#include <iostream>

int add_i(int i, int j) {
    return i + j;
}

void print_i(int i) {
    std::cout << i << std::endl;
}

int main() {
    int i = 10;
    i = add_i(i, 20);
    print_i(i);
    return 0;
}
```

### 2.1.5. í¨ì í¸ì¶ ë° ë°í 3

```
[Fortran]
program main
    implicit none
    integer :: i

    i = 10
    i = add_i(i, 20)
    call print_i(i)

contains

    function add_i(i, j) result(sum)
        implicit none
        integer, intent(in) :: i, j
        integer :: sum

        sum = i + j
    end function add_i

    subroutine print_i(i)
        implicit none
        integer, intent(in) :: i

        write(*,*) i
    end subroutine print_i

end program main

[C++]
#include <iostream>

int add_i(int i, int j) {
    return i + j;
}

void print_i(int i) {
    std::cout << i << std::endl;
}

int main() {
    int i = 10;
    i = add_i(i, 20);
    print_i(i);
    return 0;
}
```

### 2.1.6. í¨ì í¸ì¶ ë° ë°í 4

```
[Fortran]
program main
    implicit none
    integer :: i

    i = 10
    i = add_i(i, 20)
    call print_i(i)

contains

    function add_i(i, j) result(sum)
        implicit none
        integer, intent(in) :: i, j
        integer :: sum

        sum = i + j
    end function add_i

    subroutine print_i(i)
        implicit none
        integer, intent(in) :: i

        write(*,*) i
    end subroutine print_i

end program main

[C++]
#include <iostream>

int add_i(int i, int j) {
    return i + j;
}

void print_i(int i) {
    std::cout << i << std::endl;
}

int main() {
    int i = 10;
    i = add_i(i, 20);
    print_i(i);
    return 0;
}
```

### 2.1.7. í¨ì í¸ì¶ ë° ë°í 5

```
[Fortran]
program main
    implicit none
    integer :: i

    i = 10
    i = add_i(
