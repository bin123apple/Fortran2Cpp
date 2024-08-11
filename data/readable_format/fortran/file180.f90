program sub2_test
    implicit none
    real(kind=8), dimension(3) :: y, z, expected_z
    integer :: n, i
    logical :: test_passed

    y = (/2.0, 3.0, 7.0/)
    expected_z = (/4.0, 9.0, 49.0/)
    n = size(y)

    call fsub(y, n, z)

    test_passed = .true.
    do i = 1, n
        if (z(i) /= expected_z(i)) then
            test_passed = .false.
            exit
        endif
    end do

    if (test_passed) then
        print *, "Test Passed."
    else
        print *, "Test Failed."
    endif
end program sub2_test

subroutine fsub(x, n, f)
    implicit none
    integer, intent(in) :: n
    real(kind=8), dimension(n), intent(in) :: x
    real(kind=8), dimension(n), intent(out) :: f

    f = x**2
end subroutine fsub