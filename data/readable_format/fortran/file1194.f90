program main
    implicit none
    integer :: res

    ! Test the factorial function
    res = factorial(6)
    print *, "Factorial of 6 is:", res
    if (res == 720) then
        print *, "Test passed."
    else
        print *, "Test failed."
    end if

contains

    recursive function factorial(n) result(res)
        integer, intent(in) :: n
        integer :: res
        if (n < 1) then
            res = 1
        else
            res = n * factorial(n - 1)
        end if
    end function factorial

end program main