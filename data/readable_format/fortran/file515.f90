PROGRAM TestDAXPY
    IMPLICIT NONE
    DOUBLE PRECISION, ALLOCATABLE :: DX(:), DY(:)
    DOUBLE PRECISION DA
    INTEGER N, INCX, INCY
    INTEGER I

    ! Initialize variables
    N = 5
    DA = 2.0D0
    INCX = 1
    INCY = 1
    ALLOCATE(DX(N), DY(N))

    ! Initialize DX and DY arrays
    DO I = 1, N
        DX(I) = I * 1.0D0
        DY(I) = I * 2.0D0
    END DO

    ! Call DAXPY subroutine
    CALL DAXPY(N, DA, DX, INCX, DY, INCY)

    ! Print DY
    PRINT *, 'Resulting DY:'
    DO I = 1, N
        PRINT *, DY(I)
    END DO

    DEALLOCATE(DX, DY)

CONTAINS

    SUBROUTINE DAXPY (N, DA, DX, INCX, DY, INCY)
        DOUBLE PRECISION DX(*), DY(*), DA
        INTEGER N, INCX, INCY
        INTEGER I, IX, IY, M, MP1, NS
        IF (N.LE.0 .OR. DA.EQ.0.0D0) RETURN
        IF (INCX .EQ. INCY) THEN
            IF (INCX-1 == 0) THEN
                IX = 1
                IY = 1
                IF (INCX .LT. 0) IX = (-N+1)*INCX + 1
                IF (INCY .LT. 0) IY = (-N+1)*INCY + 1
                DO I = 1,N
                    DY(IY) = DY(IY) + DA*DX(IX)
                    IX = IX + INCX
                    IY = IY + INCY
                END DO
                RETURN
            ELSE
                M = MOD(N,4)
                IF (M .NE. 0) THEN
                    DO I = 1,M
                        DY(I) = DY(I) + DA*DX(I)
                    END DO
                    IF (N .LT. 4) RETURN
                END IF
                MP1 = M + 1
                DO I = MP1,N,4
                    DY(I) = DY(I) + DA*DX(I)
                    DY(I+1) = DY(I+1) + DA*DX(I+1)
                    DY(I+2) = DY(I+2) + DA*DX(I+2)
                    DY(I+3) = DY(I+3) + DA*DX(I+3)
                END DO
                RETURN
            END IF
        ELSE
            NS = N*INCX
            DO I = 1,NS,INCX
                DY(I) = DA*DX(I) + DY(I)
            END DO
            RETURN
        END IF
    END SUBROUTINE DAXPY

END PROGRAM TestDAXPY