PROGRAM TestQQQMIMA
  IMPLICIT NONE
  REAL :: fld(5) = (/1.0, 3.5, -2.0, 4.5, 0.0/)
  REAL :: xmin, xmax

  CALL QQQMIMA(fld, 5, xmin, xmax)

  PRINT *, "The minimum value is: ", xmin
  PRINT *, "The maximum value is: ", xmax
END PROGRAM TestQQQMIMA

SUBROUTINE QQQMIMA(FLD,N,XMIN,XMAX)
  INTEGER N
  REAL FLD(N)
  REAL XMIN, XMAX

  REAL XXMIN,XXMAX

  XXMIN = FLD(1)
  XXMAX = FLD(1)
  DO 10 I = 2,N
      XXMIN = MIN(FLD(I),XXMIN)
      XXMAX = MAX(FLD(I),XXMAX)
10   CONTINUE
  XMIN = XXMIN
  XMAX = XXMAX
  RETURN
END