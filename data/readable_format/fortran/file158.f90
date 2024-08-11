program test_specific_tan_r8
    implicit none
    real(kind=8) :: input, output

    ! Test 1: tan(pi/4) should be approximately 1
    input = 3.14159265358979323846 / 4.0
    output = specific__tan_r8(input)
    print *, "Test 1: Input = ", input, " Output = ", output, " Expected = ", 1.0

    ! Add more tests as needed
    ! Test 2: tan(0) should be 0
    input = 0.0
    output = specific__tan_r8(input)
    print *, "Test 2: Input = ", input, " Output = ", output, " Expected = ", 0.0

contains

    elemental function specific__tan_r8 (parm)
        real (kind=8), intent (in) :: parm
        real (kind=8) :: specific__tan_r8
        specific__tan_r8 = tan (parm)
    end function specific__tan_r8

end program test_specific_tan_r8