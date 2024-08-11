program test_initialization
    implicit none
    real, parameter :: zero = 0.0
    real :: qu, qv

    qu = zero
    qv = zero

    if (qu == zero .and. qv == zero) then
        print *, "Test passed: qu and qv are initialized to zero."
    else
        print *, "Test failed: qu and qv are not correctly initialized."
    endif
end program test_initialization