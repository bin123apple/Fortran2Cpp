program test_sinh
    implicit none
    real(kind=4) :: input, output, expected_output

    interface
        elemental function specific__sinh_r4(parm) result(specific_sinh)
            real(kind=4), intent(in) :: parm
            real(kind=4) :: specific_sinh
        end function specific__sinh_r4
    end interface

    input = 0.5_4
    expected_output = sinh(input)
    output = specific__sinh_r4(input)

    print *, "Testing specific__sinh_r4 with input:", input
    print *, "Expected output:", expected_output, "Actual output:", output

    if (abs(output - expected_output) < 1.0E-6_4) then
        print *, "Test passed."
    else
        print *, "Test failed."
    end if
end program test_sinh

! This should be placed in a separate module or in the same program above.
elemental function specific__sinh_r4(parm) result(specific_sinh)
    real(kind=4), intent(in) :: parm
    real(kind=4) :: specific_sinh
    specific_sinh = sinh(parm)
end function specific__sinh_r4