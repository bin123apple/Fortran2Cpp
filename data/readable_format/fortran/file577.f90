PROGRAM TestPYGDIR
      IMPLICIT NONE
      DOUBLE PRECISION XPGA(-6:6)
      DOUBLE PRECISION X, Q2, P2, Q02

      X = 0.5D0
      Q2 = 1D0
      P2 = 1D0
      Q02 = 1D0

      CALL PYGDIR(X, Q2, P2, Q02, XPGA)

      PRINT *, 'Testing PYGDIR...'
      PRINT *, 'XPGA(1) = ', XPGA(1)
      PRINT *, 'XPGA(2) = ', XPGA(2)
      PRINT *, 'XPGA(3) = ', XPGA(3)
      PRINT *, 'XPGA(-1) = ', XPGA(-1)
      PRINT *, 'XPGA(-2) = ', XPGA(-2)
      PRINT *, 'XPGA(-3) = ', XPGA(-3)
      PRINT *, 'All tests done.'

END PROGRAM TestPYGDIR

SUBROUTINE PYGDIR(X, Q2, P2, Q02, XPGA)
      IMPLICIT DOUBLE PRECISION(A-H, O-Z)
      IMPLICIT INTEGER(I-N)
      INTEGER PYK, PYCHGE, PYCOMP
      DOUBLE PRECISION XPGA(-6:6), PMC, PMB, AEM2PI, XTMP, CGAM
      INTEGER KFL, KF

      DATA PMC/1.3D0/, PMB/4.6D0/, AEM2PI/0.0011614D0/

      DO KFL = -6, 6
        XPGA(KFL) = 0D0
      END DO

      XTMP = (X**2 + (1D0-X)**2) * (-LOG(X)) - 1D0
      CGAM = 3D0 * AEM2PI * X * (XTMP * (1D0 + P2 / (P2 + Q02)) + 6D0 * X * (1D0 - X))

      XPGA(1) = (1D0 / 9D0) * CGAM
      XPGA(2) = (4D0 / 9D0) * CGAM
      XPGA(3) = (1D0 / 9D0) * CGAM

      DO KF = 1, 5
        XPGA(-KF) = XPGA(KF)
      END DO

END SUBROUTINE PYGDIR