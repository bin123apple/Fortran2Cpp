PROGRAM TestFortranCode
    IMPLICIT NONE
    INTEGER :: I
    COMPLEX :: Z
    LOGICAL :: L
    INTEGER, DIMENSION(2) :: B

    ! Test INTEGER condition
    I = 0
    CALL testInteger(I)
    I = -1
    CALL testInteger(I)
    I = 1
    CALL testInteger(I)

    ! Test COMPLEX condition
    Z = (0.0, 0.0)
    CALL testComplex(Z)
    Z = (1.0, 0.0)
    CALL testComplex(Z)

    ! Test LOGICAL condition
    L = .TRUE.
    CALL testLogical(L)
    L = .FALSE.
    CALL testLogical(L)

    ! Test ARRAY condition
    B = (/0, 0/)
    CALL testArray(B)
    B = (/1, 0/)
    CALL testArray(B)

CONTAINS

    SUBROUTINE testInteger(I)
        INTEGER, INTENT(IN) :: I
        IF (I > 0) THEN
            PRINT *, 'INTEGER positive branch'
        ELSEIF (I == 0) THEN
            PRINT *, 'INTEGER zero branch'
        ELSE
            PRINT *, 'INTEGER negative branch'
        END IF
    END SUBROUTINE testInteger

    SUBROUTINE testComplex(Z)
        COMPLEX, INTENT(IN) :: Z
        IF (ABS(Z) > 0.0) THEN
            PRINT *, 'COMPLEX non-zero branch'
        ELSE
            PRINT *, 'COMPLEX zero branch'
        END IF
    END SUBROUTINE testComplex

    SUBROUTINE testLogical(L)
        LOGICAL, INTENT(IN) :: L
        IF (L) THEN
            PRINT *, 'LOGICAL TRUE branch'
        ELSE
            PRINT *, 'LOGICAL FALSE branch'
        END IF
    END SUBROUTINE testLogical

    SUBROUTINE testArray(B)
        INTEGER, DIMENSION(2), INTENT(IN) :: B
        IF (ANY(B /= 0)) THEN
            PRINT *, 'ARRAY non-zero branch'
        ELSE
            PRINT *, 'ARRAY all-zero branch'
        END IF
    END SUBROUTINE testArray

END PROGRAM TestFortranCode