! Combine the subroutine and test program into one file.
PROGRAM TestSLA_CAF2R
  IMPLICIT NONE

  INTEGER :: j
  REAL :: rad

  ! Test 1: Valid input
  CALL sla_CAF2R(10, 20, 30.0, rad, j)
  PRINT *, "Test 1: RAD =", rad, "J =", j

  ! Test 2: Invalid seconds
  CALL sla_CAF2R(10, 20, 60.0, rad, j)
  PRINT *, "Test 2: RAD =", rad, "J =", j

  ! Test 3: Invalid minutes
  CALL sla_CAF2R(10, 60, 30.0, rad, j)
  PRINT *, "Test 3: RAD =", rad, "J =", j

  ! Test 4: Invalid degrees
  CALL sla_CAF2R(360, 20, 30.0, rad, j)
  PRINT *, "Test 4: RAD =", rad, "J =", j

  ! Test 5: Edge case (0, 0, 0)
  CALL sla_CAF2R(0, 0, 0.0, rad, j)
  PRINT *, "Test 5: RAD =", rad, "J =", j

CONTAINS

  SUBROUTINE sla_CAF2R (IDEG, IAMIN, ASEC, RAD, J)
    IMPLICIT NONE
    INTEGER IDEG, IAMIN
    REAL ASEC, RAD
    INTEGER J

    REAL AS2R
    PARAMETER (AS2R=0.484813681109535994E-5)

    J=0

    IF (ASEC.LT.0.0.OR.ASEC.GE.60.0) J=3
    IF (IAMIN.LT.0.OR.IAMIN.GT.59) J=2
    IF (IDEG.LT.0.OR.IDEG.GT.359) J=1

    RAD=AS2R*(60.0*(60.0*REAL(IDEG)+REAL(IAMIN))+ASEC)
  END SUBROUTINE sla_CAF2R

END PROGRAM TestSLA_CAF2R