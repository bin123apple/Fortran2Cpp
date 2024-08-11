PROGRAM testCSLSTPTR
  IMPLICIT NONE
  INTEGER :: result
  INTEGER, DIMENSION(5) :: LIST = (/1, 3, 5, 7, 9/)
  INTEGER, DIMENSION(5) :: LPTR = (/2, 3, 4, 5, 1/)

  result = CSLSTPTR(1, 7, LIST, LPTR)
  PRINT *, "Test 1 (Find 7 starting from 1): ", result
  IF (result == 4) THEN
     PRINT *, "Test 1 Passed"
  ELSE
     PRINT *, "Test 1 Failed"
  END IF

  result = CSLSTPTR(3, 1, LIST, LPTR)
  PRINT *, "Test 2 (Find 1 starting from 3): ", result
  IF (result == 1) THEN
     PRINT *, "Test 2 Passed"
  ELSE
     PRINT *, "Test 2 Failed"
  END IF

CONTAINS

  INTEGER FUNCTION CSLSTPTR (LPL,NB,LIST,LPTR)
    INTEGER LPL, NB, LIST(*), LPTR(*)

    INTEGER LP, ND

    LP = LPTR(LPL)
1   ND = LIST(LP)
    IF (ND .EQ. NB) GO TO 2
    LP = LPTR(LP)
    IF (LP .NE. LPL) GO TO 1

2   CSLSTPTR = LP
    RETURN
  END FUNCTION CSLSTPTR

END PROGRAM testCSLSTPTR