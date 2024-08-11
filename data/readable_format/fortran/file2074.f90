program test_copy
    implicit none
    character(len=10) :: digit_string = '123456789'
    character(len=1) :: digit_arr(10), expected_arr(10)
    integer :: i
    logical :: test_passed

    ! Prepare expected result
    expected_arr = (/ '1', '2', '3', '4', '5', '6', '7', '8', '9', ' ' /)

    ! Perform the operation
    call copy(digit_string, digit_arr)

    ! Check results
    test_passed = .true.
    do i = 1, 9
        if (digit_arr(i) /= expected_arr(i)) then
            test_passed = .false.
            exit
        endif
    enddo

    ! Report results
    if (test_passed) then
        print *, "Test Passed"
    else
        print *, "Test Failed"
    endif

contains
    subroutine copy(in, out)
        character(len=1), intent(in) :: in(10)
        character(len=1), intent(out) :: out(10)
        out(1:10) = in(1:10)
    end subroutine copy
end program test_copy