! Define the DSCAL subroutine
SUBROUTINE DSCAL(N, DA, DX, INCX)
    IMPLICIT NONE
    INTEGER, INTENT(IN) :: N, INCX
    DOUBLE PRECISION, INTENT(IN) :: DA
    DOUBLE PRECISION, INTENT(INOUT) :: DX(*)
    INTEGER :: I, M, MP1, NINCX
    IF (N.LE.0 .OR. INCX.LE.0) RETURN
    IF (INCX.EQ.1) THEN
        M = MOD(N, 5)
        IF (M.NE.0) THEN
            DO I = 1, M
                DX(I) = DA * DX(I)
            END DO
            IF (N.LT.5) RETURN
        END IF
        MP1 = M + 1
        DO I = MP1, N, 5
            DX(I) = DA * DX(I)
            DX(I+1) = DA * DX(I+1)
            DX(I+2) = DA * DX(I+2)
            DX(I+3) = DA * DX(I+3)
            DX(I+4) = DA * DX(I+4)
        END DO
    ELSE
        NINCX = N * INCX
        DO I = 1, NINCX, INCX
            DX(I) = DA * DX(I)
        END DO
    END IF
END SUBROUTINE DSCAL

! Test program for DSCAL
PROGRAM testDSCAL
  IMPLICIT NONE
  DOUBLE PRECISION, ALLOCATABLE :: dx(:)
  INTEGER :: n, incx
  DOUBLE PRECISION :: da
  
  ! Test Case 1: n=5, da=2.0, incx=1
  n = 5
  ALLOCATE(dx(n))
  dx = (/1.0, 2.0, 3.0, 4.0, 5.0/)
  da = 2.0
  incx = 1
  CALL DSCAL(n, da, dx, incx)
  PRINT *, 'Test Case 1: ', dx
  
  ! Test Case 2: n=3, da=3.0, incx=2 (non-contiguous memory access)
  DEALLOCATE(dx)
  n = 6
  ALLOCATE(dx(n))
  dx = (/1.0, 1.0, 2.0, 2.0, 3.0, 3.0/)
  da = 3.0
  incx = 2
  CALL DSCAL(3, da, dx, incx)
  PRINT *, 'Test Case 2: ', dx
  
  DEALLOCATE(dx)
END PROGRAM testDSCAL