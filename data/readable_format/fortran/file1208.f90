! main.f90
program test_sign_function
    implicit none
    ! Test cases
    call test_sign(2, 3, 2)
    call test_sign(4, -5, -4)
    call test_sign(-6, 7, 6)
    call test_sign(-8, -9, -8)
    call test_sign_real(1.0, 2.0, 1.0)
    call test_sign_real(1.0, -2.0, -1.0)
    call test_sign_real(1.0, 0.0, 1.0)
    call test_sign_real(1.0, -0.0, -1.0) ! Adjusted for Fortran behavior
end program test_sign_function

subroutine test_sign(a, b, expected)
    integer, intent(in) :: a, b, expected
    if (sign(a, b) /= expected) then
        print *, 'Failed test for sign(', a, ',', b, '). Expected', expected, ', got', sign(a, b)
        stop
    end if
    print *, 'Test passed for sign(', a, ',', b, ').'
end subroutine test_sign

subroutine test_sign_real(a, b, expected)
    real, intent(in) :: a, b, expected
    if (sign(a, b) /= expected) then
        print *, 'Failed test for sign(', a, ',', b, '). Expected', expected, ', got', sign(a, b)
        stop
    end if
    print *, 'Test passed for sign(', a, ',', b, ').'
end subroutine test_sign_real