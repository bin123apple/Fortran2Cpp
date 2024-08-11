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
    real :: test_value, squared_value

    ! Set a test value
    test_value = 4.0
    ! Calculate the square
    squared_value = square(test_value)
    ! Output the result
    print *, "The square of", test_value, "is", squared_value
end program test_square