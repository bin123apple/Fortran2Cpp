module math_operations
    implicit none
contains
    elemental function specific__sqrt_c8(parm)
        complex(kind=8), intent(in) :: parm
        complex(kind=8) :: specific__sqrt_c8
        specific__sqrt_c8 = sqrt(parm)
    end function specific__sqrt_c8
end module math_operations

program test_specific_sqrt_c8
    use math_operations
    implicit none
    complex(kind=8) :: test_value, result

    ! Define a test complex number
    test_value = cmplx(4.0_8, 9.0_8, kind=8)

    ! Compute the square root of the complex number
    result = specific__sqrt_c8(test_value)

    ! Print the result
    print *, "The square root of ", test_value, " is ", result

    ! Simple check to see if the result is as expected (approximately 2 + 2.25i)
    if (abs(real(result) - 2.0_8) < 1.0E-6_8 .and. &
        abs(aimag(result) - 2.25_8) < 1.0E-6_8) then
        print *, "Test passed."
    else
        print *, "Test failed."
    end if
end program test_specific_sqrt_c8