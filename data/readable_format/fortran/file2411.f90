program test_gsw_fdelta
    use, intrinsic :: iso_fortran_env, only: real64
    implicit none

    real(real64) :: p, long, lat, result

    ! Test values
    p = 1000.0_real64
    long = 30.0_real64
    lat = -60.0_real64

    ! Call the function and print the result
    result = gsw_fdelta(p, long, lat)
    print *, "gsw_fdelta(", p, ", ", long, ", ", lat, ") = ", result

contains

    function gsw_fdelta(p, long, lat) result(fdelta)
        real(real64), intent(in) :: p, long, lat
        real(real64) :: fdelta
        real(real64) :: saar
        real(real64), parameter :: gsw_error_limit = 0.02_real64
        character(len=*), parameter :: func_name = "gsw_fdelta"

        saar = gsw_saar(p, long, lat)

        if (saar > gsw_error_limit) then
            fdelta = gsw_error_code(1, func_name)
        else
            fdelta = ((1.0_real64 + 0.35_real64) * saar) / (1.0_real64 - 0.35_real64 * saar)
        end if
    end function gsw_fdelta

    real(real64) function gsw_saar(p, long, lat)
        real(real64), intent(in) :: p, long, lat
        gsw_saar = 0.01_real64  ! Dummy value for demonstration
    end function gsw_saar

    real(real64) function gsw_error_code(code, func_name)
        integer, intent(in) :: code
        character(len=*), intent(in) :: func_name
        print *, "Error in function ", trim(func_name), ": code ", code
        gsw_error_code = -9999.0_real64  ! Dummy error value for demonstration
    end function gsw_error_code

end program test_gsw_fdelta