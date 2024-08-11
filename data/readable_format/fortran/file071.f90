program test_factorial_program
    implicit none

    ! Test case 1: Factorial of 5
    call perform_test(5, 120)

    ! Test case 2: Factorial of 0
    call perform_test(0, 1)

    ! Test case 3: Factorial of 10
    call perform_test(10, 3628800)

contains

    subroutine perform_test(n, expected)
        integer, intent(in) :: n
        integer, intent(in) :: expected
        integer :: result

        result = factorial(n)
        if (result == expected) then
            print *, "Test passed for n = ", n
        else
            print *, "Test failed for n = ", n, " Expected: ", expected, " Got: ", result
        end if
    end subroutine perform_test

    integer function factorial(n)
        integer, intent(in) :: n
        integer :: i

        factorial = 1
        if (n == 0) then
            return
        else
            do i = 1, n
                factorial = factorial * i
            end do
        end if
    end function factorial

end program test_factorial_program