! fporde.f90
subroutine fporde(x, y, m, kx, ky, tx, nx, ty, ny, nummer, index, nreg)
    implicit none
    integer, intent(in) :: m, kx, ky, nx, ny, nreg
    real, dimension(m), intent(in) :: x, y
    real, dimension(nx), intent(in) :: tx
    real, dimension(ny), intent(in) :: ty
    integer, dimension(m), intent(out) :: nummer
    integer, dimension(nreg), intent(out) :: index
    integer :: i, im, k, kx1, ky1, k1, l, l1, nk1x, nk1y, num, nyy
    real :: xi, yi

    ! Initialize
    kx1 = kx + 1
    ky1 = ky + 1
    nk1x = nx - kx1
    nk1y = ny - ky1
    nyy = nk1y - ky1 + 1

    ! Initialize index array
    do i = 1, nreg
        index(i) = 0
    end do

    ! Main loop
    do im = 1, m
        xi = x(im)
        yi = y(im)
        l = kx1
        do while (xi >= tx(l+1) .and. l < nk1x)
            l = l + 1
        end do

        k = ky1
        do while (yi >= ty(k+1) .and. k < nk1y)
            k = k + 1
        end do

        num = (l - kx1) * nyy + (k - ky1) + 1
        nummer(im) = index(num) + 1
        index(num) = im
    end do
end subroutine fporde

program test_fporde
    implicit none
    integer, parameter :: m = 5, kx = 2, ky = 2, nx = 7, ny = 7, nreg = 12
    real :: x(m) = (/ 1.0, 2.0, 3.0, 4.0, 5.0 /)
    real :: y(m) = (/ 1.0, 2.0, 3.0, 4.0, 5.0 /)
    real :: tx(nx) = (/ 0.0, 1.0, 2.0, 3.0, 4.0, 5.0, 6.0 /)
    real :: ty(ny) = (/ 0.0, 1.0, 2.0, 3.0, 4.0, 5.0, 6.0 /)
    integer :: nummer(m), index(nreg), i

    call fporde(x, y, m, kx, ky, tx, nx, ty, ny, nummer, index, nreg)

    print*, 'Fortran Stdout: nummer:'
    do i = 1, m
        print*, nummer(i)
    end do

    print*, 'index:'
    do i = 1, nreg
        print*, index(i)
    end do
end program test_fporde