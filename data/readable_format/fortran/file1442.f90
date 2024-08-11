program test
    implicit none
    integer :: p(4) = (/2, 4, 1, 3/)
    integer :: expected_first_pass(4) = (/3, 1, 4, 2/)
    integer :: expected_second_pass(4) = (/1, 2, 3, 4/)
    integer :: i

    ! First transformation
    forall (i = 1:4) p(p(i)) = i
    if (all(p == expected_first_pass)) then
        print *, "First pass test passed."
    else
        print *, "First pass test failed."
        call abort()
    endif

    p = (/2, 4, 1, 3/) ! Reset p for the second transformation

    ! Second transformation
    forall (i = 1:4) p(5 - p(i)) = p(5 - i)
    if (all(p == expected_second_pass)) then
        print *, "Second pass test passed."
    else
        print *, "Second pass test failed."
        call abort()
    endif

end program test