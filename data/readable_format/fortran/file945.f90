! Define the subroutine ST_LCUC
SUBROUTINE ST_LCUC(string, outstr, iret)
    CHARACTER*(*) string, outstr
    INTEGER iret, isize, j, i
    iret = 0
    outstr = string
    isize = LEN_TRIM(outstr)
    
    DO i = 1, isize
        IF ((outstr(i:i) .GE. 'a') .AND. (outstr(i:i) .LE. 'z')) THEN
            j = ICHAR(outstr(i:i))
            j = j - 32
            outstr(i:i) = CHAR(j)
        ENDIF
    END DO
END SUBROUTINE ST_LCUC

! Main program to test ST_LCUC
PROGRAM testST_LCUC
    CHARACTER*100 string, outstr
    INTEGER iret

    ! Test with an empty string
    CALL ST_LCUC("", outstr, iret)
    IF (outstr .EQ. "") THEN
        PRINT *, "Test with empty string passed."
    ELSE
        PRINT *, "Test with empty string failed."
    ENDIF

    ! Test with only uppercase letters
    CALL ST_LCUC("HELLO", outstr, iret)
    IF (outstr .EQ. "HELLO") THEN
        PRINT *, "Test with uppercase letters passed."
    ELSE
        PRINT *, "Test with uppercase letters failed."
    ENDIF

    ! Test with only lowercase letters
    CALL ST_LCUC("world", outstr, iret)
    IF (outstr .EQ. "WORLD") THEN
        PRINT *, "Test with lowercase letters passed."
    ELSE
        PRINT *, "Test with lowercase letters failed."
    ENDIF

    ! Test with a mix of uppercase, lowercase, and non-letter characters
    CALL ST_LCUC("HeLlO 123!", outstr, iret)
    IF (outstr .EQ. "HELLO 123!") THEN
        PRINT *, "Test with mixed characters passed."
    ELSE
        PRINT *, "Test with mixed characters failed."
    ENDIF

END PROGRAM testST_LCUC