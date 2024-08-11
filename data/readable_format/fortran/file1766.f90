PROGRAM TestChrLtoc
  IMPLICIT NONE
  CHARACTER(LEN=5) :: testString
  INTEGER :: testNchar

  ! Test with LVALUE = .TRUE.
  CALL CHR_LTOC(.TRUE., testString, testNchar)
  PRINT *, 'Test 1 (LVALUE = .TRUE.):'
  PRINT *, 'STRING = ', testString
  PRINT *, 'NCHAR = ', testNchar

  ! Test with LVALUE = .FALSE.
  CALL CHR_LTOC(.FALSE., testString, testNchar)
  PRINT *, 'Test 2 (LVALUE = .FALSE.):'
  PRINT *, 'STRING = ', testString
  PRINT *, 'NCHAR = ', testNchar

END PROGRAM TestChrLtoc

SUBROUTINE CHR_LTOC(LVALUE, STRING, NCHAR)
  IMPLICIT NONE
  LOGICAL LVALUE
  CHARACTER STRING * ( * )
  INTEGER NCHAR

  IF (LVALUE) THEN
     STRING = 'TRUE'
     NCHAR = 4
  ELSE
     STRING = 'FALSE'
     NCHAR = 5
  END IF

END SUBROUTINE CHR_LTOC