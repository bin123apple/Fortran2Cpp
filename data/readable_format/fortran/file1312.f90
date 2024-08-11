PROGRAM TestDLADIV
  IMPLICIT NONE
  DOUBLE PRECISION A, B, C, D, P, Q

  ! Test case 1: ABS(D) < ABS(C)
  A = 1.0
  B = 2.0
  C = 3.0
  D = 1.0
  CALL DLADIV(A, B, C, D, P, Q)
  PRINT *, "Test 1: P =", P, "Q =", Q

  ! Test case 2: ABS(D) >= ABS(C)
  A = 2.0
  B = 3.0
  C = 1.0
  D = 3.0
  CALL DLADIV(A, B, C, D, P, Q)
  PRINT *, "Test 2: P =", P, "Q =", Q

CONTAINS

  SUBROUTINE DLADIV( A, B, C, D, P, Q )
    DOUBLE PRECISION   A, B, C, D, P, Q
    DOUBLE PRECISION   E, F
    INTRINSIC          ABS

    IF( ABS( D ).LT.ABS( C ) ) THEN
       E = D / C
       F = C + D*E
       P = ( A+B*E ) / F
       Q = ( B-A*E ) / F
    ELSE
       E = C / D
       F = D + C*E
       P = ( B+A*E ) / F
       Q = ( -A+B*E ) / F
    END IF

    RETURN
  END SUBROUTINE DLADIV

END PROGRAM TestDLADIV