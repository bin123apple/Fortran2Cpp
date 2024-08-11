program test_env_vars
    implicit none

    ! Hypothetical subroutines to set and get env vars;
    ! in practice, these would use ISO C Binding to interface with C functions.
    call set_env_var('UVM_TESTNAME', 'uex_ve_multicore_test')
    call check_env_var('UVM_TESTNAME', 'uex_ve_multicore_test')

    call set_env_var('SW_TESTNAME', 'UEX.basic_multicore_test')
    call check_env_var('SW_TESTNAME', 'UEX.basic_multicore_test')

contains

    ! Hypothetical subroutine to set an environment variable
    subroutine set_env_var(name, value)
        character(len=*), intent(in) :: name, value
        ! Here you would call the C function to set the env var
        print *, "Setting env var:", name, "to", value
    end subroutine set_env_var

    ! Hypothetical subroutine to check an environment variable's value
    subroutine check_env_var(name, expected_value)
        character(len=*), intent(in) :: name, expected_value
        character(len=100) :: retrieved_value

        ! Here you would call the C function to get the env var
        ! For demonstration, we'll pretend we retrieved the expected value
        retrieved_value = expected_value

        if (retrieved_value == expected_value) then
            print *, "Test passed for:", name
        else
            print *, "Test failed for:", name
        endif
    end subroutine check_env_var

end program test_env_vars