! combined.f90
SUBROUTINE DLAPMT(FORWRD, M, N, X, LDX, K)
  LOGICAL, INTENT(IN) :: FORWRD
  INTEGER, INTENT(IN) :: LDX, M, N
  INTEGER, INTENT(INOUT) :: K(LDX)
  DOUBLE PRECISION, INTENT(INOUT) :: X(LDX, *)

  INTEGER :: I, II, IN, J
  DOUBLE PRECISION :: TEMP

  IF (N.LE.1) RETURN

  DO I = 1, N
     K(I) = -K(I)
  END DO

  IF (FORWRD) THEN
     DO I = 1, N
        IF (K(I) .GT. 0) CYCLE

        J = I
        K(J) = -K(J)
        IN = K(J)

        DO
           IF (K(IN) .GT. 0) EXIT

           DO II = 1, M
              TEMP = X(II, J)
              X(II, J) = X(II, IN)
              X(II, IN) = TEMP
           END DO

           K(IN) = -K(IN)
           J = IN
           IN = K(IN)
        END DO
     END DO
  ELSE
     DO I = 1, N
        IF (K(I) .GT. 0) CYCLE

        K(I) = -K(I)
        J = K(I)

        DO
           IF (J .EQ. I) EXIT

           DO II = 1, M
              TEMP = X(II, I)
              X(II, I) = X(II, J)
              X(II, J) = TEMP
           END DO

           K(J) = -K(J)
           J = K(J)
        END DO
     END DO
  END IF
END SUBROUTINE DLAPMT

PROGRAM testDLAPMT
  IMPLICIT NONE
  INTEGER, PARAMETER :: dp = KIND(1.0D0)
  INTEGER :: M, N, LDX
  LOGICAL :: FORWRD
  INTEGER, ALLOCATABLE :: K(:)
  DOUBLE PRECISION, ALLOCATABLE :: X(:,:)
  INTEGER :: i, j

  ! Test parameters
  M = 2
  N = 3
  LDX = M
  ALLOCATE(K(N), X(LDX,N))

  ! Initialize data
  K = (/ 3, 1, 2 /)
  X = RESHAPE((/ 1.0_dp, 4.0_dp, 2.0_dp, 5.0_dp, 3.0_dp, 6.0_dp /), SHAPE(X))
  FORWRD = .TRUE.

  ! Call the subroutine
  CALL DLAPMT(FORWRD, M, N, X, LDX, K)

  ! Print the result
  PRINT *, "Result:"
  DO i = 1, M
      DO j = 1, N
          PRINT *, X(i, j)
      END DO
  END DO
END PROGRAM testDLAPMT