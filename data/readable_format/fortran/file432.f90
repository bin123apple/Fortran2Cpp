MODULE MDILNBMod
  IMPLICIT NONE
CONTAINS
  INTEGER FUNCTION MDILNB(CHRS)
    CHARACTER(*), INTENT(IN) :: CHRS
    INTEGER :: I

    DO I=LEN(CHRS),1,-1
      IF (CHRS(I:I).NE.' ') THEN
        MDILNB=I
        RETURN
      END IF
    END DO
    MDILNB=1
  END FUNCTION MDILNB
END MODULE MDILNBMod

PROGRAM TestMDILNB
  USE MDILNBMod
  IMPLICIT NONE

  INTEGER :: result

  ! Test 1: String with spaces at the end
  result = MDILNB('Hello World   ')
  PRINT *, 'Test 1 (Expected 11): ', result

  ! Test 2: String with no spaces
  result = MDILNB('HelloWorld')
  PRINT *, 'Test 2 (Expected 10): ', result

  ! Test 3: String with spaces only
  result = MDILNB('    ')
  PRINT *, 'Test 3 (Expected 1): ', result

  ! Test 4: Empty String
  result = MDILNB('')
  PRINT *, 'Test 4 (Expected 1): ', result

END PROGRAM TestMDILNB