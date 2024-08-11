program ExampleProgram
    implicit none
    integer :: result, n

    ! Ask for a number
    print *, 'Enter a number:'
    read *, n

    ! Call the factorial subroutine
    call calculateFactorial(n, result)

    ! Print the result
    print *, 'Factorial of ', n, ' is ', result

contains

    subroutine calculateFactorial(n, result)
        integer, intent(in) :: n
        integer, intent(out) :: result
        integer :: i

        result = 1
        do i = 2, n
            result = result * i
        end do
    end subroutine calculateFactorial

end program ExampleProgram