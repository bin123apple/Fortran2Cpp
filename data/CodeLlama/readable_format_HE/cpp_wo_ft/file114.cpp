#include <iostream>
#include <vector>
#include <string>

using namespace std;

int specialFilter(vector<int> nums) {
    int num = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] > 10) {
            string w = to_string(nums[i]);
            if (w[0] % 2 == 1 && w[w.length() - 1] % 2 == 1) {
                num++;
            }
        }
    }
    return num;
}

int specialFilterEmpty() {
    return 0;
}

int main() {
    // Test cases
    int result = specialFilter({5, -2, 1, -5});
    if (result != 0) {
        cout << "Test case 1 failed" << endl;
        return 1;
    }

    result = specialFilter({15, -73, 14, -15});
    if (result != 1) {
        cout << "Test case 2 failed" << endl;
        return 1;
    }

    result = specialFilter({33, -2, -3, 45, 21, 109});
    if (result != 2) {
        cout << "Test case 3 failed" << endl;
        return 1;
    }

    result = specialFilter({43, -12, 93, 125, 121, 109});
    if (result != 4) {
        cout << "Test case 4 failed" << endl;
        return 1;
    }

    result = specialFilter({71, -2, -33, 75, 21, 19});
    if (result != 3) {
        cout << "Test case 5 failed" << endl;
        return 1;
    }

    result = specialFilter({1});
    if (result != 0) {
        cout << "Test case 6 failed" << endl;
        return 1;
    }

    // Handle empty array case separately
    result = specialFilterEmpty();
    if (result != 0) {
        cout << "Test case 7 failed" << endl;
        return 1;
    }

    cout << "All test cases passed" << endl;
    return 0;
}
```

### 2.1.2. æ´æ°æ°ç»ä¸­çæå¤§æ°å­

```
[INST] Translate this Fortran code to C++:

module max_number_module
    implicit none
    contains

    function maxNumber(nums) result(num)
        implicit none
        integer, dimension(:), intent(in) :: nums
        integer :: num
        integer :: i

        num = nums(1)
        do i = 2, size(nums)
            if (nums(i) > num) then
                num = nums(i)
            end if
        end do
    end function maxNumber

    function maxNumberEmpty() result(num)
        implicit none
        integer :: num
        num = 0
    end function maxNumberEmpty

end module max_number_module

program max_number_program
    use max_number_module
    implicit none
    integer :: result

    ! Test cases
    result = maxNumber([1, 2, 3, 4, 5])
    if (result /= 5) then
        write(*,*) "Test case 1 failed"
        call exit(1)
    end if

    result = maxNumber([1, 2, 3, 4, 5, 6, 7, 8, 9, 10])
    if (result /= 10) then
        write(*,*) "Test case 2 failed"
        call exit(1)
    end if

    result = maxNumber([10, 9, 8, 7, 6, 5, 4, 3, 2, 1])
    if (result /= 10) then
        write(*,*) "Test case 3 failed"
        call exit(1)
    end if

    result = maxNumber([10, 10, 10, 10, 10, 10, 10, 10, 10, 10])
    if (result /= 10) then
        write(*,*) "Test case 4 failed"
        call exit(1)
    end if

    result = maxNumber([10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10])
    if (result /= 10) then
        write(*,*) "Test case 5 failed"
        call exit(1)
    end if

    result = maxNumber([10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10])
    if (result /= 10) then
        write(*,*) "Test case 6 failed"
        call exit(1)
    end if

    result = maxNumber([10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10])
    if (result /= 10) then
        write(*,*) "Test case 7 failed"
        call exit(1)
    end if

    result = maxNumber([10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10])
    if (result /= 10) then
        write(*,*) "Test case 8 failed"
        call exit(1)
    end if

    result = maxNumber([10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10])
    if (result /= 10) then
        write(*,*) "Test case 9 failed"
        call exit(1)
    end if

    result = maxNumber([10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10])
    if (result /= 10) then
        write(*,*) "Test case 10 failed"
        call exit(1)
    end if

    result = maxNumber([10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10])
    if (result /= 10) then
        write(*,*) "Test case 11 failed"
        call exit(1)
    end if

    result = maxNumber([10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10])
    if (result /= 10) then
        write(*,*) "Test case 12 failed"
        call exit(1)
    end if

    result = maxNumber([10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10])
    if (result /= 10) then
        write(*,*) "Test case 13 failed"
        call exit(1)
    end if
