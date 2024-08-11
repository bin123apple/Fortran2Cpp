PROGRAM test_csswptst
  IMPLICIT NONE
  DOUBLE PRECISION, ALLOCATABLE :: X(:), Y(:), Z(:)
  LOGICAL :: result

  ALLOCATE(X(4), Y(4), Z(4))

  ! Define test coordinates
  X = (/0.0, 1.0, 0.0, -1.0/)
  Y = (/0.0, 0.0, 1.0, 0.0/)
  Z = (/1.0, 1.0, 1.0, 1.0/)

  ! Test 1
  result = CSSWPTST(1, 2, 3, 4, X, Y, Z)
  PRINT *, "Test 1 result: ", result

  ! Test 2: Change order of points
  result = CSSWPTST(3, 1, 2, 4, X, Y, Z)
  PRINT *, "Test 2 result: ", result

CONTAINS

  LOGICAL FUNCTION CSSWPTST(N1, N2, N3, N4, X, Y, Z)
    INTEGER, INTENT(IN) :: N1, N2, N3, N4
    DOUBLE PRECISION, INTENT(IN) :: X(*), Y(*), Z(*)
    DOUBLE PRECISION :: DX1, DX2, DX3, DY1, DY2, DY3, DZ1, DZ2, DZ3, X4, Y4, Z4

    X4 = X(N4)
    Y4 = Y(N4)
    Z4 = Z(N4)
    DX1 = X(N1) - X4
    DX2 = X(N2) - X4
    DX3 = X(N3) - X4
    DY1 = Y(N1) - Y4
    DY2 = Y(N2) - Y4
    DY3 = Y(N3) - Y4
    DZ1 = Z(N1) - Z4
    DZ2 = Z(N2) - Z4
    DZ3 = Z(N3) - Z4

    CSSWPTST = (DX3*(DY2*DZ1 - DY1*DZ2) - DY3*(DX2*DZ1 - DX1*DZ2) + DZ3*(DX2*DY1 - DX1*DY2)) > 0.0D0
  END FUNCTION CSSWPTST

END PROGRAM test_csswptst