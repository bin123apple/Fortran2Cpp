! File: F_and_Test.f90
SUBROUTINE F(X, V)
  DOUBLE PRECISION X(1), V(1)
  ! Increment X(1) by 1
  X(1) = X(1) + 1
END SUBROUTINE F

PROGRAM TestF
  DOUBLE PRECISION X(1), V(1)
  X(1) = 5.0
  V(1) = 10.0
  CALL F(X, V)
  PRINT *, 'X(1) after calling F:', X(1)
  PRINT *, 'V(1) remains unchanged:', V(1)
END PROGRAM TestF