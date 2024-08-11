PROGRAM testNEMOCK
  IMPLICIT NONE

  INTEGER :: result

  ! Test 1: Valid input
  result = NEMOCK('ABC123')
  IF (result == 0) THEN
    PRINT *, 'Test 1 passed.'
  ELSE
    PRINT *, 'Test 1 failed.'
  END IF

  ! Test 2: Invalid length
  result = NEMOCK('TOOLONGINPUT')
  IF (result == -1) THEN
    PRINT *, 'Test 2 passed.'
  ELSE
    PRINT *, 'Test 2 failed.'
  END IF

  ! Test 3: Invalid character
  result = NEMOCK('AB@123')
  IF (result == -2) THEN
    PRINT *, 'Test 3 passed.'
  ELSE
    PRINT *, 'Test 3 failed.'
  END IF

CONTAINS

  FUNCTION NEMOCK(NEMO)
    CHARACTER(LEN=*), INTENT(IN) :: NEMO
    INTEGER :: NEMOCK
    CHARACTER(LEN=38) :: CHRSET = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789_.'
    INTEGER :: NCHR = 38
    INTEGER :: LNEMO, I, J

    LNEMO = 0

    DO I=LEN_TRIM(NEMO),1,-1
      IF(NEMO(I:I) .NE. ' ') THEN
        LNEMO = I
        EXIT
      END IF
    END DO

    IF(LNEMO < 1 .OR. LNEMO > 8) THEN
      NEMOCK = -1
      RETURN
    END IF

    DO I=1,LNEMO
      DO J=1,NCHR
        IF(NEMO(I:I) .EQ. CHRSET(J:J)) EXIT
        IF(J .EQ. NCHR) THEN
          NEMOCK = -2
          RETURN
        END IF
      END DO
    END DO

    NEMOCK = 0
  END FUNCTION NEMOCK

END PROGRAM testNEMOCK