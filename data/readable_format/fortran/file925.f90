program main
    implicit none
    real :: x, result

    ! Example usage of the square function
    x = 2.0
    result = square(x)
    print *, "The square of ", x, " is ", result
    ! Add more calls to square or other functions as needed

contains

    function square(x) result(res)
        real, intent(in) :: x
        real :: res
        res = x * x
    end function square

end program main