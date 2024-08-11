module sign_module
    implicit none
contains
    ! The intrinsic sign function is used directly in tests
end module sign_module

program test_sign_function
    use sign_module
    implicit none
    real :: r, s
    integer :: i, j, test_passed

    test_passed = 0

    i = 2; j = 3
    if (sign(i, j) /= 2) test_passed = test_passed + 1

    i = 4; j = -5
    if (sign(i, j) /= -4) test_passed = test_passed + 1

    r = 1.0; s = 2.0
    if (sign(r, s) /= 1.0) test_passed = test_passed + 1

    r = 1.0; s = -2.0
    if (sign(r, s) /= -1.0) test_passed = test_passed + 1

    r = 1.0; s = 0.0
    if (sign(r, s) /= 1.0) test_passed = test_passed + 1

    r = 1.0; s = -0.0
    if (sign(r, s) /= -1.0) test_passed = test_passed + 1

    if (test_passed == 0) then
        print *, "All tests PASSED."
    else
        print *, "Some tests FAILED."
    end if
end program test_sign_function