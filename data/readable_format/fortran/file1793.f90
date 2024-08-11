! combined.f90
PROGRAM MainProgram
    IMPLICIT NONE
    REAL, DIMENSION(5) :: arr = (/1.0, 2.0, 3.0, 4.0, 5.0/)
    INTEGER :: i

    CALL squareArray(arr, 5)

    DO i = 1, 5
        PRINT *, 'arr(', i, ') = ', arr(i)
    END DO
END PROGRAM MainProgram

SUBROUTINE squareArray(arr, n)
    IMPLICIT NONE
    INTEGER, INTENT(IN) :: n
    REAL, INTENT(INOUT) :: arr(n)
    INTEGER :: i

    DO i = 1, n
        arr(i) = arr(i)**2
    END DO
END SUBROUTINE squareArray