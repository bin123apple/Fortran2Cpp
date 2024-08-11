program comb_tmplalm_test
    implicit none
    ! Declare types directly in the program
    integer, parameter :: s2_sp = kind(1.0)
    integer, parameter :: s2_spc = kind((1.0,1.0))

    complex(s2_spc) :: result
    real(s2_sp) :: param(1)

    ! Test function
    result = comb_tmplalm_gaussian(2, 0)
    print *, "Test 1 (m=0, no param):", result

    param(1) = 0.1
    result = comb_tmplalm_gaussian(2, 0, param)
    print *, "Test 2 (m=0, with param):", result

contains

    function comb_tmplalm_gaussian(el, m, param) result(val)
        integer, intent(in) :: el, m
        real(s2_sp), intent(in), optional :: param(:)
        complex(s2_spc) :: val

        real(s2_sp) :: sigma = 0.05e0

        if (present(param)) then
            if (size(param) /= 1) then
                call comb_error('comb_tmplalm_gaussian')
            endif
            sigma = param(1)
        endif

        if (m == 0) then
            val = exp(-el*el*sigma*sigma/2e0)
        else
            val = cmplx(0, 0, s2_spc)
        endif
    end function comb_tmplalm_gaussian

    subroutine comb_error(function_name)
        character(len=*), intent(in) :: function_name
        write(*,*) "Error in", trim(function_name), ": Invalid parameter size."
        stop
    end subroutine comb_error

end program comb_tmplalm_test