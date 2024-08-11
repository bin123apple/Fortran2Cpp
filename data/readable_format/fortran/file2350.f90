PROGRAM test_dznrm2
    IMPLICIT NONE
    INTEGER :: N, INCX
    COMPLEX*16 :: X(3)
    DOUBLE PRECISION :: RESULT
    
    INTERFACE
        DOUBLE PRECISION FUNCTION DZNRM2(N, X, INCX)
            INTEGER, INTENT(IN) :: N, INCX
            COMPLEX*16, INTENT(IN) :: X(*)
        END FUNCTION DZNRM2
    END INTERFACE
    
    ! Test data
    N = 3
    INCX = 1
    X(1) = (1.0D+0, 2.0D+0)
    X(2) = (3.0D+0, 4.0D+0)
    X(3) = (5.0D+0, 6.0D+0)

    ! Call the function and print the result
    RESULT = DZNRM2(N, X, INCX)
    PRINT *, 'Result:', RESULT
END PROGRAM test_dznrm2

DOUBLE PRECISION FUNCTION DZNRM2(N, X, INCX)
    INTEGER, INTENT(IN) :: N, INCX
    COMPLEX*16, INTENT(IN) :: X(*)
    DOUBLE PRECISION :: ONE, ZERO
    PARAMETER (ONE = 1.0D+0, ZERO = 0.0D+0)
    DOUBLE PRECISION :: NORM, SCALE, SSQ, TEMP
    INTEGER :: IX
    IF (N.LT.1 .OR. INCX.LT.1) THEN
        NORM = ZERO
    ELSE
        SCALE = ZERO
        SSQ = ONE
        DO IX = 1, 1 + (N-1)*INCX, INCX
            IF (DBLE(X(IX)).NE.ZERO) THEN
                TEMP = ABS(DBLE(X(IX)))
                IF (SCALE.LT.TEMP) THEN
                    SSQ = ONE + SSQ * (SCALE/TEMP)**2
                    SCALE = TEMP
                ELSE
                    SSQ = SSQ + (TEMP/SCALE)**2
                END IF
            END IF
            IF (DIMAG(X(IX)).NE.ZERO) THEN
                TEMP = ABS(DIMAG(X(IX)))
                IF (SCALE.LT.TEMP) THEN
                    SSQ = ONE + SSQ * (SCALE/TEMP)**2
                    SCALE = TEMP
                ELSE
                    SSQ = SSQ + (TEMP/SCALE)**2
                END IF
            END IF
        END DO
        NORM = SCALE*SQRT(SSQ)
    END IF
    DZNRM2 = NORM
END FUNCTION DZNRM2