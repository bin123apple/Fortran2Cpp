module output_files_mod
    implicit none
    integer, parameter :: MAX_OUTPUT_FILES = 10
end module output_files_mod

module close_unit_mod
    use output_files_mod, only: MAX_OUTPUT_FILES
    implicit none
    integer :: close_call_count = 0
    integer, dimension(:), allocatable :: close_units

contains
    subroutine ofh__close_unit(unit)
        integer, intent(in) :: unit
        close_call_count = close_call_count + 1
        if (.not. allocated(close_units)) then
            allocate(close_units(MAX_OUTPUT_FILES))
        endif
        close_units(close_call_count) = unit
    end subroutine ofh__close_unit

    subroutine ofh__close_all_units
        integer :: j
        do j = 2, MAX_OUTPUT_FILES
            call ofh__close_unit(j)
        end do
    end subroutine ofh__close_all_units
end module close_unit_mod

program test_close_all_units
    use close_unit_mod, only: ofh__close_unit, ofh__close_all_units, &
                             close_call_count, close_units
    use output_files_mod, only: MAX_OUTPUT_FILES
    implicit none
    integer :: i

    call ofh__close_all_units()
    
    if (close_call_count == MAX_OUTPUT_FILES - 1) then
        print *, "PASS: Correct number of close calls."
    else
        print *, "FAIL: Incorrect number of close calls.", "Expected:", MAX_OUTPUT_FILES - 1, "Got:", close_call_count
    endif
    
    do i = 1, close_call_count
        if (close_units(i) /= i + 1) then
            print *, "FAIL: Incorrect unit closed at call", i, "Expected", i + 1, "Got", close_units(i)
        else
            print *, "PASS: Correct unit closed at call", i
        endif
    enddo
    
end program test_close_all_units