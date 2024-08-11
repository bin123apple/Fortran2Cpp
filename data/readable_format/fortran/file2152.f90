PROGRAM MAIN
    IMPLICIT NONE
    REAL :: result
    REAL, DIMENSION(3) :: A = (/1.0, 2.0, 3.0/)
    REAL, DIMENSION(3) :: B = (/4.0, 5.0, 6.0/)
    LOGICAL :: MATRIX_ERROR

    ! Calculate dot product
    result = MULT(A, B, MATRIX_ERROR)

    ! Print the result
    PRINT *, 'Dot product: ', result

    ! Check for errors
    IF (MATRIX_ERROR) THEN
        PRINT *, 'An error occurred during the dot product calculation.'
    ELSE
        PRINT *, 'Calculation was successful.'
    END IF

CONTAINS

    REAL FUNCTION MULT(A, B, MATRIX_ERROR)
        REAL, INTENT(IN) :: A(:), B(:)
        LOGICAL, INTENT(OUT) :: MATRIX_ERROR
        INTEGER :: I
        LOGICAL :: OVERFLOW
        EXTERNAL :: IEEE_GET_FLAG
        MATRIX_ERROR = .FALSE.

        IF (SIZE(A) /= SIZE(B)) THEN
            MATRIX_ERROR = .TRUE.
            RETURN
        END IF

        MULT = 0.0
        DO I = 1, SIZE(A)
            MULT = MULT + A(I)*B(I)
        END DO

        ! Assuming IEEE_GET_FLAG is used to check for overflow, but not defined here.
        ! This is just an example, as actual overflow checking would require specific implementation.
        ! CALL IEEE_GET_FLAG(IEEE_OVERFLOW, OVERFLOW)
        ! IF (OVERFLOW) MATRIX_ERROR = .TRUE.
    END FUNCTION MULT
END PROGRAM MAIN