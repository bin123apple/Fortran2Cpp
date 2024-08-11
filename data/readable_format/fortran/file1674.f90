PROGRAM MAIN
  IMPLICIT NONE
  INTEGER, PARAMETER :: N = 5
  REAL, ALLOCATABLE :: WA(:), FAC(:)
  INTEGER :: I

  ! Allocate the arrays
  ALLOCATE(WA(N), FAC(15))

  ! Initialize the arrays to zero (optional, for clarity)
  WA = 0.0
  FAC = 0.0

  ! Call the subroutine
  CALL RFFTI1(N, WA, FAC)

  ! Print results
  PRINT *, 'WA:'
  DO I = 1, N
     PRINT *, WA(I)
  END DO

  PRINT *, 'FAC:'
  DO I = 1, 15
     PRINT *, FAC(I)
  END DO

  ! Clean up
  DEALLOCATE(WA, FAC)
END PROGRAM MAIN

SUBROUTINE RFFTI1(N, WA, FAC)
  INTEGER, INTENT(IN) :: N
  REAL, INTENT(OUT) :: WA(N), FAC(15)
  INTEGER :: NTRYH(4), NL, NF, J, NTRY, NQ, NR, I, IB, IP, LD, L1, L2, IDO, IPM, IS, NFM1, II
  DOUBLE PRECISION :: TPI, ARGH, ARGLD, ARG, FI
  DATA NTRYH /4,2,3,5/

  NL = N
  NF = 0
  J = 0

101 CONTINUE
  J = J + 1
  IF (J > 4) THEN
    NTRY = NTRY + 2
  ELSE
    NTRY = NTRYH(J)
  END IF

  NQ = NL / NTRY
  NR = NL - NTRY * NQ
  IF (NR /= 0) GOTO 101

  NF = NF + 1
  FAC(NF + 2) = NTRY
  NL = NQ

  IF (NTRY /= 2 .OR. NF == 1) GOTO 107

  DO I = 2, NF
    IB = NF - I + 2
    FAC(IB + 2) = FAC(IB + 1)
  END DO
  FAC(3) = 2

107 CONTINUE
  IF (NL /= 1) GOTO 101
  FAC(1) = N
  FAC(2) = NF

  RETURN
END SUBROUTINE RFFTI1