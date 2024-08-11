PROGRAM TestNWHSEL
    INTEGER :: NPTIMS
    INTEGER, DIMENSION(5) :: IPTIMS
    LOGICAL, DIMENSION(10) :: WHOTIM
    INTEGER :: result

    ! Initialize test data
    NPTIMS = 5
    IPTIMS = (/ 2, 4, 6, 8, 10 /) ! Adjusted for 1-based indexing
    WHOTIM = (/ .FALSE., .TRUE., .FALSE., .TRUE., .FALSE., .TRUE., .FALSE., .TRUE., .FALSE., .TRUE. /)

    ! Call the function
    result = NWHSEL(NPTIMS, IPTIMS, WHOTIM)

    ! Print the result
    PRINT *, 'Result: ', result

END PROGRAM TestNWHSEL

INTEGER FUNCTION NWHSEL (NPTIMS, IPTIMS, WHOTIM)
    INTEGER NPTIMS
    INTEGER IPTIMS(*)
    LOGICAL WHOTIM(*)

    NWHSEL = 0
    DO 100 I = 1, NPTIMS
        IF (WHOTIM(IPTIMS(I))) NWHSEL = NWHSEL + 1
    100 CONTINUE

    RETURN
END FUNCTION NWHSEL