module constants
    implicit none
    integer, parameter :: sgl = selected_real_kind(p=6)
    integer, parameter :: dbl = selected_real_kind(p=13)
    real(kind=dbl), parameter :: eOverAmu = 9.58084d7
    real(kind=dbl), parameter :: mpc2 = 938271998.38
    real(kind=dbl), parameter :: c = 2.99792458d8
    real(kind=dbl), parameter :: pi = 3.141592653597932384
    real(kind=dbl), parameter :: q = 1.60217646d-19
    real(kind=dbl), parameter :: me = 9.10938188d-31
    real(kind=dbl), parameter :: mi = 1.67262158d-27
    real(kind=dbl), parameter :: eps0 = 8.854187817d-12
    complex(kind=dbl), parameter :: zi = cmplx(0.0, 1.0, kind=dbl)
    real(kind=dbl), parameter :: mu0 = 1.2566370614d-06
    real(kind=dbl), parameter :: clight = 299792458.0
    complex(kind=dbl) :: metal = (1e8, 1e8)
end module constants

program testConstants
    use constants
    implicit none

    ! Example usage of constants
    print *, "eOverAmu =", eOverAmu
    print *, "pi =", pi
    print *, "zi =", zi

    ! Add more tests or usage examples here
end program testConstants