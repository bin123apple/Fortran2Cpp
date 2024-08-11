program test_integer
    implicit none
    integer :: i = 5

    ! Test the value of i
    if (i == 5) then
        print *, 'Test passed: i equals 5'
    else
        print *, 'Test failed: i does not equal 5'
    end if
end program test_integer