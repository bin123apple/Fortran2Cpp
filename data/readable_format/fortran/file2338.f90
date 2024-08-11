PROGRAM TestILASLC
  IMPLICIT NONE
  INTEGER :: M, N, result
  REAL, DIMENSION(3, 3) :: A

  ! Initialize the matrix
  A(1, 1) = 0.0
  A(1, 2) = 0.0
  A(1, 3) = 0.0
  A(2, 1) = 0.0
  A(2, 2) = 0.0
  A(2, 3) = 0.0
  A(3, 1) = 0.0
  A(3, 2) = 0.0
  A(3, 3) = 3.0

  M = 3
  N = 3

  ! Call the ILASLC function
  result = ILASLC(M, N, A, 3)

  ! Print the result
  PRINT *, 'Result: ', result

CONTAINS
  
  INTEGER FUNCTION ILASLC(M, N, A, LDA)
    INTEGER, INTENT(IN) :: M, N, LDA
    REAL, DIMENSION(LDA, *), INTENT(IN) :: A
    REAL, PARAMETER :: ZERO = 0.0E+0
    INTEGER :: I, J
    
    ILASLC = 0
    IF (N == 0) THEN
        ILASLC = N
    ELSE
        DO J = N, 1, -1
            DO I = 1, M
                IF (A(I,J) /= ZERO) THEN
                    ILASLC = J
                    RETURN
                END IF
            END DO
        END DO
    END IF
  END FUNCTION ILASLC

END PROGRAM TestILASLC