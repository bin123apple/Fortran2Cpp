PROGRAM REDUCTION_TEST
  IMPLICIT NONE
  INTEGER :: N
  REAL :: sum

  N = 100
  CALL COMPUTE_SUM(N, sum)

  PRINT *, '   Sum = ', sum
  IF (ABS(sum - 338350.0) < 1.0) THEN
    PRINT *, 'Test Passed.'
  ELSE
    PRINT *, 'Test Failed.'
  END IF
END PROGRAM REDUCTION_TEST

SUBROUTINE COMPUTE_SUM(N, sum)
  INTEGER, INTENT(IN) :: N
  REAL, INTENT(OUT) :: sum
  REAL :: A(100), B(100)
  INTEGER :: I

  DO I = 1, N
    A(I) = I * 1.0
    B(I) = A(I)
  END DO
  sum = 0.0

!$OMP PARALLEL DO REDUCTION(+:sum)
  DO I = 1, N
    sum = sum + (A(I) * B(I))
  END DO
END SUBROUTINE COMPUTE_SUM