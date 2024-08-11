PROGRAM TestSNRM2
  IMPLICIT NONE

  REAL SNRM2
  REAL, DIMENSION(5) :: X
  REAL RESULT
  INTEGER INCX, N

  ! Testing SNRM2 with sample data
  X = (/ 1.0, 2.0, 3.0, 4.0, 5.0 /)
  N = 5
  INCX = 1

  RESULT = SNRM2(N, X, INCX)
  PRINT *, 'Result of SNRM2:', RESULT

  ! Add more tests as needed
END PROGRAM TestSNRM2

REAL FUNCTION SNRM2(N, X, INCX)
  INTEGER INCX, N
  REAL X(*)

  REAL ONE, ZERO
  PARAMETER (ONE=1.0E+0, ZERO=0.0E+0)

  REAL ABSXI, NORM, SCALE, SSQ
  INTEGER IX

  INTRINSIC ABS, SQRT

  IF (N.LT.1 .OR. INCX.LT.1) THEN
      NORM = ZERO
  ELSE IF (N.EQ.1) THEN
      NORM = ABS(X(1))
  ELSE
      SCALE = ZERO
      SSQ = ONE

      DO 10 IX = 1, 1 + (N-1)*INCX, INCX
          IF (X(IX).NE.ZERO) THEN
              ABSXI = ABS(X(IX))
              IF (SCALE.LT.ABSXI) THEN
                  SSQ = ONE + SSQ* (SCALE/ABSXI)**2
                  SCALE = ABSXI
              ELSE
                  SSQ = SSQ + (ABSXI/SCALE)**2
              END IF
          END IF
10    CONTINUE
      NORM = SCALE*SQRT(SSQ)
  END IF

  SNRM2 = NORM
  RETURN

END