! combined_program_and_tests.f90
program combined
    implicit none
    integer :: a(3)
    integer :: i
    logical :: test_passed

    ! Test function huj (originally in huj_mod module)
    a = huj()
    if (.not. all(a == (/1, 2, 3/))) call abort()

    ! Test function hoj
    a = hoj()
    if (.not. all(a == (/1, 2, 3/))) call abort()

    ! Test for huj() function
    a = huj()
    test_passed = .true.
    do i = 1, 3
        if (a(i) /= i) then
            test_passed = .false.
            exit
        endif
    end do
    if (test_passed) then
        print *, "huj() test passed."
    else
        print *, "huj() test failed."
    endif

    ! Test for hoj() function
    a = hoj()
    test_passed = .true.
    do i = 1, 3
        if (a(i) /= i) then
            test_passed = .false.
            exit
        endif
    end do
    if (test_passed) then
        print *, "hoj() test passed."
    else
        print *, "hoj() test failed."
    endif

contains
    ! Functions originally in the huj_mod module and the global scope
    pure function huj() result(res)
        integer :: res(3)
        res = (/1, 2, 3/)
    end function huj

    pure function hoj() result(res)
        integer :: res(3)
        res = (/1, 2, 3/)
    end function hoj

end program combined