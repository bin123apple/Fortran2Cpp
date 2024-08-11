module m_ezcu_knl
    implicit none
contains
    function square(x) result(y)
        real, intent(in) :: x
        real :: y
        
        y = x * x
    end function square
end module m_ezcu_knl

program main
    use m_ezcu_knl
    implicit none

    real :: num
    real :: result

    ! Example usage of the square function
    num = 4.0
    result = square(num)
    print *, "The square of", num, "is", result
end program main