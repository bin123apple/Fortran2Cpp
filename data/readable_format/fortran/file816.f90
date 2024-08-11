program test_factorial
    implicit none
    integer :: test_values(5) = [1, 2, 3, 4, 5]
    integer :: expected_results(5) = [1, 2, 6, 24, 120]
    integer :: i, computed_result

    ! Test the factorial function
    do i = 1, 5
        computed_result = factorial(test_values(i))
        if (computed_result == expected_results(i)) then
            print *, "Test passed for input", test_values(i)
        else
            print *, "Test failed for input", test_values(i)
            print *, "Expected", expected_results(i), "but got", computed_result
        end if
    end do

contains

    ! Factorial function definition
    function factorial(number) result(result)
        implicit none
        integer, intent(in) :: number
        integer :: result, i

        result = 1
        do i = 1, number
            result = result * i
        end do
    end function factorial

end program test_factorial