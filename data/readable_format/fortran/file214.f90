MODULE ConversionRoutines
    IMPLICIT NONE
CONTAINS
    SUBROUTINE INTG2REAL(SIZE, INTG, GRID)
        INTEGER, INTENT(IN) :: SIZE
        INTEGER, INTENT(IN) :: INTG(SIZE)
        REAL, INTENT(OUT) :: GRID(SIZE)
        INTEGER :: I

        DO I = 1, SIZE
            GRID(I) = REAL(INTG(I))
        END DO
    END SUBROUTINE INTG2REAL

    SUBROUTINE INT82REAL(SIZE, INT8, GRID)
        INTEGER, INTENT(IN) :: SIZE
        INTEGER(KIND=8), INTENT(IN) :: INT8(SIZE)
        REAL, INTENT(OUT) :: GRID(SIZE)
        INTEGER :: I

        DO I = 1, SIZE
            GRID(I) = REAL(INT8(I))
        END DO
    END SUBROUTINE INT82REAL
END MODULE ConversionRoutines

PROGRAM TestConversions
    USE ConversionRoutines
    IMPLICIT NONE
    INTEGER, PARAMETER :: SIZE = 3
    INTEGER :: testIntg(SIZE) = [1, 0, -1]
    INTEGER(KIND=8) :: testInt8(SIZE) = [2147483647_8, 0_8, -2147483648_8]
    REAL :: testGrid(SIZE)
    INTEGER :: I

    ! Testing INTG2REAL
    CALL INTG2REAL(SIZE, testIntg, testGrid)
    PRINT *, "INTG2REAL Results:"
    DO I = 1, SIZE
        PRINT *, testGrid(I)
    END DO

    ! Testing INT82REAL
    CALL INT82REAL(SIZE, testInt8, testGrid)
    PRINT *, "INT82REAL Results:"
    DO I = 1, SIZE
        PRINT *, testGrid(I)
    END DO
END PROGRAM TestConversions