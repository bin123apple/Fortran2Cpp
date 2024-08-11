program test_setprob
    implicit none
    character(len=12) :: fname
    
    ! Call the subroutine to set a value to fname
    call setprob(fname)
    
    ! Check if the value has been set correctly
    if (fname == 'TestFortran') then
        print *, 'Test passed.'
    else
        print *, 'Test failed.'
    endif
end program test_setprob

subroutine setprob(fname)
    implicit none
    character(len=12), intent(out) :: fname
    
    ! Set fname to a specific value
    fname = 'TestFortran'
end subroutine setprob