PROGRAM TestShGivens
  IMPLICIT NONE
  REAL :: A, B, C, S

  ! Test case 1
  A = 3.0
  B = 4.0
  CALL SHGIVENS(A, B, C, S)
  PRINT *, "Test 1: A =", A, "B =", B, "C =", C, "S =", S

  ! Test case 2
  A = 1.0
  B = 0.0
  CALL SHGIVENS(A, B, C, S)
  PRINT *, "Test 2: A =", A, "B =", B, "C =", C, "S =", S

  ! Feel free to add more test cases here

CONTAINS

  SUBROUTINE SHGIVENS(A, B, C, S)
    REAL, INTENT(INOUT) :: A, B
    REAL, INTENT(OUT) :: C, S
    REAL :: AA, BB, R, U, V

    AA = A
    BB = B
    IF (ABS(AA) > ABS(BB)) THEN
      U = AA + AA
      V = BB / U
      IF (ABS(V) < 1.E-25) V = 0.
      R = SQRT(0.25 + V*V) * U
      C = AA / R
      S = V * (C + C)
      B = S
      A = R
    ELSE
      IF (BB /= 0.) THEN
        U = BB + BB
        V = AA / U
        IF (ABS(V) < 1.E-25) V = 0.
        A = SQRT(0.25 + V*V) * U
        S = BB / A
        C = V * (S + S)
        B = 1.
        IF (C /= 0.) B = 1. / C
      ELSE
        C = 1.
        S = 0.
      END IF
    END IF
  END SUBROUTINE SHGIVENS

END PROGRAM TestShGivens