program test_factorial
    implicit none
    integer :: num, result

    ! Example usage
    num = 5
    result = factorial(num)
    print *, "Factorial of", num, "is", result

contains

    function factorial(n) result(fact)
        integer, intent(in) :: n
        integer :: fact, i

        fact = 1
        do i = 1, n
            fact = fact * i
        end do
    end function factorial

end program test_factorial