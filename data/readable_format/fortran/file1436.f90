subroutine waltbrdf(a, ap, b, c, mu, np, rm, rp, brdfint)
    implicit none
    integer :: mu, np, k, j
    real, dimension(-mu:mu) :: rm
    real, dimension(np) :: rp
    real, dimension(-mu:mu,np) :: brdfint
    real :: a, ap, b, c
    real :: xmu, ts, view, tv, fi, phi

    xmu = rm(0)
    ts = acos(xmu)
    do k = 1, np
        do j = -mu, mu
            view = rm(j)
            tv = acos(view)
            if (j == -mu) then
                fi = rp(k)
            else
                fi = rp(k) + rm(-mu)
            endif
            phi = fi
            brdfint(j, k) = a * (ts * ts * tv * tv) + ap * (ts * ts + tv * tv) + b * ts * tv * cos(phi) + c
        end do
    end do
end subroutine waltbrdf

program test
    implicit none
    integer, parameter :: mu=3, np=2
    real, dimension(-mu:mu) :: rm
    real, dimension(np) :: rp
    real, dimension(-mu:mu,np) :: brdfint
    integer :: i

    ! Initialize inputs
    do i = -mu, mu
        rm(i) = i * 0.1
    end do
    do i = 1, np
        rp(i) = i * 0.2
    end do

    ! Call subroutine
    call waltbrdf(1.0, 2.0, 3.0, 4.0, mu, np, rm, rp, brdfint)

    ! Print results
    do i = -mu, mu
        print *, 'brdfint(', i, ', 1) = ', brdfint(i, 1)
        print *, 'brdfint(', i, ', 2) = ', brdfint(i, 2)
    end do
end program test