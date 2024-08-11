PROGRAM TestPT2SAM
    IMPLICIT NONE
    INTEGER :: result

    result = PT2SAM(0.5, 8)
    PRINT *, "Test 1: Expected 192, Got ", result

    result = PT2SAM(-0.5, 16)
    PRINT *, "Test 2: Expected -16384, Got ", result

    result = PT2SAM(2.0, 8)  ! This should get normalized to 1.0
    PRINT *, "Test 3: Expected 255, Got ", result

CONTAINS

    INTEGER FUNCTION PT2SAM(PT, BITS)
        REAL, INTENT(IN) :: PT
        INTEGER, INTENT(IN) :: BITS
        REAL :: PT_Modified

        PT_Modified = PT
        IF (ABS(PT_Modified) > 1.0) THEN
            PT_Modified = PT_Modified / ABS(PT_Modified)
        END IF

        IF (BITS /= 8) THEN
            PT2SAM = INT(PT_Modified * (2**(BITS-1)-1) + 0.5)
        ELSE
            PT2SAM = INT((PT_Modified*0.5 + 0.5)*(2**BITS - 1) + 0.5)
        END IF
    END FUNCTION PT2SAM

END PROGRAM TestPT2SAM