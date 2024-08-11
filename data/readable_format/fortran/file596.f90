program factorial
    implicit none
    integer :: n, result

    print *, 'Enter a positive integer'
    read *, n

    result = 1
    do while (n > 1)
        result = result * n
        n = n - 1
    end do

    print *, 'Factorial is: ', result
end program factorial