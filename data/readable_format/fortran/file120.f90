! Define the ST_ALNM subroutine
SUBROUTINE ST_ALNM(chrstr, ityp, iret)
    CHARACTER*(*) chrstr
    INTEGER ityp, iret

    iret = 0
    ityp = 0
    IF ((chrstr .GE. '0') .AND. (chrstr .LE. '9')) ityp = 1
    IF ((chrstr .GE. 'a') .AND. (chrstr .LE. 'z')) ityp = 2
    IF ((chrstr .GE. 'A') .AND. (chrstr .LE. 'Z')) ityp = 2
    
    RETURN
END SUBROUTINE ST_ALNM

! Begin the main program to test ST_ALNM
PROGRAM testST_ALNM
    IMPLICIT NONE
    CHARACTER*1 testChar
    INTEGER ityp, iret

    ! Test 1: Check a digit
    testChar = '5'
    CALL ST_ALNM(testChar, ityp, iret)
    IF (ityp == 1) THEN
        PRINT *, 'Test 1 passed.'
    ELSE
        PRINT *, 'Test 1 failed.'
    END IF

    ! Test 2: Check a lowercase letter
    testChar = 'a'
    CALL ST_ALNM(testChar, ityp, iret)
    IF (ityp == 2) THEN
        PRINT *, 'Test 2 passed.'
    ELSE
        PRINT *, 'Test 2 failed.'
    END IF

    ! Test 3: Check an uppercase letter
    testChar = 'Z'
    CALL ST_ALNM(testChar, ityp, iret)
    IF (ityp == 2) THEN
        PRINT *, 'Test 3 passed.'
    ELSE
        PRINT *, 'Test 3 failed.'
    END IF

    ! Test 4: Check a non-alphanumeric character
    testChar = '@'
    CALL ST_ALNM(testChar, ityp, iret)
    IF (ityp == 0) THEN
        PRINT *, 'Test 4 passed.'
    ELSE
        PRINT *, 'Test 4 failed.'
    END IF
END PROGRAM testST_ALNM