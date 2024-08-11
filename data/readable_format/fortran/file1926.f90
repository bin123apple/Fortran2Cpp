PROGRAM TestIauPV2S
  IMPLICIT NONE
  DOUBLE PRECISION PV(3,2), THETA, PHI, R, TD, PD, RD

  ! Initialize PV with some test values
  DATA PV / 1.0d0, 2.0d0, 3.0d0, 4.0d0, 5.0d0, 6.0d0 /

  ! Call the subroutine
  CALL iau_PV2S(PV, THETA, PHI, R, TD, PD, RD)

  ! Print results
  PRINT *, "THETA:", THETA
  PRINT *, "PHI:", PHI
  PRINT *, "R:", R
  PRINT *, "TD:", TD
  PRINT *, "PD:", PD
  PRINT *, "RD:", RD

END PROGRAM TestIauPV2S

! The iau_PV2S subroutine definition
SUBROUTINE iau_PV2S ( PV, THETA, PHI, R, TD, PD, RD )

  IMPLICIT NONE

  DOUBLE PRECISION PV(3,2), THETA, PHI, R, TD, PD, RD
  DOUBLE PRECISION X, Y, Z, XD, YD, ZD, RXY2, RXY, R2
  DOUBLE PRECISION RTRUE, RW, XYP

  X =  PV(1,1)
  Y =  PV(2,1)
  Z =  PV(3,1)
  XD = PV(1,2)
  YD = PV(2,2)
  ZD = PV(3,2)

  RXY2 = X*X + Y*Y
  R2 = RXY2 + Z*Z
  RTRUE = SQRT(R2)
  RW = RTRUE

  IF ( RTRUE .EQ. 0D0 ) THEN
     X = XD
     Y = YD
     Z = ZD
     RXY2 = X*X + Y*Y
     R2 = RXY2 + Z*Z
     RW = SQRT(R2)
  END IF

  RXY = SQRT(RXY2)
  XYP = X*XD + Y*YD

  IF ( RXY2 .NE. 0D0 ) THEN
     THETA = ATAN2(Y,X)
     PHI = ATAN2(Z,RXY)
     TD = ( X*YD - Y*XD ) / RXY2
     PD = ( ZD*RXY2 - Z*XYP ) / ( R2*RXY )
  ELSE
     THETA = 0D0
     IF ( Z .NE. 0D0 ) THEN
        PHI = ATAN2(Z,RXY)
     ELSE
        PHI = 0D0
     END IF
     TD = 0D0
     PD = 0D0
  END IF

  R = RTRUE
  IF ( RW .NE. 0D0 ) THEN
     RD = ( XYP + Z*ZD ) / RW
  ELSE
     RD = 0D0
  END IF

END SUBROUTINE iau_PV2S