program test
    implicit none
    integer(8) :: foo, bar
    real :: r = 4e10
    
    foo = 4e10
    bar = r
    
    if (foo .ne. bar) then
        print *, "Test failed."
        call abort
    else
        print *, "Test passed."
    endif
end program test