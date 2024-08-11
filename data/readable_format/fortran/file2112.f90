PROGRAM TestNMRV
  IMPLICIT NONE
  INTEGER :: N
  REAL :: H
  REAL, ALLOCATABLE :: Q(:), S(:), U(:)
  INTEGER :: i

  ! Test parameters
  N = 5
  H = 0.1
  ALLOCATE(Q(N), S(N), U(N))
  
  ! Initialize test data
  Q = (/1.0, 2.0, 3.0, 4.0, 5.0/)
  S = (/2.0, 3.0, 4.0, 5.0, 6.0/)
  U = (/0.0, 0.0, 0.0, 0.0, 0.0/)
  
  ! Call the subroutine
  CALL NMRV(N, H, Q, S, U)
  
  ! Output for verification
  PRINT *, 'Output U:'
  DO i = 1, N
     PRINT *, U(i)
  END DO

END PROGRAM TestNMRV

SUBROUTINE NMRV(N, H, Q, S, U)
  IMPLICIT NONE
  INTEGER, INTENT(IN) :: N
  REAL, INTENT(IN) :: H
  REAL, INTENT(IN) :: Q(N), S(N)
  REAL, INTENT(OUT) :: U(N)
  INTEGER :: I
  REAL :: G, C0, C1, C2, D, UTMP

  G = H*H/12.0

  DO I = 2, N-1
    C0 = 1.0 + G*((Q(I-1) - Q(I+1))/2.0 + Q(I))
    C1 = 2.0 - G*(Q(I+1) + Q(I-1) + 8.0*Q(I))
    C2 = 1.0 + G*((Q(I+1) - Q(I-1))/2.0 + Q(I))
    D  = G*(S(I+1) + S(I-1) + 10.0*S(I))
    UTMP = C1*U(I) - C0*U(I-1) + D
    U(I+1) = UTMP / C2
  END DO
END SUBROUTINE NMRV