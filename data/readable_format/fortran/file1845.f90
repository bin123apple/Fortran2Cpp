! single_file_factorial.f90
program TestFactorial
    implicit none
    integer :: input, output

    ! Asking for user input
    print *, "Enter a number to compute its factorial:"
    read *, input

    ! Computing the factorial
    output = factorial(input)

    ! Displaying the result
    print *, "Factorial of", input, "is", output

contains

    function factorial(n) result(fact)
        integer, intent(in) :: n
        integer :: fact, i

        fact = 1
        do i = 1, n
            fact = fact * i
        end do
    end function factorial

end program TestFactorial