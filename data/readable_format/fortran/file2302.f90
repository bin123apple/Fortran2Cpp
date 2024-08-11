module specific_abs_c4_mod
    implicit none
    contains
    ! The elemental function
    elemental function specific__abs_c4(parm) result(res)
        complex(kind=4), intent(in) :: parm
        real(kind=4) :: res

        res = abs(parm)
    end function specific__abs_c4
end module specific_abs_c4_mod

program test_specific_abs_c4
    use specific_abs_c4_mod
    implicit none

    complex(kind=4) :: test_val
    real(kind=4) :: result, expected, tolerance

    ! Test case: complex number (3.0, 4.0)
    test_val = cmplx(3.0_4, 4.0_4, kind=4)
    expected = 5.0_4
    tolerance = 1.0e-6_4

    result = specific__abs_c4(test_val)

    ! Check if the result is as expected within a tolerance
    if (abs(result - expected) < tolerance) then
        print *, "Test passed. Result: ", result
    else
        print *, "Test failed. Result: ", result
    end if
end program test_specific_abs_c4