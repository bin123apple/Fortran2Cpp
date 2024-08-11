module specific_anint_r4_mod
    implicit none
contains
    elemental function specific__anint_r4(parm) result(res)
        real(kind=4), intent(in) :: parm
        real(kind=4) :: res

        res = anint(parm)
    end function specific__anint_r4
end module specific_anint_r4_mod

program test_anint_r4
    use specific_anint_r4_mod
    implicit none
    real(kind=4) :: test_val
    real(kind=4) :: result

    print *, "Fortran Tests:"
    test_val = 2.5
    result = specific__anint_r4(test_val)
    print *, "Test 1 (2.5): ", result

    test_val = 3.5
    result = specific__anint_r4(test_val)
    print *, "Test 2 (3.5): ", result

    test_val = -2.5
    result = specific__anint_r4(test_val)
    print *, "Test 3 (-2.5): ", result

    test_val = -3.5
    result = specific__anint_r4(test_val)
    print *, "Test 4 (-3.5): ", result

    test_val = 2.4
    result = specific__anint_r4(test_val)
    print *, "Test 5 (2.4): ", result

    test_val = -2.4
    result = specific__anint_r4(test_val)
    print *, "Test 6 (-2.4): ", result
end program test_anint_r4