module math_functions
    implicit none
    contains
        elemental function specific__asin_r4(parm) result(res)
            real(kind=4), intent(in) :: parm
            real(kind=4) :: res
            res = asin(parm)
        end function specific__asin_r4
end module math_functions

program test_asin
    use math_functions
    implicit none
    real(kind=4) :: input, output, expected

    ! Test 1: asin(0.0) = 0.0
    input = 0.0
    expected = 0.0
    output = specific__asin_r4(input)
    if (abs(output - expected) < 1.0E-7) then
        print *, "Test 1 Passed"
    else
        print *, "Test 1 Failed"
    end if

    ! Test 2: asin(0.5) = π/6
    input = 0.5
    expected = 0.5235987756  ! Approximately π/6
    output = specific__asin_r4(input)
    if (abs(output - expected) < 1.0E-7) then
        print *, "Test 2 Passed"
    else
        print *, "Test 2 Failed"
    end if

end program test_asin