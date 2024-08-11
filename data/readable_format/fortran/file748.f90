SUBROUTINE DAXPY(N, DA, DX, INCX, DY, INCY)
  DOUBLE PRECISION DX(*), DY(*), DA
  INTEGER I, INCX, INCY, IX, IY, M, MP1, N

  IF (N.LE.0) RETURN
  IF (DA.EQ.0.0D0) RETURN

  IF (INCX.EQ.1 .AND. INCY.EQ.1) THEN
     M = MOD(N,4)
     IF (M .NE. 0) THEN
        DO I = 1, M
           DY(I) = DY(I) + DA*DX(I)
        END DO
        IF (N .LT. 4) RETURN
     END IF
     MP1 = M + 1
     DO I = MP1, N, 4
        DY(I) = DY(I) + DA*DX(I)
        DY(I + 1) = DY(I + 1) + DA*DX(I + 1)
        DY(I + 2) = DY(I + 2) + DA*DX(I + 2)
        DY(I + 3) = DY(I + 3) + DA*DX(I + 3)
     END DO
  ELSE
     IX = 1
     IY = 1
     IF (INCX.LT.0) IX = (-N+1)*INCX + 1
     IF (INCY.LT.0) IY = (-N+1)*INCY + 1
     DO I = 1, N
        DY(IY) = DY(IY) + DA*DX(IX)
        IX = IX + INCX
        IY = IY + INCY
     END DO
  END IF
END SUBROUTINE DAXPY

PROGRAM testDAXPY
  IMPLICIT NONE
  DOUBLE PRECISION, ALLOCATABLE :: DX(:), DY(:)
  DOUBLE PRECISION :: DA
  INTEGER :: N, INCX, INCY, I

  N = 5
  DA = 2.0D0
  INCX = 1
  INCY = 1
  ALLOCATE(DX(N), DY(N))
  DX = (/1.0D0, 2.0D0, 3.0D0, 4.0D0, 5.0D0/)
  DY = (/5.0D0, 4.0D0, 3.0D0, 2.0D0, 1.0D0/)
  CALL DAXPY(N, DA, DX, INCX, DY, INCY)
  PRINT *, 'Test Case 1: DY = ', DY
  DEALLOCATE(DX, DY)
END PROGRAM testDAXPY