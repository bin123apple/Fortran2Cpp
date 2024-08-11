PROGRAM test_ppm_rc_uppercase
    IMPLICIT NONE
    CHARACTER(LEN=100) :: test_string

    ! Test 1: Standard lowercase to uppercase
    test_string = 'hello, world!'
    CALL ppm_rc_uppercase(test_string)
    IF (test_string == 'HELLO, WORLD!') THEN
        PRINT *, 'Test 1 passed.'
    ELSE
        PRINT *, 'Test 1 failed.'
    END IF

    ! Test 2: Mixed case
    test_string = 'FoRtRaN 77'
    CALL ppm_rc_uppercase(test_string)
    IF (test_string == 'FORTRAN 77') THEN
        PRINT *, 'Test 2 passed.'
    ELSE
        PRINT *, 'Test 2 failed.'
    END IF

    ! Test 3: String with numbers and punctuation
    test_string = '123abc!@#'
    CALL ppm_rc_uppercase(test_string)
    IF (test_string == '123ABC!@#') THEN
        PRINT *, 'Test 3 passed.'
    ELSE
        PRINT *, 'Test 3 failed.'
    END IF

CONTAINS

    SUBROUTINE ppm_rc_uppercase(record)
        IMPLICIT NONE
        CHARACTER(LEN = *), INTENT(INOUT) :: record
        INTEGER :: length, LowerToUpper, i
        CHARACTER(LEN = LEN(record)) :: temp

        LowerToUpper = IACHAR("A") - IACHAR("a")
        temp = ADJUSTL(record)
        length = LEN_TRIM(temp)

        record = ''
        DO i=1,length
            SELECT CASE (temp(i:i))
            CASE ('a' : 'z')
                record(i:i) = ACHAR(IACHAR(temp(i:i)) + LowerToUpper)
            CASE DEFAULT
                record(i:i) = temp(i:i)
            END SELECT
        ENDDO
    END SUBROUTINE ppm_rc_uppercase

END PROGRAM test_ppm_rc_uppercase