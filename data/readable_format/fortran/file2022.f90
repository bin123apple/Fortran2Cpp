! factorial_with_test.f90
module math_operations
    implicit none
contains
    function factorial(n) result(fact)
        integer, intent(in) :: n
        integer :: fact
        integer :: i
        fact = 1
        do i = 2, n
            fact = fact * i
        end do
    end function factorial
end module math_operations

program test_factorial
    use math_operations
    implicit none
    integer :: result

    ! Test the factorial function with a known input and output
    result = factorial(5)
    ! Check if the result is as expected
    if (result == 120) then
        print *, "Fortran Test Passed: Factorial of 5 is 120."
    else
        print *, "Fortran Test Failed."
    end if
end program test_factorial