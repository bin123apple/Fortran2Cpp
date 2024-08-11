program foo_test
    implicit none
    complex(kind=8)      z0, z1, z2
    logical :: test_passed

    test_passed = .TRUE.

    z0 = dcmplx(0.0d0, 0.5d0)
    z1 = 1.0d0 / z0
    if (z1 .ne. dcmplx(0.0d0, -2.0d0)) then
        print *, "Test 1 failed."
        test_passed = .FALSE.
    end if

    z0 = 10.0d0 * z0
    if (z0 .ne. dcmplx(0.0d0, 5.0d0)) then
        print *, "Test 2 failed."
        test_passed = .FALSE.
    end if

    z2 = dcmplx(1.0d0, 2.0d0)
    z1 = z0 / z2
    if (z1 .ne. dcmplx(2.0d0, 1.0d0)) then
        print *, "Test 3 failed."
        test_passed = .FALSE.
    end if

    z1 = z0 * z2
    if (z1 .ne. dcmplx(-10.0d0, 5.0d0)) then
        print *, "Test 4 failed."
        test_passed = .FALSE.
    end if

    if (test_passed) then
        print *, "All tests passed."
    else
        print *, "Some tests failed."
    end if
end program foo_test