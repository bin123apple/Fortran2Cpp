! Filename: testDLA_WWADDW.f90
! To compile: gfortran -o testDLA_WWADDW testDLA_WWADDW.f90
! To run: ./testDLA_WWADDW

PROGRAM TestDLA_WWADDW
  IMPLICIT NONE
  INTEGER, PARAMETER :: N = 5
  DOUBLE PRECISION :: X(N) = [1.0, 2.0, 3.0, 4.0, 5.0]
  DOUBLE PRECISION :: Y(N) = [5.0, 4.0, 3.0, 2.0, 1.0]
  DOUBLE PRECISION :: W(N) = [0.5, 1.5, 2.5, 3.5, 4.5]
  INTEGER :: I

  CALL DLA_WWADDW(N, X, Y, W)

  PRINT *, 'Modified X:'
  DO I = 1, N
    PRINT *, X(I)
  END DO

  PRINT *, 'Modified Y:'
  DO I = 1, N
    PRINT *, Y(I)
  END DO
END PROGRAM TestDLA_WWADDW

SUBROUTINE DLA_WWADDW(N, X, Y, W)
  IMPLICIT NONE
  INTEGER, INTENT(IN) :: N
  DOUBLE PRECISION, INTENT(INOUT) :: X(N), Y(N)
  DOUBLE PRECISION, INTENT(IN) :: W(N)
  DOUBLE PRECISION :: S
  INTEGER :: I

  DO I = 1, N
    S = X(I) + W(I)
    S = (S + S) - S
    Y(I) = ((X(I) - S) + W(I)) + Y(I)
    X(I) = S
  END DO
END SUBROUTINE DLA_WWADDW