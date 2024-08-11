program test_fi_a3
    implicit none
    real(kind=8) :: r(3)
    real(kind=8) :: p(3)
    real(kind=8) :: expected_p(3)
    logical :: test_passed

    ! Sample input
    r = (/ 1.0d0, 2.0d0, 3.0d0 /)

    ! Expected results
    expected_p(1) = 6.0d0
    expected_p(2) = 14.0d0
    expected_p(3) = 36.0d0

    ! Call the subroutine
    call fi_a3(r, p)

    ! Check results
    test_passed = all(abs(p - expected_p) < 1.0d-6)

    if (test_passed) then
        print *, "Test passed."
    else
        print *, "Test failed."
        print *, "Expected:", expected_p
        print *, "Got:", p
    end if

end program test_fi_a3

subroutine fi_a3(r, p)
    implicit none
    real(kind=8), intent(in) :: r(3)
    real(kind=8), intent(out) :: p(3)
    p(1) = r(1) + r(2) + r(3)
    p(2) = r(1)**2 + r(2)**2 + r(3)**2
    p(3) = r(1)**3 + r(2)**3 + r(3)**3
end subroutine fi_a3