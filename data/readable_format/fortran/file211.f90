! mamult.f90
MODULE mamult_module
  IMPLICIT NONE
  CONTAINS
    SUBROUTINE mamult(A, B, C, N, ONE)
      DOUBLE PRECISION, DIMENSION(*), INTENT(IN) :: A, B
      DOUBLE PRECISION, DIMENSION(*), INTENT(INOUT) :: C
      INTEGER, INTENT(IN) :: N
      DOUBLE PRECISION, INTENT(IN) :: ONE
      INTEGER :: i

      DO i = 1, N
        C(i) = A(i) * B(i) + ONE
      END DO
    END SUBROUTINE mamult
END MODULE mamult_module

PROGRAM test_mamult
  USE mamult_module
  IMPLICIT NONE
  DOUBLE PRECISION :: A(3) = [1.0D0, 2.0D0, 3.0D0]
  DOUBLE PRECISION :: B(3) = [4.0D0, 5.0D0, 6.0D0]
  DOUBLE PRECISION :: C(3)
  INTEGER :: i

  CALL mamult(A, B, C, 3, 1.0D0)

  PRINT *, "Testing mamult..."
  DO i = 1, 3
    IF (C(i) /= A(i) * B(i) + 1.0D0) THEN
      PRINT *, "Test failed for element", i, "C(i):", C(i)
    ELSE
      PRINT *, "Test passed for element", i, "C(i):", C(i)
    END IF
  END DO
  PRINT *, "Test completed."
END PROGRAM test_mamult