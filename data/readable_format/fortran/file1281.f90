module chebft_mod
    implicit none
contains
    subroutine chebft(a, b, c, n, func)
        implicit none
        integer, intent(in) :: n
        real, intent(in) :: a, b
        real, intent(out), dimension(1:n) :: c
        interface
            real function func(x)
                real, intent(in) :: x
            end function func
        end interface
        integer :: j, k
        real :: bma, bpa, fac, pi, sum, y
        real, dimension(1:n) :: f

        pi = 4.0*atan(1.0)
        bma = 0.5*(b - a)
        bpa = 0.5*(b + a)

        do k = 1, n
            y = cos(pi*(k - 0.5)/n)
            f(k) = func(y*bma + bpa)
        end do
        fac = 2.0/n
        do j = 1, n
            sum = 0.0
            do k = 1, n
                sum = sum + f(k)*cos(pi*(j - 1)*(k - 0.5)/n)
            end do
            c(j) = fac*sum
        end do
    end subroutine chebft

    real function func12(x)
        real, intent(in) :: x
        func12 = x**0.5
    end function func12

    real function funcm12(x)
        real, intent(in) :: x
        funcm12 = 1.0/x**0.5
    end function funcm12
end module chebft_mod

program test_chebft
    use chebft_mod
    implicit none
    integer, parameter :: n = 10
    real :: a, b
    real, dimension(1:n) :: c
    integer :: i

    a = 0.0
    b = 1.0

    ! Test with func12
    call chebft(a, b, c, n, func12)
    print *, 'Results with func12:'
    do i = 1, n
        print *, c(i)
    end do

    ! Test with funcm12
    call chebft(a, b, c, n, funcm12)
    print *, 'Results with funcm12:'
    do i = 1, n
        print *, c(i)
    end do
end program test_chebft