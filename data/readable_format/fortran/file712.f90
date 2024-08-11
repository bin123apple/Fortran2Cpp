program MainProgram
    use, intrinsic :: iso_fortran_env, only: REAL64
    implicit none
    real(REAL64) :: number, result

    number = 2.0_REAL64
    result = square(number)

    print *, "The square of ", number, " is ", result

contains

    function square(x) result(res)
        real(REAL64), intent(in) :: x
        real(REAL64) :: res

        res = x**2
    end function square

end program MainProgram