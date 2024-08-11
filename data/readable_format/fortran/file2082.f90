module math_operations
    implicit none
contains
    function square(x) result(res)
        real, intent(in) :: x
        real :: res
        res = x * x
    end function square
end module math_operations

program test_square
    use math_operations
    implicit none
    real :: y
    real :: input_value

    input_value = 4.0
    y = square(input_value)
    print *, "Square of ", input_value, " is: ", y
end program test_square