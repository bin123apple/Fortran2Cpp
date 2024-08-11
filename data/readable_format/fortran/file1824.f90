PROGRAM test_cla_wwaddw
  IMPLICIT NONE
  INTEGER, PARAMETER :: n = 3
  COMPLEX :: X(n) = (/ (1.0, 2.0), (3.0, 4.0), (5.0, 6.0) /)
  COMPLEX :: Y(n) = (/ (7.0, 8.0), (9.0, 10.0), (11.0, 12.0) /)
  COMPLEX :: W(n) = (/ (0.5, 1.5), (2.5, 3.5), (4.5, 5.5) /)
  INTEGER :: i

  CALL CLA_WWADDW(n, X, Y, W)

  PRINT *, 'Modified X:'
  DO i = 1, n
    PRINT '(F6.2, ", ", F6.2)', X(i)
  END DO

  PRINT *, 'Modified Y:'
  DO i = 1, n
    PRINT '(F6.2, ", ", F6.2)', Y(i)
  END DO
END PROGRAM test_cla_wwaddw

SUBROUTINE CLA_WWADDW(N, X, Y, W)
  IMPLICIT NONE
  INTEGER, INTENT(IN) :: N
  COMPLEX, INTENT(INOUT) :: X(*)
  COMPLEX, INTENT(INOUT) :: Y(*)
  COMPLEX, INTENT(IN) :: W(*)
  COMPLEX :: S
  INTEGER :: I

  DO I = 1, N
    S = X(I) + W(I)
    S = (S + S) - S
    Y(I) = ((X(I) - S) + W(I)) + Y(I)
    X(I) = S
  END DO
END SUBROUTINE CLA_WWADDW