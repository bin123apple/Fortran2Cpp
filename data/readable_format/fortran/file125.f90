PROGRAM testConstants
  IMPLICIT NONE
  INTEGER :: success
  INTEGER, PARAMETER :: MAXWORDS=4095, MAXRAYS=3000, MAXGATES=1500, MAXCOEFFS=13
  INTEGER, PARAMETER :: rmax=90, thetamax=90, zmax=20, nx=241, ny=241, nz=20

  success = 0

  IF (MAXWORDS /= 4095) success = 1
  IF (MAXRAYS /= 3000) success = 1
  IF (MAXGATES /= 1500) success = 1
  IF (MAXCOEFFS /= 13) success = 1
  IF (rmax /= 90) success = 1
  IF (thetamax /= 90) success = 1
  IF (zmax /= 20) success = 1
  IF (nx /= 241) success = 1
  IF (ny /= 241) success = 1
  IF (nz /= 20) success = 1

  IF (success == 0) THEN
    PRINT *, "All tests passed successfully."
  ELSE
    PRINT *, "One or more tests failed."
  END IF
END PROGRAM testConstants