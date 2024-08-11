module mod12
    implicit none
contains
    function square(x) result(res)
        integer, intent(in) :: x
        integer :: res
        res = x**2
    end function square
end module mod12

program testMod12
    use mod12
    implicit none
    integer :: testValue
    integer :: result

    ! Test the square function
    testValue = 4
    result = square(testValue)
    print *, "Square of", testValue, "is", result

    if (result == testValue**2) then
        print *, "Test passed!"
    else
        print *, "Test failed!"
    end if
end program testMod12