module abs_module
contains
    elemental function specific_abs_r4(parm) result(res)
        real(kind=4), intent(in) :: parm
        real(kind=4) :: res
        res = abs(parm)
    end function specific_abs_r4
end module abs_module

program test_specific_abs_r4
    use abs_module
    implicit none
    real(kind=4) :: test_val, expected, result
    integer :: errors

    errors = 0

    ! Test case 1
    test_val = -5.5
    expected = 5.5
    result = specific_abs_r4(test_val)
    if (result /= expected) then
        print *, 'Test case 1 failed. Expected: ', expected, ' Got: ', result
        errors = errors + 1
    end if

    ! Test case 2
    test_val = 3.2
    expected = 3.2
    result = specific_abs_r4(test_val)
    if (result /= expected) then
        print *, 'Test case 2 failed. Expected: ', expected, ' Got: ', result
        errors = errors + 1
    end if

    ! Test case 3
    test_val = 0.0
    expected = 0.0
    result = specific_abs_r4(test_val)
    if (result /= expected) then
        print *, 'Test case 3 failed. Expected: ', expected, ' Got: ', result
        errors = errors + 1
    end if

    if (errors == 0) then
        print *, 'All tests passed.'
    else
        print *, 'Number of failed tests: ', errors
    end if
end program test_specific_abs_r4