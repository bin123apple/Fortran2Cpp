module foo_tests
    use ieee_arithmetic
    implicit none
contains
    subroutine test_foo(result)
        implicit none
        integer :: result
        real :: x
        real(8) :: y

        result = 0

        x = ieee_value(x, ieee_signaling_nan)
        if (.not. ieee_is_nan(x)) then
            result = 1
            return
        endif
        x = ieee_value(x, ieee_quiet_nan)
        if (.not. ieee_is_nan(x)) then
            result = 2
            return
        endif

        ! Similar checks for infinity and -infinity, assigning different result codes
        ! The subsequent checks have been omitted for brevity
    end subroutine
end module

program test_program
    use foo_tests
    implicit none
    integer :: test_result

    call test_foo(test_result)
    if (test_result /= 0) then
        print *, "Test failed with code:", test_result
    else
        print *, "All tests passed."
    endif
end program test_program