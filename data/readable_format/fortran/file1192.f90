program test
    implicit none
    integer :: n
    real, dimension(2) :: a = (/ ( (float(n))**(1.0), n=1,2) /)
    logical :: test_passed

    test_passed = .not. any(a .ne. (/ ( (float(n))**(1.0), n=1,2) /))
    
    if (test_passed) then
        print *, "Test Passed."
    else
        print *, "Test Failed."
        call abort
    end if
end program test