PROGRAM TestILADLC
    IMPLICIT NONE
    INTEGER :: M, N, LDA, result
    DOUBLE PRECISION, DIMENSION(3, 4) :: A

    ! Initialize matrix A
    A(1, 1) = 0.0D0
    A(1, 2) = 0.0D0
    A(1, 3) = 0.0D0
    A(1, 4) = 0.0D0
    A(2, 1) = 0.0D0
    A(2, 2) = 1.0D0
    A(2, 3) = 0.0D0
    A(2, 4) = 0.0D0
    A(3, 1) = 0.0D0
    A(3, 2) = 0.0D0
    A(3, 3) = 0.0D0
    A(3, 4) = 0.0D0

    ! Set the dimensions
    M = 3
    N = 4
    LDA = 3

    ! Call the function
    result = ILADLC(M, N, A, LDA)

    ! Print the result
    PRINT *, 'Result of ILADLC:', result

CONTAINS

    INTEGER FUNCTION ILADLC(M, N, A, LDA)
        IMPLICIT NONE
        INTEGER, INTENT(IN) :: M, N, LDA
        DOUBLE PRECISION, INTENT(IN) :: A(LDA, *)
        INTEGER I
        DOUBLE PRECISION ZERO
        PARAMETER (ZERO = 0.0D0)

        IF (N.EQ.0 .OR. A(1, N).NE.ZERO .OR. A(M, N).NE.ZERO) THEN
            ILADLC = N
        ELSE
            DO ILADLC = N, 1, -1
                DO I = 1, M
                    IF (A(I, ILADLC).NE.ZERO) RETURN
                END DO
            END DO
        END IF
        RETURN
    END FUNCTION ILADLC

END PROGRAM TestILADLC