! single_file_example.f90
program main
    implicit none
    integer :: i
    integer :: test_i

    ! Equivalent of module variable initialization
    i = 0

    ! Test functionality
    call set_i(5)
    test_i = get_i()

    if (test_i == 5) then
        print *, "Test Passed: i is 5"
    else
        print *, "Test Failed: i is not 5"
    end if

contains

    subroutine set_i(val)
        integer, intent(in) :: val
        i = val
    end subroutine set_i

    function get_i() result(res)
        integer :: res
        res = i
    end function get_i
    
end program main