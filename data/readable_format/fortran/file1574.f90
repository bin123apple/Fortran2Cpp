program test_pd_example
    implicit none
    integer, dimension(1:12) :: C
    integer :: i, errors

    ! Expected operation from pd_example
    C = (/ (I+1, I = 1, 12) /)
    errors = 0

    ! Test
    do i = 1, 12
        if (C(i) /= i + 1) then
            print *, "Test failed for element:", i, "Expected:", i + 1, "Got:", C(i)
            errors = errors + 1
        end if
    end do

    if (errors == 0) then
        print *, "All tests passed."
    else
        print *, errors, " test(s) failed."
    end if

end program test_pd_example