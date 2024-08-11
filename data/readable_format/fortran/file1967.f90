PROGRAM testReplaceCharacter
  IMPLICIT NONE
  CHARACTER(LEN=20) :: testString
  CHARACTER(LEN=1) :: oldChar, newChar

  ! Test 1: Replace characters at the beginning, middle, and end.
  testString = 'abcdeabcdeabcde'
  oldChar = 'a'
  newChar = 'z'
  CALL REPLACE_CHARACTER(testString, oldChar, newChar)
  PRINT *, 'Test 1: ', testString  ! Expected: 'zbcdezbcdezbcde'

  ! Test 2: OLD_CHAR does not exist.
  testString = 'abcdeabcdeabcde'
  oldChar = 'x'
  newChar = 'y'
  CALL REPLACE_CHARACTER(testString, oldChar, newChar)
  PRINT *, 'Test 2: ', testString  ! Expected: 'abcdeabcdeabcde'

  ! Test 3: Multiple instances of OLD_CHAR.
  testString = 'aaaaa'
  oldChar = 'a'
  newChar = 'b'
  CALL REPLACE_CHARACTER(testString, oldChar, newChar)
  PRINT *, 'Test 3: ', testString  ! Expected: 'bbbbb'

  ! Test 4: Empty string.
  testString = ''
  oldChar = 'a'
  newChar = 'b'
  CALL REPLACE_CHARACTER(testString, oldChar, newChar)
  PRINT *, 'Test 4: ', testString  ! Expected: ''

CONTAINS

  SUBROUTINE REPLACE_CHARACTER(STRING,OLD_CHAR,NEW_CHAR)
    IMPLICIT NONE
    CHARACTER(LEN=*), INTENT(INOUT) :: STRING
    CHARACTER(LEN=1), INTENT(IN) :: OLD_CHAR, NEW_CHAR
    INTEGER :: IEND, I

    IEND = LEN(STRING)
    DO I = 1, IEND
       IF(STRING(I:I) == OLD_CHAR) THEN
          STRING(I:I) = NEW_CHAR
       END IF
    END DO
  END SUBROUTINE REPLACE_CHARACTER

END PROGRAM testReplaceCharacter