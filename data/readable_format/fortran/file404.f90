module functions
    implicit none
    real(kind=8) :: epsilon
    save

contains

    real(kind=8) function f_sqrt(x)
        implicit none
        real(kind=8), intent(in) :: x
        f_sqrt = x**2 - 4.d0
    end function f_sqrt

    real(kind=8) function fprime_sqrt(x)
        implicit none
        real(kind=8), intent(in) :: x
        fprime_sqrt = 2.d0 * x
    end function fprime_sqrt

    real(kind=8) function f_quartic(x)
        implicit none
        real(kind=8), intent(in) :: x
        f_quartic = (x - 1.d0)**4 - epsilon
    end function f_quartic

    real(kind=8) function fprime_quartic(x)
        implicit none
        real(kind=8), intent(in) :: x
        fprime_quartic = 4.d0 * (x - 1.d0)**3
    end function fprime_quartic

end module functions

program test_functions
    use functions
    implicit none
    real(kind=8) :: x

    epsilon = 1e-6

    x = 2.0d0
    print *, "f_sqrt(", x, ") = ", f_sqrt(x)
    print *, "fprime_sqrt(", x, ") = ", fprime_sqrt(x)
    print *, "f_quartic(", x, ") = ", f_quartic(x)
    print *, "fprime_quartic(", x, ") = ", fprime_quartic(x)

end program test_functions