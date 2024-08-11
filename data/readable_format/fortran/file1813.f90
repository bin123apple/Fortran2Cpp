program test
    implicit none
    external foo, foobar1, foobar2
    common /chrblock/ chr
    character(8) chr

    call foo(foobar1)
    call testChr('foobar1')

    call foo(foobar2)
    call testChr('foobar2')

contains

    subroutine testChr(expected)
        character(8), intent(in) :: expected
        if (chr .ne. expected) then
            print *, 'Test Failed: Expected', expected, 'but got', chr
        else
            print *, 'Test Passed: ', expected
        endif
    end subroutine testChr

end program test

subroutine foobar1
    common /chrblock/ chr
    character(8) :: chr
    chr = 'foobar1'
end subroutine foobar1

subroutine foobar2
    common /chrblock/ chr
    character(8) :: chr
    chr = 'foobar2'
end subroutine foobar2

subroutine foo(fcn)
    external fcn
    call fcn
end subroutine foo