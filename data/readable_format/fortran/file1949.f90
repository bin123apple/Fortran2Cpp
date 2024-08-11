PROGRAM testSubv
  IMPLICIT NONE
  INTEGER :: i, n
  PARAMETER (n=5)
  REAL :: A(n) = [1.0, 2.0, 3.0, 4.0, 5.0]
  REAL :: B(n) = [5.0, 4.0, 3.0, 2.0, 1.0]
  REAL :: C(n)
  CALL SUBV(n, A, B, C)
  PRINT *, "C:"
  DO i = 1, n
     PRINT *, C(i)
  END DO
END PROGRAM testSubv

SUBROUTINE SUBV(N, A, B, C)
  INTEGER :: N, I
  REAL, DIMENSION(N) :: A, B, C
  DO I = 1, N
     C(I) = A(I) - B(I)
  END DO
END SUBROUTINE SUBV