program testFortranCode
    implicit none
    real :: f(10,10,10,3,4)
    integer, parameter :: upper(5) = ubound(f), lower(5) = lbound(f)
    integer :: varu(5), varl(5)
    logical :: testPassed
    
    varu = ubound(f)
    varl = lbound(f)
    
    testPassed = .true.
    if (any(varu /= upper)) then
        print *, "Test FAILED: Upper bounds mismatch."
        testPassed = .false.
    endif
    if (any(varl /= lower)) then
        print *, "Test FAILED: Lower bounds mismatch."
        testPassed = .false.
    endif
    
    call check(f, upper, lower)
    call check(f, ubound(f), lbound(f))
    
    if (testPassed) then
        print *, "All tests PASSED."
    endif

contains

    subroutine check(f, upper, lower)
        implicit none
        integer :: upper(5), lower(5)
        real :: f(:,:,:,:,:)
        
        if (any(ubound(f) /= upper)) then
            print *, "Test FAILED in check: Upper bounds mismatch."
            stop
        endif
        if (any(lbound(f) /= lower)) then
            print *, "Test FAILED in check: Lower bounds mismatch."
            stop
        endif
        
        print *, "check subroutine PASSED."
    end subroutine check

end program testFortranCode