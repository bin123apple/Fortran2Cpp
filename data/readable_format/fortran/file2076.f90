program factorial
    implicit none
    integer :: num, result

    print *, "Enter a number:"
    read *, num

    result = fact(num)

    print *, "The factorial of ", num, " is ", result

contains

    function fact(n) result(f)
        integer, intent(in) :: n
        integer :: f

        if (n <= 1) then
            f = 1
        else
            f = n * fact(n - 1)
        endif
    end function fact

end program factorial