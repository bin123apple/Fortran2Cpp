! square_module.f90
module square_mod
    implicit none
contains
    function square(x) result(res)
        real, intent(in) :: x
        real :: res
        res = x * x
    end function square
end module square_mod

! test_square.f90
program test_square
    use square_mod
    implicit none
    real :: input
    real :: output

    ! Set the input value
    input = 4.0
    output = square(input)
    print *, "The square of", input, "is", output
end program test_square