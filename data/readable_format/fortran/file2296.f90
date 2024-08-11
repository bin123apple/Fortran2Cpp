PROGRAM TestPLTFRC
    IMPLICIT NONE

    ! Test cases
    CALL TestCase(3.14, 0.14)
    CALL TestCase(-2.71, 0.29)  ! Adjusted expected value to match C++ behavior
    CALL TestCase(5.0, 0.0)

CONTAINS

    FUNCTION PLTFRC(REALN)
        REAL :: REALN
        REAL :: PLTFRC

        PLTFRC = REALN - FLOOR(REALN)
        RETURN
    END FUNCTION PLTFRC

    SUBROUTINE TestCase(input, expected)
        REAL :: input, expected, result
        result = PLTFRC(input)
        IF (ABS(result - expected) < 1.0E-6) THEN
            PRINT *, "Test passed for input ", input
        ELSE
            PRINT *, "Test failed for input ", input, " Expected ", expected, " but got ", result
        END IF
    END SUBROUTINE TestCase

END PROGRAM TestPLTFRC