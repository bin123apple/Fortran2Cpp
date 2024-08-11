module math_module
    implicit none
contains
    function square(x) result(res)
        real, intent(in) :: x
        real :: res
        res = x * x
    end function square
end module math_module

program test
    use math_module
    real :: number, result
    number = 4.0
    result = square(number)
    print *, "The square of", number, "is", result
end program test