! plfit.f90
program test_plfit
    implicit none
    integer, parameter :: lx = 5
    real(8) :: x(lx) = (/1.0, 2.0, 3.0, 4.0, 5.0/)
    real(8) :: ksa(lx), av(lx)
    integer :: nosmall, i

    nosmall = 1

    call plfit(x, nosmall, ksa, av, lx)

    print *, "ksa:", ksa
    print *, "av:", av
end program test_plfit

subroutine plfit(x, nosmall, ksa, av, lx)
    integer :: lx, nosmall
    real(8) :: x(lx)
    real(8) :: ksa(lx), av(lx)
    integer :: i, j, n, k, nk
    real(8) :: lzs, cx, cf, ks, ksp, xmin

    xmin = 0.0
    do i = 1, lx
        if (x(i) <= xmin) then
            ksa(i) = 0.0
            av(i) = 0.0
        else
            xmin = x(i)
            lzs = 0.0
            n = 0
            do j = i, lx
                lzs = lzs + log(x(j) / xmin)
                n = n + 1
            end do
            av(i) = 1.0 + dble(n) / lzs
            if (nosmall > 0 .and. (av(i) - 1.0) / sqrt(dble(n)) < 0.1) then
                ksa(i) = 0.0 ! This condition was missing in the original Fortran code
            else
                ksp = 0.0
                nk = lx - i + 1
                do k = 1, nk
                    cx = dble(k) / dble(nk)
                    cf = 1.0 - (xmin / x(k + i - 1))**(av(i) - 1)
                    ks = abs(cf - cx)
                    if (ks > ksp) then
                        ksp = ks
                    end if
                end do
                ksa(i) = ksp
            end if
        end if
    end do
end subroutine plfit