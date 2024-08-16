#include <cstdlib>
#include <vector>

std::vector<int> f(int n) {
    std::vector<int> out(n);
    int sum = 0, prod = 1;

    for (int i = 0; i < n; i++) {
        sum += i;
        prod *= i;
        if (i % 2 == 0) {
            out[i] = prod;
        } else {
            out[i] = sum;
        }
    }

    return out;
}

bool issame(const std::vector<int>& a, const std::vector<int>& b) {
    if (a.size() != b.size()) {
        return false;
    }

    for (size_t i = 0; i < a.size(); i++) {
        if (a[i] != b[i]) {
            return false;
        }
    }

    return true;
}

int main() {
    std::vector<int> result = f(5);
    std::vector<int> expected1 = {1, 2, 6, 24, 15};
    if (!issame(result, expected1)) {
        std::cerr << "Assertion failed for f(5)" << std::endl;
        exit(1);
    }

    result = f(7);
    std::vector<int> expected2 = {1, 2, 6, 24, 15, 720, 28};
    if (!issame(result, expected2)) {
        std::cerr << "Assertion failed for f(7)" << std::endl;
        exit(1);
    }

    result = f(1);
    std::vector<int> expected3 = {1};
    if (!issame(result, expected3)) {
        std::cerr << "Assertion failed for f(1)" << std::endl;
        exit(1);
    }

    result = f(3);
    std::vector<int> expected4 = {1, 2, 6};
    if (!issame(result, expected4)) {
        std::cerr << "Assertion failed for f(3)" << std::endl;
        exit(1);
    }

    std::cout << "All tests passed" << std::endl;
}
```

### 1.1.2. å£°æ

```
[Fortran]
module utils
    implicit none
    contains

    function f(n) result(out)
        implicit none
        integer, intent(in) :: n
        integer, dimension(:), allocatable :: out
        integer :: i, sum, prod

        allocate(out(n))
        sum = 0
        prod = 1

        do i = 1, n
            sum = sum + i
            prod = prod * i
            if (mod(i, 2) == 0) then
                out(i) = prod
            else
                out(i) = sum
            end if
        end do
    end function f

    logical function issame(a, b)
        implicit none
        integer, dimension(:), intent(in) :: a, b
        integer :: i

        if (size(a) /= size(b)) then
            issame = .false.
            return
        end if

        do i = 1, size(a)
            if (a(i) /= b(i)) then
                issame = .false.
                return
            end if
        end do

        issame = .true.
    end function issame

end module utils

program main
    use utils
    implicit none
    integer, dimension(:), allocatable :: result
    integer, dimension(5) :: expected1 = [1, 2, 6, 24, 15]
    integer, dimension(7) :: expected2 = [1, 2, 6, 24, 15, 720, 28]
    integer, dimension(1) :: expected3 = [1]
    integer, dimension(3) :: expected4 = [1, 2, 6]

    result = f(5)
    if (.not. issame(result, expected1)) then
        write(*,*) "Assertion failed for f(5)"
        call exit(1)
    end if

    result = f(7)
    if (.not. issame(result, expected2)) then
        write(*,*) "Assertion failed for f(7)"
        call exit(1)
    end if

    result = f(1)
    if (.not. issame(result, expected3)) then
        write(*,*) "Assertion failed for f(1)"
        call exit(1)
    end if

    result = f(3)
    if (.not. issame(result, expected4)) then
        write(*,*) "Assertion failed for f(3)"
        call exit(1)
    end if

    write(*,*) "All tests passed"
end program main

[C++]
#include <cstdlib>
#include <vector>

std::vector<int> f(int n) {
    std::vector<int> out(n);
    int sum = 0, prod = 1;

    for (int i = 0; i < n; i++) {
        sum += i;
        prod *= i;
        if (i % 2 == 0) {
            out[i] = prod;
        } else {
            out[i] = sum;
        }
    }

    return out;
}

bool issame(const std::vector<int>& a, const std::vector<int>& b) {
    if (a.size() != b.size()) {
        return false;
    }

    for (size_t i = 0; i < a.size(); i++) {
        if (a[i] != b[i]) {
            return false;
        }
    }

    return true;
}

int main() {
    std::vector<int> result = f(5);
    std::vector<int> expected1 = {1, 2, 6, 24, 15};
    if (!issame(result, expected1)) {
        std::cerr << "Assertion failed for f(5)" << std::endl;
        exit(1);
    }

    result = f(7);
    std::vector<int> expected2 = {1, 2, 6, 24, 15, 720, 28};
    if (!issame(result, expected2)) {
        std::cerr << "Assertion failed for f(7)" << std::endl;
        exit(1);
    }

    result = f(1);
    std::vector<int> expected3 = {1};
    if (!issame(result, expected3)) {
        std::cerr << "Assertion failed for f(1)" << std::endl;
        exit(1);
    }

    result = f(3);
    std::vector<int> expected4 = {1, 2, 6};
    if (!issame(result, expected4)) {
        std::cerr << "Assertion failed for f(3)" << std::endl;
        exit(1);
    }

    std::cout << "All tests passed" << std::endl;
}
```

### 1.1.3. å½æ°

```
[Fortran]
module utils
    implicit none
    contains

    function f(n) result(out)
        implicit none
        integer, intent(in) :: n
        integer, dimension(:), allocatable :: out
        integer :: i, sum, prod

        allocate(out(n))
        sum = 0
        prod = 1

        do i = 1, n
            sum = sum + i
            prod = prod * i
            if (mod(i, 2) == 0) then
                out(i) = prod
            else
                out(i) = sum
            end if
        end do
    end function f

    logical function issame(a, b)
        implicit none
        integer, dimension(:), intent(in) :: a, b
        integer :: i

        if (size(a) /= size(b)) then
            issame = .false.
