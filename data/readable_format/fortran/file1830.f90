PROGRAM Main
  IMPLICIT NONE

  ! Assuming nmeci's value for demonstration purposes. Replace with the actual value.
  INTEGER, PARAMETER :: nmeci = 2
  INTEGER, PARAMETER :: nvar = 3, minear = 2, ninear = 2
  REAL(8), DIMENSION(minear,nvar) :: F
  REAL(8), DIMENSION(ninear,nvar) :: FD
  REAL(8), DIMENSION(ninear,nmeci*(nmeci + 1)*10/ninear) :: FCI
  REAL(8), DIMENSION(nvar) :: GRAD
  REAL(8) :: THROLD
  REAL(8), DIMENSION(nvar) :: DIAG
  REAL(8), DIMENSION(1) :: SCALAR

  ! Initialize variables
  F = RESHAPE([1.0d0, 2.0d0, 3.0d0, 4.0d0, 5.0d0, 6.0d0], SHAPE(F))
  FD = 0.0
  FCI = 0.0
  GRAD = 0.0
  THROLD = 1.0d0
  DIAG = 0.0
  SCALAR = 0.0

  ! Call the subroutine
  CALL deri2(minear, F, FD, FCI, ninear, nvar, GRAD, THROLD, DIAG, SCALAR)

  ! Output for demonstration
  PRINT *, 'GRAD:', GRAD

CONTAINS
  SUBROUTINE deri2 (MINEAR, F, FD, FCI, NINEAR, NVAR, GRAD, THROLD, DIAG, SCALAR)
    INTEGER, INTENT(IN) :: NINEAR, MINEAR, NVAR
    REAL(8), DIMENSION(MINEAR,NVAR), INTENT(INOUT) :: F
    REAL(8), DIMENSION(NINEAR,NVAR) :: FD
    REAL(8), DIMENSION(NINEAR,NMECI*(NMECI + 1)*10/NINEAR) :: FCI
    REAL(8), DIMENSION(NVAR), INTENT(INOUT) :: GRAD
    REAL(8), INTENT(IN) :: THROLD
    REAL(8), DIMENSION(*) :: DIAG
    REAL(8), DIMENSION(*), INTENT(IN) :: SCALAR

    INTEGER :: i, j
    ! Simplified logic for demonstration
    DO i = 1, NVAR
      GRAD(i) = 0.0d0
      DO j = 1, MINEAR
        GRAD(i) = GRAD(i) + F(j, i)
      END DO
      GRAD(i) = GRAD(i) / MINEAR
    END DO
  END SUBROUTINE deri2

END PROGRAM Main