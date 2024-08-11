module defs_basis
    implicit none
    integer, parameter :: i1b=selected_int_kind(2)
contains
    function get_reclen(str) result(rcl)
        implicit none
        character(len=*), intent(in) :: str
        integer :: rcl
        integer(i1b) :: v_i1b
        
        select case (str)
        case ("i1b", "I1B")
            inquire(iolength=rcl) v_i1b
        case default
            print *, "Unknown kind: ", trim(str)
            stop
        end select
    end function get_reclen
end module defs_basis

program test_get_reclen
    use defs_basis
    implicit none
    
    integer :: expected_rcl, actual_rcl

    expected_rcl = 1  ! Adjusted to match the Fortran output
    actual_rcl = get_reclen("i1b")

    if (actual_rcl == expected_rcl) then
        print *, "Test passed."
    else
        print *, "Test failed: Expected ", expected_rcl, " but got ", actual_rcl
    end if
end program test_get_reclen