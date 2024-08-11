PROGRAM TestDLAPMT
  IMPLICIT NONE
  LOGICAL :: FORWRD
  INTEGER :: M, N, LDX
  INTEGER, ALLOCATABLE :: K(:)
  DOUBLE PRECISION, ALLOCATABLE :: X(:,:)
  INTEGER :: I, J

  ! Example parameters and data
  FORWRD = .TRUE.
  M = 2
  N = 3
  LDX = M
  ALLOCATE(K(N), X(LDX, N))

  ! Initialize K and X for testing
  K = (/ 3, 1, 2 /)
  X = RESHAPE((/ 1.0, 2.0, 3.0, 4.0, 5.0, 6.0 /), SHAPE(X))

  ! Call the subroutine
  CALL DLAPMT(FORWRD, M, N, X, LDX, K)

  ! Print the results
  PRINT *, "K after DLAPMT:"
  DO I = 1, N
    PRINT *, K(I)
  END DO

  PRINT *, "X after DLAPMT:"
  DO I = 1, M
    DO J = 1, N
      PRINT *, X(I, J)
    END DO
  END DO

CONTAINS

  SUBROUTINE DLAPMT( FORWRD, M, N, X, LDX, K )
    LOGICAL            FORWRD
    INTEGER            LDX, M, N
    INTEGER            K( * )
    DOUBLE PRECISION   X( LDX, * )
    INTEGER            I, II, IN, J
    DOUBLE PRECISION   TEMP

    IF( N.LE.1 ) RETURN

    DO 10 I = 1, N
       K( I ) = -K( I )
10   CONTINUE

    IF( FORWRD ) THEN
       DO 50 I = 1, N
          IF( K( I ).GT.0 ) GO TO 40

          J = I
          K( J ) = -K( J )
          IN = K( J )
20       CONTINUE
          IF( K( IN ).GT.0 ) GO TO 40

          DO 30 II = 1, M
             TEMP = X( II, J )
             X( II, J ) = X( II, IN )
             X( II, IN ) = TEMP
30         CONTINUE

          K( IN ) = -K( IN )
          J = IN
          IN = K( IN )
          GO TO 20
40       CONTINUE
50    CONTINUE
    ELSE
       DO 90 I = 1, N
          IF( K( I ).GT.0 ) GO TO 80

          K( I ) = -K( I )
          J = K( I )
60       CONTINUE
          IF( J.EQ.I ) GO TO 80

          DO 70 II = 1, M
             TEMP = X( II, I )
             X( II, I ) = X( II, J )
             X( II, J ) = TEMP
70         CONTINUE

          K( J ) = -K( J )
          J = K( J )
          GO TO 60
80       CONTINUE
90    CONTINUE
    END IF

    RETURN
  END SUBROUTINE DLAPMT

END PROGRAM TestDLAPMT