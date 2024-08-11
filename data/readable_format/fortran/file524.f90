module utilities_module
    implicit none
contains
    function square(input) result(output)
        real, intent(in) :: input
        real :: output
        output = input * input
    end function square
end module utilities_module

program test_utilities
    use utilities_module
    implicit none
    real :: value
    real :: result

    ! Example usage of square function
    value = 5.0
    result = square(value)
    print *, "The square of ", value, " is ", result

end program test_utilities