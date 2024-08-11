PROGRAM testDLADIV
  IMPLICIT NONE
  DOUBLE PRECISION A, B, C, D, P, Q

  ! Test 1
  A = 1.0
  B = 2.0
  C = 3.0
  D = 4.0
  CALL DLADIV(A, B, C, D, P, Q)
  PRINT *, "Test 1: P =", P, " Q =", Q

  ! Test 2
  A = 5.0
  B = 6.0
  C = 7.0
  D = 8.0
  CALL DLADIV(A, B, C, D, P, Q)
  PRINT *, "Test 2: P =", P, " Q =", Q

  ! Add more tests as needed
  
CONTAINS

  SUBROUTINE DLADIV( A, B, C, D, P, Q )
    DOUBLE PRECISION A, B, C, D, P, Q
    DOUBLE PRECISION E, F
    INTRINSIC ABS

    IF( ABS( D ) .LT. ABS( C ) ) THEN
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

END PROGRAM testDLADIV