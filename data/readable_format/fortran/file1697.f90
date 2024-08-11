program test_specific_abs_c8
    implicit none
    complex(kind=8) :: test_val
    real(kind=8) :: result

    ! Test 1: Positive real and imaginary parts
    test_val = (3.0d0, 4.0d0)
    result = specific__abs_c8(test_val)
    print *, "Test 1 (3+4i): Expected 5, got ", result

    ! Test 2: Negative real part
    test_val = (-3.0d0, 4.0d0)
    result = specific__abs_c8(test_val)
    print *, "Test 2 (-3+4i): Expected 5, got ", result

    ! Test 3: Negative imaginary part
    test_val = (3.0d0, -4.0d0)
    result = specific__abs_c8(test_val)
    print *, "Test 3 (3-4i): Expected 5, got ", result

    ! Test 4: Negative real and imaginary parts
    test_val = (-3.0d0, -4.0d0)
    result = specific__abs_c8(test_val)
    print *, "Test 4 (-3-4i): Expected 5, got ", result

contains

    elemental function specific__abs_c8 (parm)
        complex (kind=8), intent (in) :: parm
        real(kind=8) :: specific__abs_c8

        specific__abs_c8 = abs(parm)
    end function

end program test_specific_abs_c8