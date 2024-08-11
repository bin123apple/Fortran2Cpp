SUBROUTINE ZROT(N, CX, INCX, CY, INCY, C, S)
      INTEGER            INCX, INCY, N
      DOUBLE PRECISION   C
      COMPLEX*16         S
      COMPLEX*16         CX( * ), CY( * )

      INTEGER            I, IX, IY
      COMPLEX*16         STEMP

      IF (N.LE.0) RETURN
      IF (INCX.EQ.1 .AND. INCY.EQ.1) THEN
          DO I = 1, N
              STEMP = C*CX(I) + S*CY(I)
              CY(I) = C*CY(I) - DCONJG(S)*CX(I)
              CX(I) = STEMP
          END DO
      ELSE
          IX = 1
          IY = 1
          IF (INCX.LT.0) IX = (-N+1)*INCX + 1
          IF (INCY.LT.0) IY = (-N+1)*INCY + 1
          DO I = 1, N
              STEMP = C*CX(IX) + S*CY(IY)
              CY(IY) = C*CY(IY) - DCONJG(S)*CX(IX)
              CX(IX) = STEMP
              IX = IX + INCX
              IY = IY + INCY
          END DO
      END IF
      END SUBROUTINE ZROT

      PROGRAM testZROT
      IMPLICIT NONE
      INTEGER :: N, INCX, INCY
      DOUBLE PRECISION :: C
      COMPLEX*16 :: S
      COMPLEX*16, ALLOCATABLE :: CX(:), CY(:)
      INTEGER :: i

      ! Test parameters
      N = 2
      C = 0.5
      S = (0.5, 0.5)
      ALLOCATE(CX(N), CY(N))
      CX = [(1.0, 2.0), (3.0, 4.0)]
      CY = [(5.0, 6.0), (7.0, 8.0)]
      INCX = 1
      INCY = 1

      ! Call ZROT subroutine
      CALL ZROT(N, CX, INCX, CY, INCY, C, S)

      ! Output the results
      PRINT *, 'Test 1 Results:'
      DO i = 1, N
          PRINT *, 'CX(', i, ') = ', CX(i)
          PRINT *, 'CY(', i, ') = ', CY(i)
      END DO

      DEALLOCATE(CX, CY)
      END PROGRAM testZROT