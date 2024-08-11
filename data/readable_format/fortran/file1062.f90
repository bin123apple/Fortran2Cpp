! testverbatim.F90
PROGRAM testverbatim
! No actual functionality to test since it's a no-op
! But we can demonstrate a structure for testing
#ifdef TEST
CALL test_no_output()
#endif
END PROGRAM testverbatim

SUBROUTINE test_no_output()
    PRINT*, 'Running test_no_output: Expect no other output...'
    ! Normally, we'd check conditions here, but our code is a no-op when the condition is false.
END SUBROUTINE