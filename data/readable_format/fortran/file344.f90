module specific_sqrt_r4_module
implicit none
contains
    elemental function specific__sqrt_r4 (parm) result(res)
       real (kind=4), intent(in) :: parm
       real (kind=4) :: res

       res = sqrt(parm)
    end function specific__sqrt_r4
end module specific_sqrt_r4_module

program test_specific_sqrt_r4
    use specific_sqrt_r4_module
    implicit none
    real(kind=4) :: input, expected, result
    logical :: test_passed

    ! Test 1
    input = 4.0
    expected = 2.0
    result = specific__sqrt_r4(input)
    test_passed = (abs(result - expected) < 1.0E-6)
    print *, "Test 1 with input", input, "expected", expected, "result", result, "Passed:", test_passed

    ! Test 2
    input = 9.0
    expected = 3.0
    result = specific__sqrt_r4(input)
    test_passed = (abs(result - expected) < 1.0E-6)
    print *, "Test 2 with input", input, "expected", expected, "result", result, "Passed:", test_passed

    ! Test 3
    input = 0.0
    expected = 0.0
    result = specific__sqrt_r4(input)
    test_passed = (abs(result - expected) < 1.0E-6)
    print *, "Test 3 with input", input, "expected", expected, "result", result, "Passed:", test_passed

end program test_specific_sqrt_r4