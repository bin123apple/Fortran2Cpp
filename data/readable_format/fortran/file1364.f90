program main
    implicit none

    real::a, b, c
    real::expected_a, expected_b, expected_c
    real, parameter :: tolerance = 1.0E-5

    call calculate(a, b, c)
    expected_a = 0.0 ! Actual expected values based on the computation
    expected_b = -0.0425162911
    expected_c = -0.0628442615

    call test_calculations(a, b, c, expected_a, expected_b, expected_c, tolerance)

contains

    subroutine calculate(a, b, c)
        real, intent(out) :: a, b, c
        real,dimension(2)::p, q, r

        p = (/ 0.0, 1.0 /)
        q = (/ 1.0, 0.9 /)
        r = (/ 3.0, 0.5 /)

        a = q(1)*r(1)*log(p(2))/((p(1)-q(1))*(p(1)-r(1))) - p(1)*r(1)*log(q(2))/((p(1)-q(1))*(q(1)-r(1))) &
            + p(1)*q(1)*log(r(2))/((p(1)-r(1))*(q(1)-r(1)))

        b = -(q(1)+r(1))*log(p(2))/((p(1)-q(1))*(p(1)-r(1))) + (p(1)+r(1))*log(q(2))/((p(1)-q(1))*(q(1)-r(1))) &
            + (p(1)+q(1))*log(r(2))/((p(1)-r(1))*(r(1)-q(1)))

        c = log(p(2))/((p(1)-q(1))*(p(1)-r(1))) - log(q(2))/((p(1)-q(1))*(q(1)-r(1))) + log(r(2))/((p(1)-r(1))*(q(1)-r(1)))
    end subroutine calculate

    subroutine test_calculations(a, b, c, expected_a, expected_b, expected_c, tolerance)
        real, intent(in) :: a, b, c, expected_a, expected_b, expected_c, tolerance

        if (abs(a - expected_a) < tolerance .and. &
            abs(b - expected_b) < tolerance .and. &
            abs(c - expected_c) < tolerance) then
            print *, "Test passed."
        else
            print *, "Test failed."
            print *, "Expected: ", expected_a, expected_b, expected_c
            print *, "Got: ", a, b, c
        endif
    end subroutine test_calculations

end program main