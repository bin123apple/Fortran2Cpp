program testSquare
    implicit none
    real :: x, result

    ! Example usage of the square function
    x = 4.0
    result = square(x)
    print *, "Square of ", x, " is ", result
    ! Add more function calls or tests here if needed

contains

    function square(x) result(res)
        implicit none
        real, intent(in) :: x
        real :: res
        res = x * x
    end function square

end program testSquare