PROGRAM TestGDAEFN1
  IMPLICIT NONE
  DOUBLE PRECISION :: X, result

  ! Declare types for common block variables
  DOUBLE PRECISION :: TOMEGA, PHIX, GAM, SN1, CS1, PII, CDN, QPI
  INTEGER :: ICHG, IWT, MDEX

  ! Define common blocks
  COMMON /CM9/ TOMEGA, PHIX, ICHG, IWT
  COMMON /CM29/ GAM, SN1, CS1, PII, CDN, QPI, MDEX

  ! Initialize common block variables for testing
  TOMEGA = 1.0
  PHIX = 2.0
  ICHG = 1
  IWT = 1
  GAM = 0.5
  MDEX = -1

  ! Define a test value for X
  X = 1.0

  ! Call the function and print the result
  result = GDAEFN1(X)
  PRINT *, "Test Result = ", result

CONTAINS

  DOUBLE PRECISION FUNCTION GDAEFN1(X)
    IMPLICIT NONE
    DOUBLE PRECISION, INTENT(IN) :: X
    DOUBLE PRECISION :: SGNP, XABX, XEE, XCU, XAR
    DOUBLE PRECISION :: TOMEGA, PHIX, GAM, SN1, CS1, PII, CDN, QPI
    INTEGER :: ICHG, IWT, MDEX
    COMMON /CM9/ TOMEGA, PHIX, ICHG, IWT
    COMMON /CM29/ GAM, SN1, CS1, PII, CDN, QPI, MDEX

    SGNP = DSIGN(1.D0, PHIX)
    XABX = DABS(X*PHIX)

    XEE = DEXP(X)

    XCU = X*ICHG - SGNP*(XABX**GAM)/GAM

    IF(DABS(XCU) > 300.D0) THEN
       XCU = DSIGN(300.D0, XCU)
    END IF

    IF(IWT == 1) THEN
          GDAEFN1 = DEXP(XCU)/(1.D0 + (TOMEGA*XEE)**2)
      IF(MDEX < 0) THEN
          GDAEFN1 = GDAEFN1*XEE
      END IF
    ELSE 
      XAR = XCU - TOMEGA*DEXP(-X)
      IF(XAR < -50.D0) THEN
          GDAEFN1 = 0.D0
      ELSE
          GDAEFN1 = DEXP(XAR)
      END IF
    END IF 
  END FUNCTION GDAEFN1

END PROGRAM TestGDAEFN1