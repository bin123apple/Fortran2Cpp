! Define the MSTDEV subroutine
SUBROUTINE MSTDEV(LINE, NX, NRAN, JN, AM, STD, SNUM)
  INTEGER, INTENT(IN) :: LINE(*), NX, NRAN(2), JN
  DOUBLE PRECISION, INTENT(OUT) :: AM, STD, SNUM
  INTEGER :: J, K, KL, KH, KLA, KHA
  DOUBLE PRECISION :: S, SS, SN, AN, V
  
  KL = NRAN(1)
  KH = NRAN(2)
  
  DO J = 1, JN
     S = 0.0D0
     SN = 0.0D0
     SS = 0.0D0
     
     IF (KH >= KL) THEN
        DO K = KL, KH
           AN = DBLE(LINE(K))
           V = DBLE(K)
           SN = SN + AN
           S = S + AN * V
           SS = SS + AN * V * V
        END DO
     END IF
     
     IF (SN > 0.0D0) THEN
        AM = S / SN
     ELSE
        AM = 0.0D0
     END IF
     
     IF (SN > 1.0D0) THEN
        SS = (SS - S * S / SN) / (SN - 1.0D0)
        IF (SS > 1.0D-20) THEN
           STD = SQRT(SS)
        ELSE
           STD = 0.0D0
        END IF
     ELSE
        STD = 0.0D0
     END IF
     
     KLA = INT(AM - 3.0D0 * STD)
     KHA = INT(AM + 3.0D0 * STD)
     
     IF (KLA > NRAN(1)) KL = KLA
     IF (KHA < NRAN(2)) KH = KHA
  END DO
  
  SNUM = SN
END SUBROUTINE MSTDEV

! Test program for MSTDEV
PROGRAM TestMSTDEV
  IMPLICIT NONE
  INTEGER, DIMENSION(5) :: LINE = (/2, 3, 5, 7, 11/)
  INTEGER, DIMENSION(2) :: NRAN = (/1, 5/)
  INTEGER :: NX, JN
  DOUBLE PRECISION :: AM, STD, SNUM
  
  NX = 5
  JN = 2
  
  CALL MSTDEV(LINE, NX, NRAN, JN, AM, STD, SNUM)
  
  PRINT *, 'AM = ', AM
  PRINT *, 'STD = ', STD
  PRINT *, 'SNUM = ', SNUM
END PROGRAM TestMSTDEV