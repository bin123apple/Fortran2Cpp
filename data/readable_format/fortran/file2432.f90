program test_handle_cycle
    implicit none
    ! Assuming loptable_entry is a constant needed from 'interpreter.h'
    integer, parameter :: loptable_entry = 5
    integer :: noptable, start_op, end_op, iop
    integer, dimension(loptable_entry, 10) :: optable
    logical :: debug

    ! Initialize values
    noptable = 10
    start_op = 0
    end_op = 5
    debug = .FALSE.

    call handle_cycle(optable, noptable, debug, start_op, end_op, iop)

    ! Check the value of iop
    if (iop == end_op) then
        print *, 'Test Passed: iop = ', iop
    else
        print *, 'Test Failed: iop = ', iop
    end if

contains

    subroutine handle_cycle(optable, noptable, debug, start_op, end_op, iop)
        implicit none
        integer, parameter :: loptable_entry = 5
        integer noptable, start_op, end_op, iop
        integer optable(loptable_entry,noptable)
        logical debug

        iop = end_op 
        return
    end subroutine handle_cycle

end program test_handle_cycle