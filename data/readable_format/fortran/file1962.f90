program test
    implicit none
    integer :: ans_val
    integer, parameter :: test_array(5) = [1, 2, 3, 4, 5]
    integer :: expected_xor
    integer :: i

    ! Calculate expected XOR result manually or using a calculator.
    expected_xor = 1
    do i = 2, 5
        expected_xor = ieor(expected_xor, test_array(i))
    end do

    ! Perform XOR in the same way as the main program does.
    ans_val = 0
    do i = 1, 5
        ans_val = ieor(ans_val, test_array(i))
    end do

    ! Check if the results match.
    if (ans_val == expected_xor) then
        write(*,*) "Test PASS"
    else
        write(*,*) "Test FAIL"
    endif
end program test