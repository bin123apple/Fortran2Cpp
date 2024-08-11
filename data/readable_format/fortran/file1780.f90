PROGRAM TestYIQRGB
  IMPLICIT NONE
  REAL :: Y, I, Q, R, G, B

  ! Test case 1
  Y = 0.5
  I = 0.2
  Q = -0.3
  CALL YIQRGB(Y, I, Q, R, G, B)
  PRINT *, "Test 1: ", R, G, B

  ! Test case 2
  Y = 0.1
  I = 0.9
  Q = 0.2
  CALL YIQRGB(Y, I, Q, R, G, B)
  PRINT *, "Test 2: ", R, G, B

  ! Test case 3
  Y = 0.9
  I = -0.4
  Q = 0.6
  CALL YIQRGB(Y, I, Q, R, G, B)
  PRINT *, "Test 3: ", R, G, B
END PROGRAM TestYIQRGB

SUBROUTINE YIQRGB(Y, I, Q, R, G, B)
  REAL :: R, G, B, Y, I, Q
  R = Y +  .956*I +  .621*Q
  G = Y -  .272*I -  .647*Q
  B = Y - 1.105*I + 1.702*Q
  R = MIN(MAX(R, 0.), 1.)
  G = MIN(MAX(G, 0.), 1.)
  B = MIN(MAX(B, 0.), 1.)
END SUBROUTINE YIQRGB