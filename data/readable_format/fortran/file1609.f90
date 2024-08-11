program test_kind
    implicit none
    integer,parameter::s4 = selected_int_kind(8)
    integer,parameter::s8 = selected_int_kind(10)
    integer,parameter::k4 = kind(1)
    integer,parameter::k8 = kind(1_8)
    integer,parameter::r8 = kind(1.0D0)
    logical :: test_passed

    test_passed = .TRUE.

    if (kind(0_s4) /= 4) then
        print *, "Test failed: invalid s4"
        test_passed = .FALSE.
    end if
    if (kind(0_s8) /= 8) then
        print *, "Test failed: invalid s8"
        test_passed = .FALSE.
    end if
    if (kind(0_k4) /= 4) then
        print *, "Test failed: invalid k4"
        test_passed = .FALSE.
    end if
    if (kind(0_k8) /= 8) then
        print *, "Test failed: invalid k8"
        test_passed = .FALSE.
    end if
    if (kind(0.0_r8) /= 8) then
        print *, "Test failed: invalid r8"
        test_passed = .FALSE.
    end if

    if (test_passed) then
        print *, "All tests passed."
    end if
end program test_kind