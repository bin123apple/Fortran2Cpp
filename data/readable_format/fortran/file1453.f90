program test_program
    implicit none

    ! Call the subroutine that mimics the original program's behavior
    call testPrintMessage()

contains

    subroutine testPrintMessage()
        print *, 'Testing printMessage:'
        call printMessage()
        print *, 'Test should print OK above this line.'
    end subroutine testPrintMessage

    subroutine printMessage()
        ! This subroutine mimics the original program's functionality
        print *, 'ok'
    end subroutine printMessage

end program test_program