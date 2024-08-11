MODULE parameters
  IMPLICIT NONE
  INTEGER, PARAMETER :: iprec1 = SELECTED_INT_KIND(2)
  INTEGER, PARAMETER :: iprec4 = SELECTED_INT_KIND(7)
  INTEGER, PARAMETER :: iprec8 = SELECTED_INT_KIND(12)
  INTEGER, PARAMETER :: rprec4 = SELECTED_REAL_KIND(p=6)
  INTEGER, PARAMETER :: rprec8 = SELECTED_REAL_KIND(p=12)
  INTEGER, PARAMETER :: rprec16 = SELECTED_REAL_KIND(p=18)
END MODULE parameters

PROGRAM testParameters
  USE parameters
  IMPLICIT NONE

  PRINT *, "Testing integer kinds..."
  IF (BIT_SIZE(1_iprec1) >= 2) THEN
    PRINT *, "iprec1 pass"
  ELSE
    PRINT *, "iprec1 fail"
  END IF

  IF (BIT_SIZE(1_iprec4) >= 7) THEN
    PRINT *, "iprec4 pass"
  ELSE
    PRINT *, "iprec4 fail"
  END IF

  IF (BIT_SIZE(1_iprec8) >= 12) THEN
    PRINT *, "iprec8 pass"
  ELSE
    PRINT *, "iprec8 fail"
  END IF

  PRINT *, "Testing real kinds..."
  IF (DIGITS(1.0_rprec4) >= 6) THEN
    PRINT *, "rprec4 pass"
  ELSE
    PRINT *, "rprec4 fail"
  END IF

  IF (DIGITS(1.0_rprec8) >= 12) THEN
    PRINT *, "rprec8 pass"
  ELSE
    PRINT *, "rprec8 fail"
  END IF

  IF (DIGITS(1.0_rprec16) >= 18) THEN
    PRINT *, "rprec16 pass"
  ELSE
    PRINT *, "rprec16 fail"
  END IF

END PROGRAM testParameters