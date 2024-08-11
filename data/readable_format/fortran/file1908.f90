module test_utilities
    implicit none
contains
    subroutine check(condition, message)
        logical, intent(in) :: condition
        character(len=*), intent(in) :: message
        if (.not. condition) then
            print *, "Test failed:", trim(message)
            stop 1
        else
            print *, "Test passed:", trim(message)
        end if
    end subroutine check
end module test_utilities

program test_chk_alloc_string
    use test_utilities
    implicit none

    character(len=20) :: buffer
    character(len=:), allocatable :: test_strings(:)
    integer :: i

    ! Allocate and initialize the strings
    allocate(character(len=10) :: test_strings(5))
    test_strings = ["A   ", "C   ", "ABCD", "V   ", "zzzz"]

    ! Size check
    call check(size(test_strings) == 5, "Size after allocation")

    ! Content checks
    call check(trim(test_strings(1)) == "A", "Content check at position 1")
    call check(trim(test_strings(2)) == "C", "Content check at position 2")
    call check(trim(test_strings(3)) == "ABCD", "Content check at position 3")
    call check(trim(test_strings(4)) == "V", "Content check at position 4")
    call check(trim(test_strings(5)) == "zzzz", "Content check at position 5")

    ! Formatted output check
    write(buffer, "(5a4)") test_strings
    call check(trim(buffer) == "A   C   ABCDV   zzzz", "Formatted output check")

end program test_chk_alloc_string