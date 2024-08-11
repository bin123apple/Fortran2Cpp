program main
    integer :: i = 1
    integer :: test_result

    if (i > 0) then
        i = 2
    else if (i > 10) then
        i = 3
    else
        i = 4
    endif

    ! Unit test to check the value of i
    if (i == 2) then
        test_result = 1  ! Test passed
    else
        test_result = 0  ! Test failed
    endif

    print *, 'Test result: ', test_result
end program main