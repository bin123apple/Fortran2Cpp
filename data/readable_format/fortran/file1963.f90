! Define the subroutine sla_PERMUT
SUBROUTINE sla_PERMUT(N, ISTATE, IORDER, J)
  IMPLICIT NONE
  INTEGER, INTENT(IN) :: N
  INTEGER, INTENT(INOUT) :: ISTATE(N), IORDER(N)
  INTEGER, INTENT(OUT) :: J
  INTEGER :: I, IP1, ISLOT, ISKIP

  IF (N.LT.1) THEN
     J = -1
     RETURN
  ELSE
     J = 0
  END IF

  IF (ISTATE(1).LT.0) THEN
     ISTATE(1) = -1
     DO I=2,N
        ISTATE(I) = 0
     END DO
  END IF

  ISTATE(1) = ISTATE(1) + 1

  DO I=1,N
     IF (ISTATE(I).GE.I) THEN
        ISTATE(I) = 0
        IF (I.GE.N) THEN
           J = 1
        ELSE
           IP1 = I + 1
           ISTATE(IP1) = ISTATE(IP1) + 1
        END IF
     END IF
  END DO

  DO I=1,N
     IORDER(I) = 1
  END DO

  DO I=N,2,-1
     ISLOT = 0
     DO ISKIP=0,ISTATE(I)
        ISLOT = ISLOT + 1
        DO WHILE (IORDER(ISLOT).GT.1)
           ISLOT = ISLOT + 1
        END DO
     END DO
     IORDER(ISLOT) = I
  END DO
END SUBROUTINE sla_PERMUT

! Main program to test sla_PERMUT subroutine
PROGRAM test_sla_PERMUT
  IMPLICIT NONE
  INTEGER, PARAMETER :: N = 4
  INTEGER :: ISTATE(N), IORDER(N), J, i

  ! Initialize ISTATE with a specific test case, e.g., all -2
  ISTATE = -2
  CALL sla_PERMUT(N, ISTATE, IORDER, J)

  PRINT *, 'Test Case: J = ', J
  PRINT *, 'ISTATE =', ISTATE
  PRINT *, 'IORDER =', IORDER

  ! Include further test cases as needed
END PROGRAM test_sla_PERMUT