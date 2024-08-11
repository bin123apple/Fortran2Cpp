PROGRAM Test_iau_PXP

  IMPLICIT NONE

  DOUBLE PRECISION A(3), B(3), AXB(3)

  ! Example input vectors
  A(1) = 1.0
  A(2) = 2.0
  A(3) = 3.0
  B(1) = 4.0
  B(2) = 5.0
  B(3) = 6.0

  ! Call the subroutine
  CALL iau_PXP(A, B, AXB)

  ! Print the result
  PRINT *, 'AXB = ', AXB(1), AXB(2), AXB(3)

END PROGRAM Test_iau_PXP

SUBROUTINE iau_PXP ( A, B, AXB )

  IMPLICIT NONE

  DOUBLE PRECISION A(3), B(3), AXB(3)

  DOUBLE PRECISION XA, YA, ZA, XB, YB, ZB

  XA = A(1)
  YA = A(2)
  ZA = A(3)
  XB = B(1)
  YB = B(2)
  ZB = B(3)
  AXB(1) = YA*ZB - ZA*YB
  AXB(2) = ZA*XB - XA*ZB
  AXB(3) = XA*YB - YA*XB

END SUBROUTINE iau_PXP