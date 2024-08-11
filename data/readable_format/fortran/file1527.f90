program test_prog
    implicit none
    integer, parameter :: num = 1

    call testNum()

contains

    subroutine testNum()
        implicit none
        if (num == 1) then
            print *, "Test passed: num is 1"
        else
            print *, "Test failed: num is not 1"
        endif
    end subroutine testNum

end program test_prog