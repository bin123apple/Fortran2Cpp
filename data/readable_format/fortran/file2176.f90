! euler_stability.f90
program euler_stability
    implicit none
    integer :: i, N
    real :: x, h

    h = 0.1
    N = NINT(1.0 / h)

    x = 1.01
    print *, 0.0, x
    do i=1,N
        x = x + h * f(x, (i - 1) * h)
        print *, i * h, x
    end do

contains

    real function f(x, t)
        real, intent(in) :: x, t
        f = -100.0 * x + 100.0 * t + 101.0
    end function f
end program euler_stability