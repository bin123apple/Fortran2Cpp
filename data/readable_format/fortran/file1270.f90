MODULE RotationModule
  IMPLICIT NONE
CONTAINS
  SUBROUTINE iau_RV2M(W, R)
    DOUBLE PRECISION, INTENT(IN) :: W(3)
    DOUBLE PRECISION, INTENT(OUT) :: R(3,3)
    DOUBLE PRECISION :: X, Y, Z, PHI, S, C, F
    X = W(1)
    Y = W(2)
    Z = W(3)
    PHI = SQRT(X*X + Y*Y + Z*Z)
    S = SIN(PHI)
    C = COS(PHI)
    F = 1D0 - C
    IF (PHI > 0D0) THEN
       X = X / PHI
       Y = Y / PHI
       Z = Z / PHI
    END IF
    R(1,1) = X*X*F + C
    R(1,2) = X*Y*F + Z*S
    R(1,3) = X*Z*F - Y*S
    R(2,1) = Y*X*F - Z*S
    R(2,2) = Y*Y*F + C
    R(2,3) = Y*Z*F + X*S
    R(3,1) = Z*X*F + Y*S
    R(3,2) = Z*Y*F - X*S
    R(3,3) = Z*Z*F + C
  END SUBROUTINE iau_RV2M
END MODULE RotationModule

PROGRAM TestRV2M
  USE RotationModule
  IMPLICIT NONE
  DOUBLE PRECISION :: W(3), R(3,3), Expected(3,3)
  INTEGER :: i, j

  ! Initialize test variables, call subroutines, and define expected outcomes here

  ! Test 1: Zero vector
  W = 0.0
  CALL iau_RV2M(W, R)
  CALL IdentityMatrix(Expected)
  CALL AssertMatrixEqual(R, Expected, "Test 1: Zero vector")

  ! You can add more tests here following the same structure

CONTAINS

  SUBROUTINE AssertMatrixEqual(A, B, Message)
    DOUBLE PRECISION, INTENT(IN) :: A(3,3), B(3,3)
    CHARACTER(LEN=*), INTENT(IN) :: Message
    DOUBLE PRECISION :: Tolerance
    INTEGER :: i, j
    Tolerance = 1.0D-10
    DO i = 1, 3
      DO j = 1, 3
        IF (ABS(A(i,j) - B(i,j)) > Tolerance) THEN
          PRINT *, TRIM(Message), ": Failed"
          RETURN
        END IF
      END DO
    END DO
    PRINT *, TRIM(Message), ": Passed"
  END SUBROUTINE AssertMatrixEqual

  SUBROUTINE IdentityMatrix(Mat)
    DOUBLE PRECISION, INTENT(OUT) :: Mat(3,3)
    INTEGER :: i, j
    DO i = 1, 3
      DO j = 1, 3
        IF (i == j) THEN
          Mat(i, j) = 1.0
        ELSE
          Mat(i, j) = 0.0
        END IF
      END DO
    END DO
  END SUBROUTINE IdentityMatrix

END PROGRAM TestRV2M