program test_transfer
    implicit none

    ! Original code goes here...
    ! (Omitting for brevity since the focus is on the testing approach)

    ! Test cases
    call test_transfer_operations()

contains

    subroutine test_transfer_operations()
        implicit none

        integer, parameter :: ip1 = 42
        integer :: ip2, i
        logical :: b

        ! Test 1: Transfer int to bool and back
        ip2 = transfer(transfer(ip1, .true.), 0)
        if (ip2 /= ip1) then
            print *, 'Test 1 failed.'
        else
            print *, 'Test 1 passed.'
        endif

        ! Additional tests follow a similar structure...
        ! Focusing on the key functionalities demonstrated in the original code.

    end subroutine test_transfer_operations

end program test_transfer