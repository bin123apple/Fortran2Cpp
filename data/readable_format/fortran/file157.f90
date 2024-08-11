! Compile with: gfortran -o square square.f90
program test_square
    implicit none
    integer :: x, result

    x = 4
    result = square(x)
    print *, "Square of", x, "is", result

contains

    function square(n) result(square_n)
        integer, intent(in) :: n
        integer :: square_n

        square_n = n * n
    end function square

end program test_square