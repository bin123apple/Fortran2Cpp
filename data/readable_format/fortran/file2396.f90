program test_w
    implicit none
    double precision :: result
    double precision :: r, h, coef

    ! Test case 1
    r = 0.5d0
    h = 1.0d0
    coef = 2.0d0
    result = w(r, h, coef)
    print *, 'Test case 1: ', result

    ! Test case 2
    r = 1.5d0
    h = 1.0d0
    coef = 2.0d0
    result = w(r, h, coef)
    print *, 'Test case 2: ', result

    ! Test case 3
    r = 2.5d0
    h = 1.0d0
    coef = 2.0d0
    result = w(r, h, coef)
    print *, 'Test case 3: ', result

contains

    double precision function w(r, h, coef)
        implicit none
        double precision, parameter :: a1 = 2.0d0 / 3.0d0
        double precision :: r, h, s, q, dms, coef
        s = r / h
        if (s <= 1.d0) then
            q = a1 * (1.d0 - 1.5d0 * (s * s) * (1.d0 - s / 2.d0))
        elseif (s > 1.d0 .and. s < 2.d0) then
            dms = 2.d0 - s
            q = a1 * (dms * dms * dms) / 6.d0
        else
            q = 0.d0
        endif
        w = q * coef
    end function w

end program test_w