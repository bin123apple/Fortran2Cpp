program test
    implicit none
    character(len=2) wbuf1
    character(len=2), dimension(2) :: wbuf2 = ['AB', 'CD']
    wbuf1 = wbuf2(1)
    call testCopy(wbuf1, wbuf2(1))
contains
    subroutine testCopy(result, expected)
        character(len=2), intent(in) :: result, expected
        if (result == expected) then
            print *, "Test passed: ", result, " equals ", expected
        else
            print *, "Test failed: ", result, " does not equal ", expected
        end if
    end subroutine testCopy
end program test