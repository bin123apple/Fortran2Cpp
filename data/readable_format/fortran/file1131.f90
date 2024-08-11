module auxiliary_routines_mod
    implicit none
contains

    function get_least_common_multiple(a, b) result(return_value)
        integer, intent(in) :: a, b
        integer :: return_value
        integer :: i, j, jnew
        i = a
        j = b
        do while (j /= 0)
            jnew = mod(i, j)
            i = j
            j = jnew
        end do
        return_value = (a * b) / i
    end function get_least_common_multiple

    function fft_consistent(inc, jump, n, lot) result(is_consistent)
        integer, intent(in) :: inc, jump, n, lot
        logical :: is_consistent
        integer :: lcm
        lcm = get_least_common_multiple(inc, jump)
        if (lcm <= (n - 1) * inc .and. lcm <= (lot - 1) * jump) then
            is_consistent = .false.
        else
            is_consistent = .true.
        endif
    end function fft_consistent

    subroutine fft_error_handler(info, subroutine_name)
        integer, intent(in) :: info
        character(len=*), intent(in) :: subroutine_name
        select case (info)
            case (-1)
                write(*,*) "On entry to ", trim(subroutine_name), " parameters lot, jump, n and inc are inconsistent."
            case (-2)
                write(*,*) "On ntry to ", trim(subroutine_name), " parameter l is greater than ldim."
            case (-3)
                write(*,*) "On entry to ", trim(subroutine_name), " parameter m is greater than mdim."
            case (-5)
                write(*,*) "Within ", trim(subroutine_name), " input error returned by lower level routine."
            case (-6)
                write(*,*) "On entry to ", trim(subroutine_name), " parameter ldim is less than 2*(l/2+1)."
            case default
                write(*,*) "On entry to ", trim(subroutine_name), " parameter number ", info, " had an illegal value."
        end select
    end subroutine fft_error_handler

end module auxiliary_routines_mod

program testAuxiliaryRoutines
    use auxiliary_routines_mod
    implicit none

    ! Tests for get_least_common_multiple
    write(*,*) "Testing get_least_common_multiple..."
    if (get_least_common_multiple(6, 8) == 24) then
        write(*,*) "PASS"
    else
        write(*,*) "FAIL"
    end if

    ! Tests for fft_consistent
    write(*,*) "Testing fft_consistent..."
    if (.not. fft_consistent(1, 1, 10, 10)) then
        write(*,*) "PASS"
    else
        write(*,*) "FAIL"
    end if

    ! Example to trigger fft_error_handler
    write(*,*) "Testing fft_error_handler with info = -1..."
    call fft_error_handler(-1, "TestSubroutine")

end program testAuxiliaryRoutines