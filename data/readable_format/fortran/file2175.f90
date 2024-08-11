PROGRAM TestEquivalence
  IMPLICIT NONE
  REAL :: A
  REAL :: B
  REAL :: expectedValue

  EQUIVALENCE(A, B)

  A = 0.0
  expectedValue = 0.0
  CALL Verify(A, B, expectedValue)

  B = 5.0
  expectedValue = 5.0
  CALL Verify(A, B, expectedValue)

CONTAINS

  SUBROUTINE Verify(x, y, expected)
    REAL, INTENT(IN) :: x, y, expected
    IF (x == expected .AND. y == expected) THEN
      PRINT *, "Test Passed: A =", x, ", B =", y, ", Expected =", expected
    ELSE
      PRINT *, "Test Failed: A =", x, ", B =", y, ", Expected =", expected
    END IF
  END SUBROUTINE Verify

END PROGRAM TestEquivalence