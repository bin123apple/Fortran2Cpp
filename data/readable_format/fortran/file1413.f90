MODULE mo_column
  IMPLICIT NONE
CONTAINS
  SUBROUTINE compute(nz, q, t)
    INTEGER, INTENT(IN) :: nz
    REAL, DIMENSION(nz), INTENT(INOUT) :: q, t
    INTEGER :: i
    ! Dummy compute operation: add 1.0 to q and 2.0 to t
    DO i = 1, nz
      q(i) = q(i) + 1.0
      t(i) = t(i) + 2.0
    END DO
  END SUBROUTINE compute
END MODULE mo_column

PROGRAM test_abstraction4
  USE mo_column, ONLY: compute
  REAL, DIMENSION(20,60) :: q, t
  INTEGER :: nproma, nz, p, i, j
  REAL :: sum_q, sum_t

  nproma = 20
  nz = 60

  ! Initialize arrays
  DO p = 1, nproma
    DO i = 1, nz
      q(p, i) = 0.0
      t(p, i) = 0.0
    END DO
  END DO

  ! Apply compute to each column
  DO p = 1, nproma
    CALL compute(nz, q(p, :), t(p, :))
  END DO

  ! Calculate sum of q and t for a simple verification
  sum_q = 0.0
  sum_t = 0.0
  DO j = 1, nproma
    DO i = 1, nz
      sum_q = sum_q + q(j, i)
      sum_t = sum_t + t(j, i)
    END DO
  END DO

  PRINT*, 'Sum of q:', sum_q
  PRINT*, 'Sum of t:', sum_t

  ! Simple test to verify correctness
  IF (ALL(q == 1.0) .AND. ALL(t == 2.0)) THEN
    PRINT*, 'Test Passed'
  ELSE
    PRINT*, 'Test Failed'
  END IF
END PROGRAM test_abstraction4