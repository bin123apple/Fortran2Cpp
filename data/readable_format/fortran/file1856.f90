program test_conditions
    ! Simulated conditions for testing purposes
    integer :: file_storage_size = 8
    integer :: character_storage_size = 8
    integer, dimension(5) :: numeric_storage_size = [8, 16, 32, 64, 128]
    integer :: iostat_end = -1
    integer :: iostat_eor = -2
    logical :: is_valid

    ! Check conditions
    is_valid = .true.
    if (file_storage_size /= 8) is_valid = .false.
    if (character_storage_size /= 8) is_valid = .false.
    if (all(numeric_storage_size /= [8, 16, 32, 64, 128])) is_valid = .false.
    if (iostat_end /= -1) is_valid = .false.
    if (iostat_eor /= -2) is_valid = .false.

    ! Output result based on the checks
    if (.not. is_valid) then
        print *, "Test failed: A condition was not met."
    else
        print *, "All checks passed successfully."
    endif
end program test_conditions