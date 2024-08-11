PROGRAM test_zdscal
    IMPLICIT NONE
    COMPLEX*16, ALLOCATABLE :: zx(:)
    INTEGER :: i
    DOUBLE PRECISION :: da
    INTEGER :: n, incx

    ! Example test case
    n = 5
    ALLOCATE(zx(n))
    da = 2.0D0
    incx = 1

    ! Initialize zx with some values
    DO i = 1, n
        zx(i) = CMPLX(DBLE(i), DBLE(i))
    END DO

    ! Call ZDSCAL
    CALL ZDSCAL(n, da, zx, incx)

    ! Output the result
    PRINT *, 'Result:'
    DO i = 1, n
        PRINT *, 'zx(', i, ') = ', zx(i)
    END DO

    DEALLOCATE(zx)
END PROGRAM test_zdscal

SUBROUTINE ZDSCAL(N,DA,ZX,INCX)
    DOUBLE PRECISION DA
    INTEGER INCX,N
    COMPLEX*16 ZX(*)

    INTEGER I,NINCX
    INTRINSIC DCMPLX

    IF (N.LE.0 .OR. INCX.LE.0) RETURN
    IF (INCX.EQ.1) THEN
        DO I = 1,N
            ZX(I) = DCMPLX(DA,0.0D0)*ZX(I)
        END DO
    ELSE
        NINCX = N*INCX
        DO I = 1,NINCX,INCX
            ZX(I) = DCMPLX(DA,0.0D0)*ZX(I)
        END DO
    END IF
    RETURN
END SUBROUTINE ZDSCAL