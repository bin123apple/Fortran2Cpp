program test_square
    implicit none
    real :: x = 2.0
    real :: result

    result = square(x)
    print *, "Square of", x, "is", result

    if (result == 4.0) then
        print *, "Test passed."
    else
        print *, "Test failed."
    end if
contains

    function square(x) result(y)
        real, intent(in) :: x
        real :: y

        y = x**2
    end function square

end program test_square