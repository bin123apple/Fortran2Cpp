program test_integer
    implicit none
    integer :: i = 5

    ! Check if i is equal to 5
    if (i /= 5) then
        print *, "Test failed: i is not equal to 5"
    else
        print *, "Test passed: i is equal to 5"
    end if
end program test_integer