MODULE mo_column
  IMPLICIT NONE
CONTAINS
  SUBROUTINE compute(nz, b, q_subarray, t_subarray)
    INTEGER, INTENT(IN) :: nz, b
    REAL, INTENT(INOUT) :: q_subarray(nz), t_subarray(b)
    INTEGER :: i
    ! Increment each element by 1.0
    DO i = 1, nz
      q_subarray(i) = q_subarray(i) + 1.0
    END DO
    DO i = 1, b
      t_subarray(i) = t_subarray(i) + 1.0
    END DO
  END SUBROUTINE compute
END MODULE mo_column

PROGRAM test_abstraction21
  USE mo_column, ONLY: compute
  REAL, DIMENSION(20,60) :: q = 0.0
  REAL, DIMENSION(60,20) :: t = 0.0
  INTEGER :: nproma, nz
  INTEGER :: p

  nproma = 20
  nz = 60

  DO p = 1, nproma
    CALL compute(nz, nproma, q(p,:), t(:,p))
  END DO

  PRINT*, "Sum of q:", SUM(q)
  PRINT*, "Sum of t:", SUM(t)
END PROGRAM test_abstraction21