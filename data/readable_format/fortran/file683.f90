program taylor_converge
    implicit none
    real(kind=8) :: x, exp_true, y, relative_error
    integer :: nmax, nterms, j

    ! Main calculation and display loop
    nmax = 100
    print *, "     x         true              approximate          error         nterms"
    do j = -20, 20, 4
        x = real(j, kind=8)
        call exptaylor(x, nmax, y, nterms)
        exp_true = exp(x)
        relative_error = abs(y - exp_true) / exp_true
        print '(f10.3,3E19.10,i6)', x, exp_true, y, relative_error, nterms
    end do

    ! Call the unit test subroutine
    call unit_test()
end program taylor_converge

subroutine exptaylor(x, nmax, y, nterms)
    implicit none
    real(kind=8), intent(in) :: x
    integer, intent(in) :: nmax
    real(kind=8), intent(out) :: y
    integer, intent(out) :: nterms
    real(kind=8) :: term, partial_sum
    integer :: j

    term = 1.0
    partial_sum = term

    do j = 1, nmax
        term = term * x / real(j, kind=8)
        partial_sum = partial_sum + term
        if (abs(term) < 1.0d-16 * partial_sum) exit
    end do
    nterms = j
    y = partial_sum
end subroutine exptaylor

subroutine unit_test()
    implicit none
    real(kind=8) :: test_values(3) = [0.0d0, 1.0d0, -1.0d0]
    real(kind=8) :: expected_results(3) = [1.0d0, exp(1.0d0), exp(-1.0d0)]
    real(kind=8) :: y, tolerance
    integer :: nmax, nterms, i

    nmax = 100
    tolerance = 1.e-8

    print *, "Running unit tests..."
    do i = 1, 3
        call exptaylor(test_values(i), nmax, y, nterms)
        if (abs(y - expected_results(i)) > tolerance) then
            print *, "Test failed for x =", test_values(i)
            print *, "Expected:", expected_results(i), "Got:", y
        else
            print *, "Test passed for x =", test_values(i)
        end if
    end do
end subroutine unit_test