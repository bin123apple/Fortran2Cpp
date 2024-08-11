PROGRAM test_ilazlrquad
  IMPLICIT NONE
  INTEGER :: result
  COMPLEX(KIND=16) :: A(4,4)
  INTEGER :: M, N, LDA

  ! Initialize the matrix A with zeros
  A = CMPLX(0.0q0, 0.0q0, KIND=16)
  
  ! Test case 1: Non-zero element at the lower left corner
  M = 4
  N = 4
  LDA = 4
  A(4,1) = CMPLX(1.0q0, 1.0q0, KIND=16) ! Set one element to be non-zero to test the functionality
  result = ilazlrquad(M, N, A, LDA)
  PRINT *, "Test Case 1: Expected 4, got ", result

  ! You can add more test cases here following the same pattern

CONTAINS

  INTEGER FUNCTION ilazlrquad(M, N, A, LDA)
    INTEGER, INTENT(IN) :: M, N, LDA
    COMPLEX(KIND=16), INTENT(IN) :: A(LDA, *)
    COMPLEX(KIND=16) :: ZERO
    INTEGER :: I, J

    ZERO = CMPLX(0.0q0, 0.0q0, KIND=16)

    IF (M == 0) THEN
       ilazlrquad = M
    ELSE IF (A(M, 1) /= ZERO .OR. A(M, N) /= ZERO) THEN
       ilazlrquad = M
    ELSE
       ilazlrquad = 0
       DO J = 1, N
          I = M
          DO WHILE (A(MAX(I,1), J) == ZERO .AND. I >= 1)
             I = I - 1
          END DO
          ilazlrquad = MAX(ilazlrquad, I)
       END DO
    END IF
  END FUNCTION ilazlrquad

END PROGRAM test_ilazlrquad