! Main program and subroutine in the same file
PROGRAM TestCHKRNG
  IMPLICIT NONE
  INTEGER, PARAMETER :: N = 5
  INTEGER :: IARRAY(N) = (/ 0, 2, 5, 10, 15 /)
  INTEGER :: NITEMS, MAXVAL, NZERO, NERR

  ! Initialize variables
  NITEMS = N
  MAXVAL = 10
  ! Call the subroutine
  CALL CHKRNG(IARRAY, NITEMS, MAXVAL, NZERO, NERR)

  ! Output results
  PRINT *, 'NZERO = ', NZERO
  PRINT *, 'NERR = ', NERR
END PROGRAM TestCHKRNG

! Subroutine definition
SUBROUTINE CHKRNG (IARRAY, NITEMS, MAXVAL, NZERO, NERR)
  INTEGER :: IARRAY(*), NITEMS, MAXVAL, NZERO, NERR, I, N

  NERR  = 0
  NZERO = 0
  DO I = 1, NITEMS
     N = IARRAY(I)
     IF (N .LT. 1) THEN
        NZERO = NZERO + 1
     END IF
     IF (N .GT. MAXVAL) THEN
        NERR  = NERR + 1
     END IF
  END DO
END SUBROUTINE CHKRNG