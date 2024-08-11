module rrsw_kg20
    implicit none
    real, dimension(5) :: a = [1.0, 2.0, 3.0, 4.0, 5.0]
    real, dimension(5) :: b = [5.0, 4.0, 3.0, 2.0, 1.0]
contains
    subroutine modify_arrays()
        a(1) = 10.0
        b(1) = 20.0
    end subroutine modify_arrays
end module rrsw_kg20

program test_rrsw_kg20
    use rrsw_kg20
    implicit none

    call modify_arrays()

    ! Test 1: Check if a(1) was modified
    if (a(1) == 10.0) then
        print *, "Test 1 Passed: a(1) was modified correctly."
    else
        print *, "Test 1 Failed: a(1) was not modified as expected."
    endif

    ! Test 2: Check if b(1) was modified
    if (b(1) == 20.0) then
        print *, "Test 2 Passed: b(1) was modified correctly."
    else
        print *, "Test 2 Failed: b(1) was not modified as expected."
    endif
end program test_rrsw_kg20