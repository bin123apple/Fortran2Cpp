PROGRAM TestADGRD
    IMPLICIT NONE
    INTEGER :: i
    REAL, DIMENSION(6) :: dataF = (/1.0, 2.0, 3.0, -1.0, 5.0, 4.0/)
    REAL, DIMENSION(3) :: gridF = (/0.0, 0.0, 0.0/)
    REAL, DIMENSION(3) :: weightF = (/0.0, 0.0, 0.0/)
    DOUBLE PRECISION, DIMENSION(6) :: dataD = (/1.0D0, 2.0D0, 3.0D0, -1.0D0, 5.0D0, 4.0D0/)
    DOUBLE PRECISION, DIMENSION(3) :: gridD = (/0.0D0, 0.0D0, 0.0D0/)
    DOUBLE PRECISION, DIMENSION(3) :: weightD = (/0.0D0, 0.0D0, 0.0D0/)

    CALL ADGRDF(3, 1, 1, 0.5, dataF, gridF, weightF)
    CALL ADGRDD(3, 1, 1, 0.5D0, dataD, gridD, weightD)

    PRINT *, 'Single Precision Results:'
    DO i = 1, 3
       PRINT *, 'Grid:', gridF(i), 'Weight:', weightF(i)
    END DO

    PRINT *, 'Double Precision Results:'
    DO i = 1, 3
       PRINT *, 'Grid:', gridD(i), 'Weight:', weightD(i)
    END DO
END PROGRAM TestADGRD

SUBROUTINE ADGRDF(NVALS, START, INCR, CELLWT, DATA, GRID, WEIGHT)
    INTEGER :: INCR, J, K, NVALS, OFFSET, START
    REAL :: CELLWT, TOTWT
    REAL, DIMENSION(2*NVALS) :: DATA
    REAL, DIMENSION(START+INCR*(NVALS-1)) :: GRID, WEIGHT
    OFFSET = 0
    DO J = 2, 2*NVALS, 2
        IF (DATA(J) >= 0.0) THEN
            TOTWT = CELLWT * DATA(J)
            K = START + OFFSET
            GRID(K) = GRID(K) + DATA(J-1) * TOTWT
            WEIGHT(K) = WEIGHT(K) + TOTWT
        END IF
        OFFSET = OFFSET + INCR
    END DO
END SUBROUTINE ADGRDF

SUBROUTINE ADGRDD(NVALS, START, INCR, CELLWT, DATA, GRID, WEIGHT)
    INTEGER :: INCR, J, K, NVALS, OFFSET, START
    DOUBLE PRECISION :: CELLWT, TOTWT
    DOUBLE PRECISION, DIMENSION(2*NVALS) :: DATA
    DOUBLE PRECISION, DIMENSION(START+INCR*(NVALS-1)) :: GRID, WEIGHT
    OFFSET = 0
    DO J = 2, 2*NVALS, 2
        IF (DATA(J) >= 0.0D0) THEN
            TOTWT = CELLWT * DATA(J)
            K = START + OFFSET
            GRID(K) = GRID(K) + DATA(J-1) * TOTWT
            WEIGHT(K) = WEIGHT(K) + TOTWT
        END IF
        OFFSET = OFFSET + INCR
    END DO
END SUBROUTINE ADGRDD