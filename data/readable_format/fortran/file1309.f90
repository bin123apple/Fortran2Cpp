program test_sin
    use, intrinsic :: iso_fortran_env, only: real32
    implicit none
    interface
        elemental function specific__sin_r4(parm) result(sine_val)
            import :: real32
            real(real32), intent(in) :: parm
            real(real32) :: sine_val
        end function specific__sin_r4
    end interface

    real(real32) :: result
    real(real32), parameter :: pi = 3.14159265_real32
    real(real32) :: error_threshold
    real(real32) :: input
    real(real32) :: expected_output

    input = pi / 6.0_real32
    expected_output = 0.5_real32
    error_threshold = 1.0E-5_real32

    result = specific__sin_r4(input)
    print *, "Testing specific__sin_r4 with input:", input
    if (abs(result - expected_output) < error_threshold) then
        print *, "PASS"
    else
        print *, "FAIL"
    end if
end program test_sin

elemental function specific__sin_r4(parm) result(sine_val)
    use, intrinsic :: iso_fortran_env, only: real32
    real(real32), intent(in) :: parm
    real(real32) :: sine_val

    sine_val = sin(parm)
end function specific__sin_r4