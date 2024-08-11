PROGRAM testLSAME
    IMPLICIT NONE

    CHARACTER*2 CA1
    CHARACTER*1 CB1, CA2, CB2, CA3, CB3
    LOGICAL result

    ! Test for the first implementation of LSAME
    CA1 = 'AB'
    CB1 = 'A'
    result = LSAME1(CA1, CB1)
    PRINT *, 'Test 1-1 (expected .TRUE.): ', result

    CA1 = 'AB'
    CB1 = 'B'
    result = LSAME1(CA1, CB1)
    PRINT *, 'Test 1-2 (expected .FALSE.): ', result

    ! Test for the second implementation of LSAME
    CA2 = 'A'
    CB2 = 'A'
    result = LSAME2(CA2, CB2)
    PRINT *, 'Test 2-1 (expected .TRUE.): ', result

    CA2 = 'A'
    CB2 = 'a'
    result = LSAME2(CA2, CB2)
    PRINT *, 'Test 2-2 (expected .FALSE.): ', result

    ! Test for the third implementation of LSAME
    CA3 = 'A'
    CB3 = 'A'
    result = LSAME3(CA3, CB3)
    PRINT *, 'Test 3-1 (expected .TRUE.): ', result

    CA3 = 'A'
    CB3 = 'a'
    result = LSAME3(CA3, CB3)
    PRINT *, 'Test 3-2 (expected .FALSE.): ', result

CONTAINS

    LOGICAL FUNCTION LSAME1(CA, CB)
        CHARACTER(*), INTENT(IN) :: CA
        CHARACTER(1), INTENT(IN) :: CB
        INTEGER :: ICIRFX, IVAL
        DATA ICIRFX /62/
        LSAME1 = CA(1:1) == CB .AND. CA(1:1) /= CHAR(ICIRFX)
        IF (LSAME1) RETURN
        IVAL = ICHAR(CA(2:2))
        IF (IVAL >= ICHAR('A') .AND. IVAL <= ICHAR('Z')) THEN
            LSAME1 = CA(1:1) == CHAR(ICIRFX) .AND. CA(2:2) == CB
        END IF
    END FUNCTION LSAME1

    LOGICAL FUNCTION LSAME2(CA, CB)
        CHARACTER(1), INTENT(IN) :: CA, CB
        INTEGER :: IOFF, ISHIFT
        DATA IOFF /32/
        LSAME2 = CA == CB
        IF (LSAME2) RETURN
        ISHIFT = ICHAR(CA) - IOFF
        IF (ISHIFT >= ICHAR('A') .AND. ISHIFT <= ICHAR('Z')) THEN
            LSAME2 = ISHIFT == ICHAR(CB)
        END IF
    END FUNCTION LSAME2

    LOGICAL FUNCTION LSAME3(CA, CB)
        CHARACTER(1), INTENT(IN) :: CA, CB
        INTEGER :: IOFF, ISHIFT
        DATA IOFF /64/
        LSAME3 = CA == CB
        IF (LSAME3) RETURN
        ISHIFT = ICHAR(CA) + IOFF
        IF ((ISHIFT >= ICHAR('A') .AND. ISHIFT <= ICHAR('I')) .OR. &
            (ISHIFT >= ICHAR('J') .AND. ISHIFT <= ICHAR('R')) .OR. &
            (ISHIFT >= ICHAR('S') .AND. ISHIFT <= ICHAR('Z'))) THEN
            LSAME3 = ISHIFT == ICHAR(CB)
        END IF
    END FUNCTION LSAME3

END PROGRAM testLSAME