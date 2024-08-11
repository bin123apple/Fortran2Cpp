PROGRAM test_sla_PV2UE
  IMPLICIT NONE
  DOUBLE PRECISION PV(6), U(13), DATE, PMASS
  INTEGER JSTAT

  ! Test 1: Basic functionality
  PV = (/1.0D0, 2.0D0, 3.0D0, 0.1D0, 0.2D0, 0.3D0/)
  DATE = 2451545.0D0
  PMASS = 1.0D0
  CALL sla_PV2UE(PV, DATE, PMASS, U, JSTAT)
  IF (JSTAT .EQ. 0) THEN
    PRINT *, "Test 1 Passed"
  ELSE
    PRINT *, "Test 1 Failed"
  END IF

  ! Additional tests can be added here following the same structure

CONTAINS

  SUBROUTINE sla_PV2UE (PV, DATE, PMASS, U, JSTAT)
    IMPLICIT NONE
    DOUBLE PRECISION PV(6),DATE,PMASS,U(13)
    INTEGER JSTAT

    DOUBLE PRECISION GCON
    PARAMETER (GCON=0.01720209895D0)

    DOUBLE PRECISION CD2S
    PARAMETER (CD2S=GCON/86400D0)

    DOUBLE PRECISION RMIN,VMIN
    PARAMETER (RMIN=1D-3,VMIN=1D-3)

    DOUBLE PRECISION T0,CM,X,Y,Z,XD,YD,ZD,R,V2,V,ALPHA,RDV

    T0 = DATE

    IF (PMASS.LT.0D0) THEN
      JSTAT = -1
      RETURN
    END IF
    CM = 1D0+PMASS

    X = PV(1)
    Y = PV(2)
    Z = PV(3)
    XD = PV(4)/CD2S
    YD = PV(5)/CD2S
    ZD = PV(6)/CD2S

    R = SQRT(X*X+Y*Y+Z*Z)
    V2 = XD*XD+YD*YD+ZD*ZD
    V = SQRT(V2)

    IF (R.LT.RMIN) THEN
      JSTAT = -2
      RETURN
    END IF
    IF (V.LT.VMIN) THEN
      JSTAT = -3
      RETURN
    END IF

    ALPHA = V2-2D0*CM/R

    RDV = X*XD+Y*YD+Z*ZD

    U(1) = CM
    U(2) = ALPHA
    U(3) = T0
    U(4) = X
    U(5) = Y
    U(6) = Z
    U(7) = XD
    U(8) = YD
    U(9) = ZD
    U(10) = R
    U(11) = RDV
    U(12) = T0
    U(13) = 0D0

    JSTAT = 0
  END SUBROUTINE sla_PV2UE

END PROGRAM test_sla_PV2UE