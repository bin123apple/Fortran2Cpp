PROGRAM testST_LCUC
    IMPLICIT NONE
    CHARACTER(len=20) :: string, outstr
    INTEGER :: iret

    ! Test data
    string = 'Hello, World!'
    outstr = ' ' ! Initialize with spaces
    iret = -1    ! Initialize with a non-zero value

    ! Call the subroutine
    CALL ST_LCUC(string, outstr, iret)

    ! Check the results
    IF (TRIM(outstr) == 'HELLO, WORLD!' .AND. iret == 0) THEN
        PRINT *, 'Test passed.'
    ELSE
        PRINT *, 'Test failed.'
    END IF

END PROGRAM testST_LCUC

SUBROUTINE ST_LCUC(string, outstr, iret)
    IMPLICIT NONE
    CHARACTER(len=*), INTENT(IN) :: string
    CHARACTER(len=*), INTENT(OUT) :: outstr
    INTEGER, INTENT(OUT) :: iret
    INTEGER :: i, j, isize

    iret = 0
    outstr = string
    isize = LEN_TRIM(outstr)

    DO i = 1, isize
        IF ((outstr(i:i) >= 'a') .AND. (outstr(i:i) <= 'z')) THEN
            j = ICHAR(outstr(i:i))
            j = j - 32
            outstr(i:i) = CHAR(j)
        END IF
    END DO

END SUBROUTINE ST_LCUC