program test_advance
    implicit none

    real*4 :: dt, flg
    integer :: nmol, ndim
    integer, parameter :: nm = 64, nd = 3
    real*4 :: q(nm, nd), v(nm, nd), oq(nm, nd), f(nm, nd)
    integer :: i, j

    ! Initialize variables
    nmol = nm
    ndim = nd
    dt = 0.01
    flg = 1.0

    do i = 1, nmol
        do j = 1, ndim
            q(i, j) = 1.0
            v(i, j) = 1.0
            oq(i, j) = 0.5
            f(i, j) = 0.1
        end do
    end do

    ! Call the subroutine
    call advance(q, v, oq, f, dt, flg, nmol, ndim)

    ! Print results to verify correctness
    print *, 'q: ', q
    print *, 'v: ', v
    print *, 'oq: ', oq

end program test_advance

subroutine advance(q, v, oq, f, dt, flg, nmol, ndim)
    implicit real*4(a-h, o-z)
    dimension q(64, 3), oq(64, 3), v(64, 3), f(64, 3)

    dt2 = dt * dt
    dt2i = 1.0 / (2.0 * dt)
    dti = 1.0 / dt

    if (nint(flg) .eq. 0) then
        do j = 1, ndim
            do i = 1, nmol
                temp = 2.0 * q(i, j) - oq(i, j) + f(i, j) * dt2
                v(i, j) = (temp - oq(i, j)) * dt2i
                oq(i, j) = q(i, j)
                q(i, j) = temp
            end do
        end do
    else
        do j = 1, ndim
            do i = 1, nmol
                temp = q(i, j) + v(i, j) * dt + 0.5 * f(i, j) * dt2
                v(i, j) = (temp - q(i, j)) * dti
                oq(i, j) = q(i, j)
                q(i, j) = temp
            end do
        end do
        flg = 0.0
    endif

    return
end subroutine advance