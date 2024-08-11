PROGRAM testLSAME
  IMPLICIT NONE

  ! Test cases are called here
  CALL testLSAMECases

CONTAINS

  LOGICAL FUNCTION LSAME(CA, CB)
    CHARACTER, INTENT(IN) :: CA, CB
    INTEGER :: INTA, INTB, ZCODE

    LSAME = (CA == CB)
    IF (LSAME) RETURN

    ZCODE = ICHAR('Z')

    INTA = ICHAR(CA)
    INTB = ICHAR(CB)

    IF (ZCODE == 90 .OR. ZCODE == 122) THEN
      IF (INTA >= 97 .AND. INTA <= 122) INTA = INTA - 32
      IF (INTB >= 97 .AND. INTB <= 122) INTB = INTB - 32
    ELSE IF (ZCODE == 233 .OR. ZCODE == 169) THEN
      IF ((INTA >= 129 .AND. INTA <= 137) .OR. &
          (INTA >= 145 .AND. INTA <= 153) .OR. &
          (INTA >= 162 .AND. INTA <= 169)) INTA = INTA + 64
      IF ((INTB >= 129 .AND. INTB <= 137) .OR. &
          (INTB >= 145 .AND. INTB <= 153) .OR. &
          (INTB >= 162 .AND. INTB <= 169)) INTB = INTB + 64
    ELSE IF (ZCODE == 218 .OR. ZCODE == 250) THEN
      IF (INTA >= 225 .AND. INTA <= 250) INTA = INTA - 32
      IF (INTB >= 225 .AND. INTB <= 250) INTB = INTB - 32
    END IF

    LSAME = (INTA == INTB)
  END FUNCTION LSAME

  SUBROUTINE testLSAMECases
    CHARACTER(1) :: char1, char2
    LOGICAL :: expected

    ! Test Case 1: Identical uppercase letters
    char1 = 'A'; char2 = 'A'; expected = .TRUE.
    CALL assertLSAME(char1, char2, expected)

    ! Test Case 2: Identical lowercase letters
    char1 = 'b'; char2 = 'b'; expected = .TRUE.
    CALL assertLSAME(char1, char2, expected)

    ! Test Case 3: Uppercase and lowercase of the same letter
    char1 = 'c'; char2 = 'C'; expected = .TRUE.
    CALL assertLSAME(char1, char2, expected)

    ! Test Case 4: Different letters
    char1 = 'D'; char2 = 'E'; expected = .FALSE.
    CALL assertLSAME(char1, char2, expected)

    ! Test Case 5: Non-letter characters
    char1 = '1'; char2 = '1'; expected = .TRUE.
    CALL assertLSAME(char1, char2, expected)
  END SUBROUTINE testLSAMECases

  SUBROUTINE assertLSAME(char1, char2, expected)
    CHARACTER(1), INTENT(IN) :: char1, char2
    LOGICAL, INTENT(IN) :: expected
    LOGICAL :: result

    result = LSAME(char1, char2)
    IF (result .EQV. expected) THEN
      PRINT *, "Test Passed for comparing '", char1, "' with '", char2, "'"
    ELSE
      PRINT *, "Test Failed for comparing '", char1, "' with '", char2, "'"
    END IF
  END SUBROUTINE assertLSAME

END PROGRAM testLSAME