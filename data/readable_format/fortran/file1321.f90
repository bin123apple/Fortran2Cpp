PROGRAM P
    IMPLICIT NONE
    CHARACTER(LEN=1024), DIMENSION(:), ALLOCATABLE :: X1
    INTEGER :: i

    ! Allocate and initialize test data
    ALLOCATE(X1(2))
    X1(1) = 'Test1'
    X1(2) = 'Test2'

    ! Call the subroutine
    CALL S(X1)

    ! Print the results
    DO i = 1, SIZE(X1)
        PRINT *, TRIM(X1(i))
    END DO

CONTAINS
    SUBROUTINE S(X)
        CHARACTER(LEN=*), DIMENSION(:), INTENT(INOUT) :: X
        INTEGER :: j

        ! Append a suffix to each string
        DO j = 1, SIZE(X)
            X(j) = TRIM(X(j)) // "_suffix"
        END DO
    END SUBROUTINE S
END PROGRAM P