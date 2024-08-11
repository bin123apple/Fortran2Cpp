MODULE OLSAMEModule
IMPLICIT NONE
CONTAINS
    LOGICAL FUNCTION OLSAME(CA,CB)
        CHARACTER, INTENT(IN) :: CA, CB
        INTEGER :: INTA, INTB, ZCODE
        OLSAME = CA .EQ. CB
        IF (OLSAME) RETURN
        ZCODE = ICHAR('Z')
        INTA = ICHAR(CA)
        INTB = ICHAR(CB)
        IF (ZCODE .EQ. 90 .OR. ZCODE .EQ. 122) THEN
            IF (INTA .GE. 97 .AND. INTA .LE. 122) INTA = INTA - 32
            IF (INTB .GE. 97 .AND. INTB .LE. 122) INTB = INTB - 32
        ELSE IF (ZCODE .EQ. 233 .OR. ZCODE .EQ. 169) THEN
            IF ((INTA .GE. 129 .AND. INTA .LE. 137) .OR. &
                (INTA .GE. 145 .AND. INTA .LE. 153) .OR. &
                (INTA .GE. 162 .AND. INTA .LE. 169)) INTA = INTA + 64
            IF ((INTB .GE. 129 .AND. INTB .LE. 137) .OR. &
                (INTB .GE. 145 .AND. INTB .LE. 153) .OR. &
                (INTB .GE. 162 .AND. INTB .LE. 169)) INTB = INTB + 64
        ELSE IF (ZCODE .EQ. 218 .OR. ZCODE .EQ. 250) THEN
            IF (INTA .GE. 225 .AND. INTA .LE. 250) INTA = INTA - 32
            IF (INTB .GE. 225 .AND. INTB .LE. 250) INTB = INTB - 32
        END IF
        OLSAME = INTA .EQ. INTB
    END FUNCTION OLSAME
END MODULE OLSAMEModule

PROGRAM TestOLSAME
    USE OLSAMEModule
    IMPLICIT NONE
    CHARACTER :: testChar1, testChar2
    LOGICAL :: result

    ! Test case 1: Same uppercase letters
    testChar1 = 'A'
    testChar2 = 'A'
    result = OLSAME(testChar1, testChar2)
    PRINT *, "Test 1 (A, A): ", result

    ! Test case 2: Same letters, different cases
    testChar1 = 'a'
    testChar2 = 'A'
    result = OLSAME(testChar1, testChar2)
    PRINT *, "Test 2 (a, A): ", result

    ! Test case 3: Different letters
    testChar1 = 'A'
    testChar2 = 'B'
    result = OLSAME(testChar1, testChar2)
    PRINT *, "Test 3 (A, B): ", result

    ! Add more tests as needed...
END PROGRAM TestOLSAME