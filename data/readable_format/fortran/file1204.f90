program test_ffunction
    implicit none
    real :: a, b
    
    call ffunction(a, b)
    
    if (a == 3.0 .and. b == 4.0) then
        print *, 'Test passed: a = ', a, ', b = ', b
    else
        print *, 'Test failed: a = ', a, ', b = ', b
    endif
end program test_ffunction

subroutine ffunction(a, b)
    real, intent(out) :: a, b
    a = 3.0
    b = 4.0
end subroutine ffunction