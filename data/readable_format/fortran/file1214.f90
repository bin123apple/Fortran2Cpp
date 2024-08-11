subroutine sgtsl(n, c, d, e, b, info)
    implicit none
    integer, intent(in) :: n
    double precision, dimension(n), intent(inout) :: c, d, e, b
    integer, intent(out) :: info
    integer :: k, kp1, nm1, nm2
    double precision :: t

    info = 0
    nm1 = n - 1
    if (nm1 < 1) return

    do k = 1, nm1
        kp1 = k + 1
        if (abs(c(k)) >= abs(e(k))) then
            t = e(k) / c(k)
            e(k) = c(k)
            c(k) = d(k) - t * e(k)
            d(k) = b(k) - t * d(k)
            b(k) = -t * b(k)
        else
            t = c(k) / e(k)
            c(k) = e(k)
            e(k) = d(k) - t * c(k)
            d(k) = b(k) - t * d(k)
            b(k) = -t * b(k)
        endif
    end do

    b(1) = d(1) / c(1)
    do k = 2, n
        b(k) = (d(k) - e(k-1) * b(k-1)) / c(k)
    end do

    do k = n-1, 1, -1
        b(k) = b(k) - b(k+1) * e(k) / c(k+1)
    end do
end subroutine sgtsl

program test_sgtsl
    implicit none
    integer :: n, info
    parameter (n=4)
    double precision :: c(n), d(n), e(n), b(n)
    integer :: i

    ! Initialize the arrays with some test values
    c = (/1.0d0, 2.0d0, 3.0d0, 4.0d0/)
    d = (/1.0d0, 2.0d0, 3.0d0, 4.0d0/)
    e = (/0.0d0, 1.0d0, 1.0d0, 1.0d0/)
    b = (/5.0d0, 5.0d0, 5.0d0, 5.0d0/)
    info = 0

    call sgtsl(n, c, d, e, b, info)

    print *, 'Info:', info
    print *, 'Solution vector b:'
    do i = 1, n
        print *, b(i)
    end do
end program test_sgtsl