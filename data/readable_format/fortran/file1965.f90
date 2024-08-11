! rk4_corrected.f90
MODULE rk4_module
    IMPLICIT NONE
CONTAINS
    FUNCTION RK4_INT(RHSInit, dTime) RESULT(integrationResult)
        REAL*8, INTENT(IN) :: RHSInit, dTime
        REAL*8 :: integrationResult
        REAL*8 :: k1, k2, k3, k4

        k1 = RHSInit
        k2 = RHSInit + (dTime / 2.0d0) * k1
        k3 = RHSInit + (dTime / 2.0d0) * k2
        k4 = RHSInit + dTime * k3

        integrationResult = RHSInit + (dTime / 6.0d0) * (k1 + 2.0d0 * k2 + 2.0d0 * k3 + k4)
    END FUNCTION RK4_INT
END MODULE rk4_module

PROGRAM TestRK4
    USE rk4_module
    IMPLICIT NONE
    REAL*8 :: result

    result = RK4_INT(1.0d0, 0.1d0)
    PRINT *, 'Fortran Test Result: ', result
END PROGRAM TestRK4