module fonction
    implicit none
    double precision :: f_sigma = 1.d0, f_mu = 0.d0
    double precision, parameter :: pi = 3.14159265359d0

contains

    double precision function unefonction(x)
        implicit none
        double precision, intent(in) :: x
        unefonction = (exp(x) - 10.) / (x + 2.)
    end function unefonction

    double precision function gaussienne(x, mu, sig)
        implicit none
        double precision, intent(in) :: x
        double precision, optional, intent(in) :: mu, sig
        double precision :: norme, moy, sigma

        if (present(sig)) then
            sigma = sig
        else
            sigma = f_sigma
        end if

        if (present(mu)) then
            moy = mu
        else
            moy = f_mu
        end if

        norme = 1.d0 / (sigma * sqrt(2.d0 * pi))
        gaussienne = norme * exp(-(x - moy)**2 / (2.d0 * sigma**2))
    end function gaussienne

end module fonction

program test_fonction
    use fonction
    implicit none

    double precision :: x, mu, sigma
    double precision :: result

    ! Test unefonction
    print *, "Testing unefonction"
    x = 1.0d0
    result = unefonction(x)
    print *, "unefonction(", x, ") = ", result

    ! Test gaussienne with default parameters
    print *, "Testing gaussienne with default parameters"
    x = 0.0d0
    result = gaussienne(x)
    print *, "gaussienne(", x, ") = ", result

    ! Test gaussienne with specific parameters
    print *, "Testing gaussienne with specific parameters"
    x = 0.0d0
    mu = 0.0d0
    sigma = 2.0d0
    result = gaussienne(x, mu, sigma)
    print *, "gaussienne(", x, ", ", mu, ", ", sigma, ") = ", result

end program test_fonction