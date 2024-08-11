program test_a1_d1
    implicit none
    integer :: runMode

    ! Assuming runMode is set based on some logic or input
    ! For simplicity, 0 = main, 1 = test
    runMode = 0

    if (runMode == 0) then
        call mainExecution
    else if (runMode == 1) then
        call testExecution
    end if

contains

    subroutine mainExecution
        ! Your main program logic here
    end subroutine mainExecution

    subroutine testExecution
        ! Your test logic here
    end subroutine testExecution

end program test_a1_d1