PROGRAM test_cddiv
  IMPLICIT NONE
  DOUBLE PRECISION A(2), B(2), C(2)
  
  ! Test 1: Dividing two positive complex numbers
  A = [2.0D0, 3.0D0]
  B = [4.0D0, 5.0D0]
  CALL CDDIV(A,B,C)
  PRINT *, 'Test 1: ', C
  
  ! Test 2: Dividing two negative complex numbers
  A = [-2.0D0, -3.0D0]
  B = [-4.0D0, -5.0D0]
  CALL CDDIV(A,B,C)
  PRINT *, 'Test 2: ', C
  
  ! Test 3: Dividing a positive by a negative complex number
  A = [2.0D0, 3.0D0]
  B = [-4.0D0, -5.0D0]
  CALL CDDIV(A,B,C)
  PRINT *, 'Test 3: ', C
  
  ! Test 4: Real part of divisor is 0
  A = [1.0D0, 2.0D0]
  B = [0.0D0, 1.0D0]
  CALL CDDIV(A,B,C)
  PRINT *, 'Test 4: ', C

  ! Test 5: Imaginary part of divisor is 0
  A = [1.0D0, 2.0D0]
  B = [1.0D0, 0.0D0]
  CALL CDDIV(A,B,C)
  PRINT *, 'Test 5: ', C

CONTAINS

  SUBROUTINE CDDIV(A,B,C)
    DOUBLE PRECISION A(2),B(2),C(2),G,H,T
    IF ( DABS(B(1)) .GT. DABS(B(2)) ) THEN
      H = B(1)/B(2)
      G = H*B(1) + B(2)
      T = A(1)
      C(1) = (H * T  + A(2))/G
      C(2) = (H * A(2) - T)/G
    ELSE
      H = B(2)/B(1)
      G = H*B(2) + B(1)
      T = A(1)
      C(1) = ( T  + H * A(2))/G
      C(2) = (A(2) - H * T)/G
    END IF
  END SUBROUTINE CDDIV

END PROGRAM test_cddiv