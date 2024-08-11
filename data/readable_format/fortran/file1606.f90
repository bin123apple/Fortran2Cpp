! square_with_test.f90
program test_square
    implicit none
    real :: y
    
    ! Test the square function
    y = square(4.0)
    print *, "Square of 4.0 is", y
    print *, "Expected: 16.0"

contains

    function square(x) result(res)
        implicit none
        real, intent(in) :: x
        real :: res
        
        res = x * x
    end function square

end program test_square