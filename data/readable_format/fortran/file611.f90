program test_scheck
    implicit none
    integer, parameter :: npde = 2
    integer, parameter :: nepn = npde + 2
    integer, parameter :: kx = npde + 1
    integer, parameter :: ky = npde + 2
    integer, parameter :: mtri = 3
    double precision :: y(nepn, mtri)
    double precision :: dxymin
    double precision :: dxy0(mtri), dxy1(mtri), dxy(mtri)
    integer :: errc, kvec, i, j

    ! Initialize values
    dxymin = 0.5
    ! Note: Adjusted the reshape function's shape parameter to correctly specify the array dimensions
    y = reshape([0.0d0, 0.0d0, 1.0d0, 0.0d0, &
                0.0d0, 1.0d0, 0.0d0, 1.0d0, &
                0.0d0, 0.0d0, 1.0d0, 0.0d0, &
                0.0d0, 1.0d0, 0.0d0], shape=[nepn, mtri])

    ! Invoke scheck subroutine with test data
    call scheck(y, 0, errc, dxymin, dxy0, dxy1, dxy)
    print *, 'Error code:', errc

contains

    subroutine scheck(y, kvec, errc, dxymin, dxy0, dxy1, dxy)
        integer, intent(in) :: kvec
        integer, intent(out) :: errc
        double precision, intent(in) :: y(nepn, mtri), dxymin
        double precision, intent(inout) :: dxy0(mtri), dxy1(mtri), dxy(mtri)
        integer :: j
        double precision :: x0, x1, x2, y0, y1, y2

        if (kvec == 1) then
            do j = 1, mtri
                dxy1(j) = dxy(j)
            end do
        end if

        do j = 1, mtri
            x0 = y(kx, j)
            y0 = y(ky, j)
            x1 = y(kx, j)
            y1 = y(ky, j)
            x2 = y(kx, j)
            y2 = y(ky, j)
            dxy(j) = abs((x0 - x2) * (y1 - y0) - (x1 - x0) * (y0 - y2))
            if (dxy(j) < dxymin) then
                errc = 1
                return
            endif
        end do

        if (kvec == 0) then
            do j = 1, mtri
                dxy0(j) = dxy(j)
            end do
        end if

        errc = 0
    end subroutine scheck

end program test_scheck