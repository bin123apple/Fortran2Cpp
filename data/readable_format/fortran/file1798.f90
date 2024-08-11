PROGRAM test_zlassq
  IMPLICIT NONE
  INTEGER, PARAMETER :: n = 2
  COMPLEX*16, DIMENSION(n) :: X
  INTEGER :: INCX
  DOUBLE PRECISION :: SCALE, SUMSQ

  X(1) = (3.0D0, 4.0D0)
  X(2) = (5.0D0, 12.0D0)
  INCX = 1
  SCALE = 0.0D0
  SUMSQ = 0.0D0

  CALL ZLASSQ(n, X, INCX, SCALE, SUMSQ)

  PRINT *, 'Scale:', SCALE
  PRINT *, 'Sumsq:', SUMSQ
END PROGRAM test_zlassq

SUBROUTINE ZLASSQ(N, X, INCX, SCALE, SUMSQ)
  INTEGER            INCX, N
  DOUBLE PRECISION   SCALE, SUMSQ
  COMPLEX*16         X( * )
  DOUBLE PRECISION   TEMP1
  INTEGER            IX

  IF(N.GT.0) THEN
    DO IX = 1, 1 + (N-1)*INCX, INCX
      ! Process the real part
      TEMP1 = ABS(DBLE(X(IX)))
      IF(TEMP1.NE.0) THEN
        IF(SCALE.LT.TEMP1) THEN
          SUMSQ = 1 + SUMSQ*(SCALE / TEMP1)**2
          SCALE = TEMP1
        ELSE
          SUMSQ = SUMSQ + (TEMP1 / SCALE)**2
        END IF
      END IF
      ! Process the imaginary part
      TEMP1 = ABS(DIMAG(X(IX)))
      IF(TEMP1.NE.0) THEN
        IF(SCALE.LT.TEMP1) THEN
          SUMSQ = 1 + SUMSQ*(SCALE / TEMP1)**2
          SCALE = TEMP1
        ELSE
          SUMSQ = SUMSQ + (TEMP1 / SCALE)**2
        END IF
      END IF
    END DO
  END IF
END SUBROUTINE ZLASSQ