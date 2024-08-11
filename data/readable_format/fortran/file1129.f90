PROGRAM TestSLASSQ
  IMPLICIT NONE
  REAL, ALLOCATABLE :: X(:)
  INTEGER :: N, INCX
  REAL :: SCALE, SUMSQ

  ! Example: Testing the SLASSQ subroutine with specific values
  N = 4
  INCX = 1
  ALLOCATE(X(N))
  X = [1.0, 2.0, -3.0, 4.0]
  SCALE = 0.0
  SUMSQ = 0.0

  CALL SLASSQ(N, X, INCX, SCALE, SUMSQ)

  PRINT *, 'SCALE =', SCALE
  PRINT *, 'SUMSQ =', SUMSQ

  DEALLOCATE(X)
END PROGRAM TestSLASSQ

SUBROUTINE SLASSQ(N, X, INCX, SCALE, SUMSQ)
  INTEGER, INTENT(IN) :: N, INCX
  REAL, INTENT(IN) :: X(*)
  REAL, INTENT(INOUT) :: SCALE, SUMSQ
  INTEGER :: IX
  REAL :: ABSXI

  IF (N > 0) THEN
     DO IX = 1, 1 + (N-1) * INCX, INCX
        IF (X(IX) /= 0.0) THEN
           ABSXI = ABS(X(IX))
           IF (SCALE < ABSXI) THEN
              SUMSQ = 1 + SUMSQ * (SCALE / ABSXI)**2
              SCALE = ABSXI
           ELSE IF (SCALE /= 0.0) THEN
              SUMSQ = SUMSQ + (ABSXI / SCALE)**2
           END IF
        END IF
     END DO
  END IF
END SUBROUTINE SLASSQ