module bessel_module
implicit none
contains

subroutine zbessela(lmax, x, a)
    implicit none
    integer, intent(in) :: lmax
    real(8), intent(in) :: x
    real(8), intent(out) :: a(0:lmax)
    integer, parameter :: lst = 25
    integer :: l
    real(8) :: xi, a0, a1, at, t1, t2, xmin

    if ((lmax .lt. 0) .or. (lmax .gt. 50)) then
        print *, 'Error(zbessela): lmax out of range:', lmax
        stop
    endif
    if ((x .lt. 0.d0) .or. (x .gt. 1.d8)) then
        print *, 'Error(zbessela): x out of range:', x
        stop
    endif

    xi = 1.d0 / x
    xmin = 1.d-7
    select case (lmax)
    case (0)
        xmin = 1.d-6
    case (1:2)
        xmin = 1.d-4
    case (3:4)
        xmin = 1.d-2
    case (5:)
        xmin = 1.d0
    end select

    if (x .lt. xmin) then
        a(0) = 1.d0
        t1 = 1.d0
        t2 = 1.d0
        do l = 1, lmax
            t1 = t1 / dble(2*l + 1)
            t2 = -t2 * x
            a(l) = t2 * t1
        end do
        return
    endif

    a(0) = xi * (sinh(x))
    if (lmax .eq. 0) return
    a(1) = xi * (a(0) - cosh(x))
    if (lmax .eq. 1) return

    a0 = a(0)
    a1 = a(1)
    do l = 2, lmax
        at = dble(2*l - 1) * a1 * xi + a0
        a0 = a1
        a1 = at
        a(l) = a1
    end do
end subroutine zbessela

end module bessel_module

program test_zbessela
    use bessel_module
    implicit none
    integer, parameter :: lmax = 5
    real(8), allocatable :: a(:)
    real(8) :: x
    integer :: i

    allocate(a(0:lmax))
    x = 0.5d0

    call zbessela(lmax, x, a)

    do i = 0, lmax
        print *, 'a(', i, ') =', a(i)
    end do
end program test_zbessela