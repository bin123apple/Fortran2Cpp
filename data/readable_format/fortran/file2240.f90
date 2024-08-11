MODULE vast_kind_param
  INTEGER, PARAMETER :: DOUBLE = SELECTED_REAL_KIND(15, 307)
END MODULE vast_kind_param

MODULE zerom_I
  INTERFACE
    SUBROUTINE zerom(X, M)
      USE vast_kind_param, ONLY: DOUBLE
      INTEGER, INTENT(IN) :: M
      REAL(DOUBLE), DIMENSION(M, M), INTENT(OUT) :: X
    END SUBROUTINE
  END INTERFACE
END MODULE zerom_I

SUBROUTINE zerom(X, M)
  USE vast_kind_param, ONLY: DOUBLE
  INTEGER, INTENT(IN) :: M
  REAL(DOUBLE), DIMENSION(M, M), INTENT(OUT) :: X
  INTEGER :: i, j

  DO i = 1, M
    DO j = 1, M
      X(i, j) = 0.0_DOUBLE
    END DO
  END DO
END SUBROUTINE zerom

PROGRAM test_zerom
  USE zerom_I
  USE vast_kind_param, ONLY: DOUBLE
  IMPLICIT NONE

  INTEGER :: M
  REAL(DOUBLE), ALLOCATABLE :: X(:,:)
  INTEGER :: i, j
  LOGICAL :: test_passed

  M = 5
  ALLOCATE(X(M, M))

  CALL zerom(X, M)

  test_passed = .TRUE.
  DO i = 1, M
    DO j = 1, M
      IF (X(i, j) /= 0.0_DOUBLE) THEN
        test_passed = .FALSE.
      END IF
    END DO
  END DO

  IF (test_passed) THEN
    PRINT *, 'Fortran test passed.'
  ELSE
    PRINT *, 'Fortran test failed.'
  END IF

END PROGRAM test_zerom