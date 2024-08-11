PROGRAM test
    IMPLICIT NONE
    DOUBLE PRECISION DA
    INTEGER I, N
    DOUBLE PRECISION DX(9), DY(9)

    N = 5
    DA = 1.0
    DATA DX /-2, -1, -3, -4, 1, 2, 10, 15, 14/
    DATA DY /0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0/
    CALL DAXPY(N, DA, DX, DY)
    DO I = 1, N
        PRINT *, 'DY(', I, ') = ', DY(I)
    END DO
    STOP
END PROGRAM test

SUBROUTINE DAXPY(N, DA, DX, DY)
    IMPLICIT NONE
    DOUBLE PRECISION DA
    INTEGER N
    DOUBLE PRECISION DX(*), DY(*)
    INTEGER I

    DO I = 1, N
        DY(I) = DY(I) + DA * DX(I)
    END DO
    RETURN
END SUBROUTINE DAXPY