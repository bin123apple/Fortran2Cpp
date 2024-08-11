program test_dynamic
    implicit none
    integer, dimension(:), allocatable :: x
    allocate(x(1))
    x(1) = 123 ! Explicitly assigning a value for testing
    
    ! Test condition
    if (x(1) == 123) then
        print *, "Test passed: x(1) is correctly assigned."
    else
        print *, "Test failed: incorrect assignment."
    end if
    
    deallocate(x)
end program test_dynamic