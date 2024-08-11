program test_fortran_code
    implicit none

    integer :: x = 5

    ! Check if x is equal to 5
    if (x /= 5) then
        print *, 'Test failed: x is not equal to 5'
        stop 1
    else
        print *, 'Test passed: x is equal to 5'
    end if
end program test_fortran_code