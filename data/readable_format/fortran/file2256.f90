module specific_abs_module
    implicit none
    contains

    elemental function specific__abs_c8(parm) result(res)
        complex(kind=8), intent(in) :: parm
        real(kind=8) :: res

        res = abs(parm)
    end function specific__abs_c8
end module specific_abs_module

program test_specific_abs_c8
    use specific_abs_module
    implicit none
    complex(kind=8) :: parm
    real(kind=8) :: result, expected

    ! Test case 1
    parm = (3.0_8, 4.0_8)
    expected = 5.0_8  ! Expected result is the magnitude sqrt(3^2 + 4^2) = 5
    result = specific__abs_c8(parm)
    if (abs(result - expected) < 1e-12) then
        print *, 'Test case 1 passed'
    else
        print *, 'Test case 1 failed'
    end if

    ! Add more test cases as needed
end program test_specific_abs_c8