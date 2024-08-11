program test_fortran_code
    implicit none
    integer :: x
    integer :: expected_value
    logical :: test_passed

    x = 5 ! Initialize x

    ! Expected value
    expected_value = 5

    ! Check if the actual value matches the expected value
    test_passed = (x == expected_value)

    if (test_passed) then
        print *, "Fortran test passed."
    else
        print *, "Fortran test failed."
    end if
end program test_fortran_code