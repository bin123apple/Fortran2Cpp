! Compile with: gfortran -o square square.f90
program test_square
    implicit none
    real :: number, result

    number = 4.0
    result = square(number)
    print *, 'Square of', number, 'is', result

contains

    function square(x) result(square_result)
        real, intent(in) :: x
        real :: square_result

        square_result = x * x
    end function square
end program test_square