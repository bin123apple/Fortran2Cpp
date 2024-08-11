PROGRAM TestZDSCAL
    IMPLICIT NONE
    DOUBLE PRECISION, PARAMETER :: DA = 2.0d0
    INTEGER, PARAMETER :: N = 3, INCX = 1
    DOUBLE COMPLEX, DIMENSION(N) :: ZX
    INTEGER :: I

    ! Initialize ZX array
    ZX(1) = (1.0d0, 2.0d0)
    ZX(2) = (3.0d0, 4.0d0)
    ZX(3) = (5.0d0, 6.0d0)

    CALL ZDSCAL(N, DA, ZX, INCX)

    PRINT *, 'Scaled ZX:'
    DO I = 1, N
        PRINT '("ZX(",I1,") = (",F4.1,", ",F4.1,")")', I, DBLE(ZX(I)), DIMAG(ZX(I))
    END DO
END PROGRAM TestZDSCAL

!=================================================================

SUBROUTINE ZDSCAL(N,DA,ZX,INCX)
    DOUBLE PRECISION DA
    INTEGER INCX,N
    DOUBLE COMPLEX ZX(*)
    INTEGER I,NINCX
    IF (N.LE.0 .OR. INCX.LE.0) RETURN
    IF (INCX.EQ.1) THEN
        DO I = 1,N
            ZX(I) = DCMPLX(DA,0.0d0)*ZX(I)
        END DO
    ELSE
        NINCX = N*INCX
        DO I = 1,NINCX,INCX
            ZX(I) = DCMPLX(DA,0.0d0)*ZX(I)
        END DO
    END IF
    RETURN
END SUBROUTINE ZDSCAL