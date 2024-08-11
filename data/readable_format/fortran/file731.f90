program entrytest
    implicit none
    integer :: res1, resE4
    real :: resF3
    double precision :: resE1, resG4
    logical :: resE2, resE3, resF4
    complex :: resF2, resG3

    ! Test f1 and e1
    res1 = f1(6)
    if (res1 /= 21) call abort()

    resE1 = e1(7)
    if (resE1 /= 49) call abort()

    ! Test f2
    resF2 = f2(0)
    if (resF2 /= cmplx(45.0, 0.0)) call abort()

    resF2 = f2(45)
    if (resF2 /= cmplx(1.0, 0.0)) call abort()

    resF2 = f2(46)
    if (resF2 /= cmplx(0.0, 0.0)) call abort()

    ! Test for e2
    resE2 = e2(45)
    if (.not. resE2) call abort()

    resE2 = e2(46)
    if (resE2) call abort()

    ! Tests for f3, e3, and g3
    resF3 = f3(17)
    if (resF3 /= 32) call abort()

    resE3 = e3(42)
    if (.not. resE3) call abort()

    resE3 = e3(41)
    if (resE3) call abort()

    resG3 = g3(12)
    if (resG3 /= cmplx(23.0, 0.0)) call abort()

    ! Tests for f4, e4, and g4
    resF4 = f4(-5)
    if (.not. resF4) call abort()

    resE4 = e4(0)
    if (resE4 /= 16) call abort()

    resG4 = g4(2)
    if (resG4 /= 19) call abort()

    print *, "All tests passed successfully."

contains

    integer function f1(a)
        integer, intent(in) :: a
        f1 = 15 + a
    end function f1

    double precision function e1(b)
        integer, intent(in) :: b
        e1 = 42 + b
    end function e1

    complex function f2(a)
        integer, intent(in) :: a
        if (a <= 0) then
            f2 = cmplx(45.0, 0.0)
        else
            if (a < 46) then
                f2 = cmplx(1.0, 0.0)
            else
                f2 = cmplx(0.0, 0.0)
            endif
        endif
    end function f2

    logical function e2(a)
        integer, intent(in) :: a
        e2 = a > 0 .and. a < 46
    end function e2

    real function f3(a)
        integer, intent(in) :: a
        f3 = 15 + a
    end function f3

    logical function e3(b)
        integer, intent(in) :: b
        e3 = b == 42
    end function e3

    complex function g3(b)
        integer, intent(in) :: b
        g3 = cmplx(b + 11, 0.0)
    end function g3

    logical function f4(a)
        integer, intent(in) :: a
        f4 = a < 0
    end function f4

    integer function e4(a)
        integer, intent(in) :: a
        if (a == 0) then
            e4 = 16 + a
        else
            e4 = 0
        endif
    end function e4

    double precision function g4(a)
        integer, intent(in) :: a
        if (a > 0) then
            g4 = 17 + a
        else
            g4 = 0
        endif
    end function g4

end program entrytest