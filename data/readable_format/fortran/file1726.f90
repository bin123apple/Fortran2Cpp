program factorialTestProgram
    implicit none
    integer :: result

    call testFactorialCalculation(0, 1)
    call testFactorialCalculation(1, 1)
    call testFactorialCalculation(5, 120)
end program factorialTestProgram

subroutine calculateFactorial(n, result)
    integer, intent(in) :: n
    integer, intent(out) :: result
    result = 1
    do i = 2, n
        result = result * i
    end do
end subroutine calculateFactorial

subroutine testFactorialCalculation(n, expected)
    integer, intent(in) :: n, expected
    integer :: result
    call calculateFactorial(n, result)
    if (result == expected) then
        print *, "Test passed for n =", n
    else
        print *, "Test failed for n =", n, "Expected:", expected, "Got:", result
    endif
end subroutine testFactorialCalculation