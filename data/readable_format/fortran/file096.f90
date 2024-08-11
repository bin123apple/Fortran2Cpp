program squareTest
    implicit none
    real :: x, result

    x = 5.0
    result = square(x)
    if (result == 25.0) then
        print *, "Test passed: The square of", x, "is", result
    else
        print *, "Test failed"
    end if

contains

    function square(num) result(squareResult)
        real, intent(in) :: num
        real :: squareResult
        squareResult = num * num
    end function square

end program squareTest