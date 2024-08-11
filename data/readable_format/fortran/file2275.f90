PROGRAM test_zero
  IMPLICIT NONE

  ! Variable declarations
  DOUBLE PRECISION :: TIME, TPRINT, ERRTOT, DETOT, ONE3, ONE6, ONE9, ONE12, TWOPI, CPUTOT
  INTEGER :: MODEL, NDUMP, NSTEPS, NTIMER

  CALL ZERO
  
  ! Output the results to verify correctness
  PRINT *, 'TIME = ', TIME
  PRINT *, 'TPRINT = ', TPRINT
  PRINT *, 'CPUTOT = ', CPUTOT
  PRINT *, 'ERRTOT = ', ERRTOT
  PRINT *, 'DETOT = ', DETOT
  PRINT *, 'MODEL = ', MODEL
  PRINT *, 'NDUMP = ', NDUMP
  PRINT *, 'NSTEPS = ', NSTEPS
  PRINT *, 'NTIMER = ', NTIMER
  PRINT *, 'ONE3 = ', ONE3
  PRINT *, 'ONE6 = ', ONE6
  PRINT *, 'ONE9 = ', ONE9
  PRINT *, 'ONE12 = ', ONE12
  PRINT *, 'TWOPI = ', TWOPI

  CONTAINS

    SUBROUTINE ZERO
      ! Initialize variables
      TIME = 0.0D0
      TPRINT = 0.0D0
      CPUTOT = 0.0D0
      ERRTOT = 0.0D0
      DETOT = 0.0D0
      MODEL = 0
      NDUMP = 0
      NSTEPS = 0
      NTIMER = 0
      ONE3 = 1.0D0/3.0D0
      ONE6 = 1.0D0/6.0D0
      ONE9 = 1.0D0/9.0D0
      ONE12 = 1.0D0/12.0D0
      TWOPI = 8.0D0*ATAN(1.0D0)
    END SUBROUTINE ZERO

END PROGRAM test_zero