module lib
    integer :: var_i = 1
contains
    subroutine lib_func
        if (var_i /= 1) then
            print *, "lib_func aborting: var_i is not 1"
            stop
        end if
        var_i = 2
    end subroutine lib_func
end module lib

module libmany
    integer :: var_j = 3
    integer :: var_k = 4
end module libmany

program test_lib
    use lib
    use libmany
    implicit none

    call test_initial_values()
    call test_lib_func()
    call print_vars()

contains
    subroutine test_initial_values
        if (var_i == 1) then
            print *, "Test Passed: Initial value of var_i is correct."
        else
            print *, "Test Failed: Initial value of var_i is incorrect."
        end if

        if (var_j == 3) then
            print *, "Test Passed: Initial value of var_j is correct."
        else
            print *, "Test Failed: Initial value of var_j is incorrect."
        end if

        if (var_k == 4) then
            print *, "Test Passed: Initial value of var_k is correct."
        else
            print *, "Test Failed: Initial value of var_k is incorrect."
        end if
    end subroutine test_initial_values

    subroutine test_lib_func
        call lib_func()
        if (var_i == 2) then
            print *, "Test Passed: lib_func correctly updated var_i to 2."
        else
            print *, "Test Failed: lib_func did not correctly update var_i."
        end if
    end subroutine test_lib_func

    subroutine print_vars
        print *, "After tests, var_i:", var_i
        print *, "var_j:", var_j
        print *, "var_k:", var_k
    end subroutine print_vars
end program test_lib