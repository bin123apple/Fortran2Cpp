module factorial_module
contains
    recursive function factorial(n) result(fact)
        integer, intent(in) :: n
        integer :: fact
        if (n <= 1) then
            fact = 1
        else
            fact = n * factorial(n-1)
        endif
    end function factorial
end module factorial_module

program test_factorial
    use factorial_module
    implicit none
    integer :: result
    result = factorial(5)
    if (result == 120) then
        print *, "Test passed: 5! = 120"
    else
        print *, "Test failed: 5! is not 120, result is ", result
    endif
end program test_factorial