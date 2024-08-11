program test_random_number
    implicit none
    real :: r(1,5)
    integer :: i
    
    ! Generate Random Numbers
    CALL RANDOM_NUMBER(r)
    
    ! Check each number is within the expected range
    do i = 1, 5
        if (r(1,i) < 0.0 .or. r(1,i) > 1.0) then
            print *, 'Test Failed: Number out of range'
            stop
        endif
    end do
    
    print *, 'All numbers within range. Test Passed.'
end program test_random_number