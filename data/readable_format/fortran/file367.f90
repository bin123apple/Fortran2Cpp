PROGRAM ezcu_test_fortran
    IMPLICIT NONE
    CALL handler_start()
    CALL base_test()
    CALL dev_test()
    CALL mem_test()
    CALL knl_test()
    CALL handler_end()
    CALL handler_stat()
END PROGRAM ezcu_test_fortran

SUBROUTINE handler_start()
    PRINT *, "Handler start."
END SUBROUTINE handler_start

SUBROUTINE base_test()
    PRINT *, "Base test."
END SUBROUTINE base_test

SUBROUTINE dev_test()
    PRINT *, "Device test."
END SUBROUTINE dev_test

SUBROUTINE mem_test()
    PRINT *, "Memory test."
END SUBROUTINE mem_test

SUBROUTINE knl_test()
    PRINT *, "Kernel test."
END SUBROUTINE knl_test

SUBROUTINE handler_end()
    PRINT *, "Handler end."
END SUBROUTINE handler_end

SUBROUTINE handler_stat()
    PRINT *, "Handler statistics."
END SUBROUTINE handler_stat