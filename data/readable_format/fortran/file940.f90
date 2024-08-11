PROGRAM MatrixInversionTest
  IMPLICIT NONE

  INTEGER, PARAMETER :: dp = KIND(1.0D0)
  REAL :: matSingle(2,2), invMatSingle(2,2)
  REAL(KIND=dp) :: matDouble(2,2), invMatDouble(2,2)
  ! Initialize matrices
  matSingle = RESHAPE([1.0, 2.0, 3.0, 4.0], [2,2])
  matDouble = RESHAPE([1.0D0, 2.0D0, 3.0D0, 4.0D0], [2,2])

  ! Invert single precision matrix
  CALL matInv2x2_s(matSingle, invMatSingle)
  PRINT *, "Inverted Single Precision Matrix:"
  PRINT *, invMatSingle

  ! Invert double precision matrix
  CALL matInv2x2_d(matDouble, invMatDouble)
  PRINT *, "Inverted Double Precision Matrix:"
  PRINT *, invMatDouble

CONTAINS

  SUBROUTINE matInv2x2_s(matrix, inverse)
    REAL, INTENT(IN) :: matrix(2,2)
    REAL, INTENT(OUT) :: inverse(2,2)
    REAL :: det
    det = matrix(1,1) * matrix(2,2) - matrix(1,2) * matrix(2,1)
    IF (det == 0.0) THEN
      PRINT *, "Matrix is singular and cannot be inverted."
    ELSE
      inverse(1,1) = matrix(2,2) / det
      inverse(2,2) = matrix(1,1) / det
      inverse(1,2) = -matrix(1,2) / det
      inverse(2,1) = -matrix(2,1) / det
    END IF
  END SUBROUTINE matInv2x2_s

  SUBROUTINE matInv2x2_d(matrix, inverse)
    REAL(KIND=dp), INTENT(IN) :: matrix(2,2)
    REAL(KIND=dp), INTENT(OUT) :: inverse(2,2)
    REAL(KIND=dp) :: det
    det = matrix(1,1) * matrix(2,2) - matrix(1,2) * matrix(2,1)
    IF (det == 0.0D0) THEN
      PRINT *, "Matrix is singular and cannot be inverted."
    ELSE
      inverse(1,1) = matrix(2,2) / det
      inverse(2,2) = matrix(1,1) / det
      inverse(1,2) = -matrix(1,2) / det
      inverse(2,1) = -matrix(2,1) / det
    END IF
  END SUBROUTINE matInv2x2_d

END PROGRAM MatrixInversionTest