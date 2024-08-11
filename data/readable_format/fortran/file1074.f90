PROGRAM test_abstraction1
  IMPLICIT NONE
  REAL :: q(1:20, 1:60)
  REAL :: t(1:20, 1:60)
  INTEGER :: nproma, nz, p
  REAL :: sum_q, sum_t

  nproma = 20
  nz = 60
  DO p = 1, nproma, 1
    q(p, 1) = 0.0
    t(p, 1) = 0.0
  END DO

  CALL compute_column(4, nz, q, t, nproma)

  sum_q = sum(q)
  sum_t = sum(t)

  PRINT *, 'Sum of q:', sum_q
  PRINT *, 'Sum of t:', sum_t

CONTAINS

  SUBROUTINE compute_column(arg1, nz, q, t, nproma)
    INTEGER, INTENT(IN) :: arg1, nz, nproma
    REAL, INTENT(INOUT) :: q(nproma,nz), t(nproma,nz)
    INTEGER :: i, j
    
    ! A dummy implementation - replace with the actual logic
    DO i = 1, nproma
      DO j = 1, nz
        q(i, j) = 1.0  ! Example modification
        t(i, j) = 2.0  ! Example modification
      END DO
    END DO
  END SUBROUTINE compute_column

END PROGRAM test_abstraction1