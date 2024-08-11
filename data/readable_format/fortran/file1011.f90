! factorial_program.f90
program main
    implicit none
    integer :: n, result

    ! Test the factorial function
    n = 5
    result = factorial(n)
    print *, "Factorial of", n, "is", result

    contains

    function factorial(n) result(fact)
        integer, intent(in) :: n
        integer :: fact, i

        fact = 1
        do i = 1, n
            fact = fact * i
        end do
    end function factorial
end program main