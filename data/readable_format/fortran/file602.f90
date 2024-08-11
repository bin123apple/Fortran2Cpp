program test_infel
    implicit none
    double precision v, va, vv, dvv
    integer io

    ! Test case 1: io = 0
    v = 0.5
    va = 0.5
    io = 0
    call infel(v, va, vv, dvv, io)
    print *, "Test 1 (io=0): Expected vv=0.625, dvv=0.25; Actual vv=", vv, "dvv=", dvv

    ! Test case 2: io = 1
    v = -0.5
    va = 0.5
    io = 1
    call infel(v, va, vv, dvv, io)
    print *, "Test 2 (io=1): Expected vv=-0.75, dvv=4; Actual vv=", vv, "dvv=", dvv

contains

    subroutine infel(v, va, vv, dvv, io)
        double precision, intent(in) :: v, va
        double precision, intent(out) :: vv, dvv
        integer, intent(in) :: io
        double precision sgn, fac, fac1
        double precision, parameter :: one = 1.0, half = 0.5, two = 2.0

        vv = half * (one + va * v)
        dvv = half * va
        if (io .eq. 0) return
        sgn = one
        if (io .eq. 1) sgn = -one
        fac = one - sgn * v
        fac1 = half * abs(va + sgn)
        vv = fac1 + two * v * va / fac
        dvv = two * va / (fac * fac)
    end subroutine infel

end program test_infel