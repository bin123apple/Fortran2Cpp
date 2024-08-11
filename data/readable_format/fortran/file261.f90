program test_subroutines
    implicit none
    integer :: iarg
    character(len=20) :: arg

    if (command_argument_count() .ne. 1) then
        print *, "Usage: program <test_number>"
        stop 1
    endif

    call get_command_argument(1, arg)
    read(arg, *) iarg

    select case(iarg)
    case(1)
        call a1
    case(2)
        call a2
    case(3)
        call a3
    case(4)
        call a4
    case(5)
        call a5
    case default
        print *, "Invalid test number"
        stop 1
    end select
contains
    subroutine a1
        integer, parameter :: i = -1
        stop i
    end subroutine a1

    subroutine a2
        stop -2
    end subroutine a2

    subroutine a3
        integer, parameter :: i = 3
        stop i
    end subroutine a3

    subroutine a4
        stop 4
    end subroutine a4

    subroutine a5
        stop merge(5, 6, .true.)
    end subroutine a5

end program test_subroutines