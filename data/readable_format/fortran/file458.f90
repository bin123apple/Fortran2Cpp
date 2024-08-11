program nested_where_with_test
    implicit none
    integer, parameter :: n = 4
    integer :: a(n)
    integer :: expected(n)
    logical :: mask1(n) = (/.TRUE., .TRUE., .FALSE., .FALSE./)
    logical :: mask2(n) = (/.TRUE., .FALSE., .TRUE., .FALSE./)

    call compute_values(a, mask1, mask2, n)
    call print_array(a, n)
    
    ! Set expected values for testing
    expected = (/1, 2, 3, 4/)
    call test_values(a, expected, n)
    
contains

    subroutine compute_values(a, mask1, mask2, n)
        integer, intent(in) :: n
        integer, intent(out) :: a(n)
        logical, intent(in) :: mask1(n), mask2(n)
        integer :: i

        do i = 1, n
            if (mask1(i)) then
                if (mask2(i)) then
                    a(i) = 1
                else
                    a(i) = 2
                end if
            else
                if (mask2(i)) then
                    a(i) = 3
                else
                    a(i) = 4
                end if
            end if
        end do
    end subroutine compute_values

    subroutine print_array(a, n)
        integer, intent(in) :: n
        integer, intent(in) :: a(n)
        
        print *, a
    end subroutine print_array

    subroutine test_values(a, expected, n)
        integer, intent(in) :: n
        integer, intent(in) :: a(n), expected(n)
        integer :: i
        logical :: test_passed
        test_passed = .TRUE.

        do i = 1, n
            if (a(i) /= expected(i)) then
                print *, "Test failed at index", i, "Expected:", expected(i), "Got:", a(i)
                test_passed = .FALSE.
            end if
        end do
        
        if (test_passed) then
            print *, "All tests passed!"
        end if
    end subroutine test_values

end program nested_where_with_test