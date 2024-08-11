program common_block_test
    implicit none
    integer :: a, b, c, d
    integer :: n(4)
    common /block/ a, b, c, d
    equivalence (a, n(1)), (c, n(3))

    ! Initialize variables
    a = 1
    b = 2
    c = 3
    d = 4

    ! Test to verify the expected values
    call test_values()

contains

    subroutine test_values()
        implicit none
        if (n(1) .eq. 1 .and. n(2) .eq. 2 .and. n(3) .eq. 3 .and. n(4) .eq. 4) then
            print *, "Test Passed: Values are as expected."
        else
            print *, "Test Failed: Values are not as expected."
        endif
    end subroutine test_values

end program common_block_test