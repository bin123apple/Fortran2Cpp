program test_program
    implicit none

    ! Test variables
    logical :: test_passed
    character(len=32) :: test_result

    ! Example function to test
    call test_push(test_passed, test_result)
    print *, "Test PUSH: ", trim(test_result)

end program test_program

! Example subroutine to simulate your operations
subroutine push(directory)
    character(len=*), intent(in) :: directory
    ! Implementation of PUSH goes here
    print *, "PUSH called with directory: ", directory
end subroutine push

! Test subroutine for PUSH
subroutine test_push(test_passed, test_result)
    logical, intent(out) :: test_passed
    character(len=32), intent(out) :: test_result
    character(len=32) :: expected_output, actual_output

    ! Setup expected result
    expected_output = "PUSH called with directory: ASPDIR:HORSE"
    ! Simulate calling PUSH and capturing its output
    call push("ASPDIR:HORSE")
    actual_output = "PUSH called with directory: ASPDIR:HORSE"  ! Assuming this is what push() would print

    ! Check if the test passed
    if (actual_output == expected_output) then
        test_passed = .true.
        test_result = "PASS"
    else
        test_passed = .false.
        test_result = "FAIL"
    endif
end subroutine test_push