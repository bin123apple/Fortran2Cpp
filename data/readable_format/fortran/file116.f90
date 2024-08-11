program test_x
    implicit none
    integer :: x

    x = 5
    
    if (x .eq. 5) then
        print *, "Test passed: x equals 5."
    else
        print *, "Test failed: x does not equal 5."
    end if
end program test_x