PROGRAM test_scnrm2
    IMPLICIT NONE
    INTEGER, PARAMETER :: n = 3
    INTEGER :: incx = 1
    COMPLEX :: x(3)
    REAL :: result

    ! Define a complex array for testing
    x(1) = CMPLX(1.0, 2.0)
    x(2) = CMPLX(-2.0, 1.0)
    x(3) = CMPLX(0.5, -0.5)

    ! Calling the SCNRM2 function
    result = SCNRM2(n, x, incx)

    ! Output the result
    PRINT *, "Norm: ", result

    ! Compare the result with expected value
    IF (ABS(result - 3.201562) < 0.0001) THEN
        PRINT *, "Test passed!"
    ELSE
        PRINT *, "Test failed!"
    END IF

CONTAINS

    REAL FUNCTION SCNRM2(N, X, INCX)
        INTEGER, INTENT(IN) :: N, INCX
        COMPLEX, INTENT(IN) :: X(*)
        REAL :: ONE, ZERO
        PARAMETER (ONE=1.0E+0, ZERO=0.0E+0)
        REAL :: NORM, SCALE, SSQ, TEMP
        INTEGER :: IX

        IF (N .LT. 1 .OR. INCX .LT. 1) THEN
            NORM = ZERO
        ELSE
            SCALE = ZERO
            SSQ = ONE
            DO IX = 1, 1 + (N-1)*INCX, INCX
                IF (REAL(X(IX)) .NE. ZERO) THEN
                    TEMP = ABS(REAL(X(IX)))
                    IF (SCALE .LT. TEMP) THEN
                        SSQ = ONE + SSQ * (SCALE/TEMP)**2
                        SCALE = TEMP
                    ELSE
                        SSQ = SSQ + (TEMP/SCALE)**2
                    END IF
                END IF
                IF (AIMAG(X(IX)) .NE. ZERO) THEN
                    TEMP = ABS(AIMAG(X(IX)))
                    IF (SCALE .LT. TEMP) THEN
                        SSQ = ONE + SSQ * (SCALE/TEMP)**2
                        SCALE = TEMP
                    ELSE
                        SSQ = SSQ + (TEMP/SCALE)**2
                    END IF
                END IF
            END DO
            NORM = SCALE*SQRT(SSQ)
        END IF
        SCNRM2 = NORM
    END FUNCTION SCNRM2

END PROGRAM test_scnrm2