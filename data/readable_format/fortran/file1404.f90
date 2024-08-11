program test_anint
    use, intrinsic :: iso_fortran_env, only: real64
    implicit none

    real(kind=real64) :: result

    ! Function prototype is not required since the function is contained within the program

    ! Test 1
    result = specific__anint_r8(1.4_real64)
    if (result /= 1.0_real64) then
        print *, "Test 1 failed"
    else
        print *, "Test 1 passed"
    end if

    ! Test 2
    result = specific__anint_r8(1.6_real64)
    if (result /= 2.0_real64) then
        print *, "Test 2 failed"
    else
        print *, "Test 2 passed"
    end if

    ! Test 3
    result = specific__anint_r8(-1.4_real64)
    if (result /= -1.0_real64) then
        print *, "Test 3 failed"
    else
        print *, "Test 3 passed"
    end if

    ! Test 4
    result = specific__anint_r8(-1.6_real64)
    if (result /= -2.0_real64) then
        print *, "Test 4 failed"
    else
        print *, "Test 4 passed"
    end if

contains

    elemental function specific__anint_r8(parm) result(res)
        real(kind=real64), intent(in) :: parm
        real(kind=real64) :: res

        res = anint(parm)
    end function specific__anint_r8

end program test_anint