PROGRAM test_tf
  USE, INTRINSIC :: iso_fortran_env, ONLY: dp => REAL64
  IMPLICIT NONE
  INTEGER :: NORBS, i, j
  REAL(dp), ALLOCATABLE :: UA(:,:), GA(:,:), UB(:,:), GB(:,:), T(:,:)

  NORBS = 2
  ALLOCATE(UA(NORBS,NORBS), GA(NORBS,NORBS), UB(NORBS,NORBS), GB(NORBS,NORBS), T(NORBS,NORBS))

  ! Initialize matrices
  UA = RESHAPE([1.0_dp, 2.0_dp, 3.0_dp, 4.0_dp], SHAPE(UA))
  GA = RESHAPE([0.5_dp, 0.5_dp, 0.5_dp, 0.5_dp], SHAPE(GA))
  UB = RESHAPE([1.0_dp, 1.0_dp, 1.0_dp, 1.0_dp], SHAPE(UB))
  GB = RESHAPE([0.2_dp, 0.2_dp, 0.2_dp, 0.2_dp], SHAPE(GB))

  CALL tf(UA, GA, UB, GB, T, NORBS)

  PRINT *, "T Matrix:"
  DO i = 1, NORBS
    PRINT *, T(i, :)
  END DO

  CONTAINS

    SUBROUTINE tf(UA, GA, UB, GB, T, NORBS)
      INTEGER, INTENT(IN) :: NORBS
      INTEGER :: i, j
      REAL(dp), DIMENSION(NORBS,NORBS), INTENT(IN) :: UA, GA, UB, GB
      REAL(dp), DIMENSION(NORBS,NORBS), INTENT(OUT) :: T

      DO i = 1, NORBS
        DO j = 1, NORBS
          T(i, j) = UA(i, j) + GA(i, j) - UB(i, j) - GB(i, j)
        END DO
      END DO
    END SUBROUTINE tf

END PROGRAM test_tf