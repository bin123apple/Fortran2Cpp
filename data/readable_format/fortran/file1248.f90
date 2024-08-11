program test_factorial
    implicit none
    integer :: test_values(5) = [0, 1, 2, 3, 5]
    integer :: expected_results(5) = [1, 1, 2, 6, 120]
    integer :: i, result

    do i = 1, 5
        result = factorial(test_values(i))
        if (result == expected_results(i)) then
            print *, "Test passed for n =", test_values(i), ". Result: ", result
        else
            print *, "Test failed for n =", test_values(i), "Expected:", expected_results(i), "Got:", result
        end if
    end do

contains

    function factorial(n) result(res)
        integer, intent(in) :: n
        integer :: res
        if (n <= 1) then
            res = 1
        else
            res = n * factorial(n - 1)
        end if
    end function factorial

end program test_factorial