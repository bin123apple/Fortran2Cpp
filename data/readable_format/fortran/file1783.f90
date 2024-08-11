program main
    implicit none
    call testHelloWorld()
contains

    subroutine checkHelloWorld(c, result)
        implicit none
        character(len=*), intent(in) :: c
        integer, intent(out) :: result
        character(len=40) :: expectedString
        
        expectedString = "Hello, world!"
        if (c .ne. expectedString) then
            result = 1
        else
            result = 0
        endif
    end subroutine checkHelloWorld

    subroutine testHelloWorld()
        implicit none
        integer :: result
        call checkHelloWorld("Hello, world!", result)
        if (result .eq. 1) then
            print *, "Test failed!"
        else
            print *, "Test passed!"
        endif
    end subroutine testHelloWorld

end program main