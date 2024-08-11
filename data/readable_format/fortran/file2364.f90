! Corrected Fortran code with unit test
subroutine fporde(x, y, m, kx, ky, tx, nx, ty, ny, nummer, index, nreg)
    implicit none
    integer, intent(in) :: m, kx, ky, nx, ny, nreg
    real(8), intent(in) :: x(m), y(m), tx(nx), ty(ny)
    integer, intent(out) :: nummer(m), index(nreg)
    real(8) :: xi, yi
    integer :: i, im, k, kx1, ky1, k1, l, l1, nk1x, nk1y, num, nyy

    kx1 = kx + 1
    ky1 = ky + 1
    nk1x = nx - kx1
    nk1y = ny - ky1
    nyy = nk1y - ky

    do i = 1, nreg
        index(i) = 0
    end do

    do im = 1, m
        xi = x(im)
        yi = y(im)
        l = kx1
        l1 = l + 1

        do while (.not. (xi < tx(l1) .or. l == nk1x))
            l = l1
            l1 = l + 1
        end do

        k = ky1
        k1 = k + 1

        do while (.not. (yi < ty(k1) .or. k == nk1y))
            k = k1
            k1 = k + 1
        end do

        num = (l - kx1) * nyy + k - ky
        nummer(im) = index(num)
        index(num) = im
    end do
end subroutine fporde

program test_fporde
    implicit none
    integer, parameter :: m = 5, kx = 1, ky = 1, nx = 5, ny = 5, nreg = 16
    real(8), dimension(m) :: x, y
    real(8), dimension(nx) :: tx
    real(8), dimension(ny) :: ty
    integer, dimension(m) :: nummer
    integer, dimension(nreg) :: index
    integer :: i

    ! Initialize test data
    x = (/ 1.0, 2.0, 3.0, 4.0, 5.0 /)
    y = (/ 1.0, 2.0, 3.0, 4.0, 5.0 /)
    tx = (/ 0.0, 1.5, 2.5, 3.5, 4.5 /)
    ty = (/ 0.0, 1.5, 2.5, 3.5, 4.5 /)

    ! Call subroutine
    call fporde(x, y, m, kx, ky, tx, nx, ty, ny, nummer, index, nreg)

    ! Print results
    print *, 'nummer:'
    do i = 1, m
        print *, nummer(i)
    end do

    print *, 'index:'
    do i = 1, nreg
        print *, index(i)
    end do
end program test_fporde