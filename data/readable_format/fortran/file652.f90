PROGRAM main
  USE, INTRINSIC :: ISO_FORTRAN_ENV, ONLY: REAL64
  IMPLICIT NONE

  INTEGER :: NVAR, MINEAR, NFIRST, NCUT, i, j
  REAL(REAL64), ALLOCATABLE :: A(:,:), VNERT(:), PNERT(:), B(:,:)

  ! Example initialization for demonstration
  NVAR = 3
  MINEAR = 2
  NFIRST = 1
  ALLOCATE(A(MINEAR,NVAR), VNERT(NVAR), PNERT(NVAR), B(MINEAR,NVAR))

  ! Initialize with some example values, ensuring all constants are REAL(8)
  A = RESHAPE([1.0_REAL64, 2.0_REAL64, 3.0_REAL64, 4.0_REAL64, 5.0_REAL64, 6.0_REAL64], SHAPE(A))
  VNERT = [1.0_REAL64, 2.0_REAL64, 3.0_REAL64]
  PNERT = [0.5_REAL64, 1.5_REAL64, 2.5_REAL64]

  CALL deri21(A, NVAR, MINEAR, NFIRST, VNERT, PNERT, B, NCUT)

  ! Example output
  PRINT *, 'NCUT:', NCUT
  DO i = 1, MINEAR
    PRINT *, B(i,:)
  END DO

CONTAINS

  SUBROUTINE deri21(A, NVAR, MINEAR, NFIRST, VNERT, PNERT, B, NCUT)
    INTEGER, INTENT(IN) :: NVAR, MINEAR, NFIRST
    REAL(REAL64), INTENT(IN) :: A(MINEAR,NVAR)
    REAL(REAL64), INTENT(INOUT) :: VNERT(NVAR), PNERT(NVAR)
    REAL(REAL64), INTENT(OUT) :: B(MINEAR,NVAR)
    INTEGER, INTENT(OUT) :: NCUT
    
    ! Placeholder for actual logic
    NCUT = 0 ! Example assignment, replace with actual logic

    ! Example: Fill B with zeros (replace with actual logic)
    B = 0.0_REAL64

  END SUBROUTINE deri21

END PROGRAM main