MODULE parameters
  IMPLICIT NONE
  INTEGER, PARAMETER :: ntypx  = 10
  INTEGER, PARAMETER :: npsx   = ntypx
  INTEGER, PARAMETER :: npk    = 40000
  INTEGER, PARAMETER :: lmaxx  = 3
  INTEGER, PARAMETER :: nchix  = 6
  INTEGER, PARAMETER :: ndmx   = 2000
  INTEGER, PARAMETER :: nbrx   = 28
  INTEGER, PARAMETER :: lqmax  = 2*lmaxx+1
  INTEGER, PARAMETER :: nqfx   = 8
  INTEGER, PARAMETER :: nacx   = 10
  INTEGER, PARAMETER :: nsx    = ntypx
  INTEGER, PARAMETER :: natx   = 5000
  INTEGER, PARAMETER :: npkx   = npk
  INTEGER, PARAMETER :: ncnsx  = 101
  INTEGER, PARAMETER :: nspinx = 2
  INTEGER, PARAMETER :: nhclm  = 4
  INTEGER, PARAMETER :: max_nconstr = 100
END MODULE parameters

PROGRAM testParameters
  USE parameters
  IMPLICIT NONE

  IF (ntypx /= 10) THEN
    PRINT *, "FAIL: ntypx"
  ELSE
    PRINT *, "PASS: ntypx"
  END IF

  IF (npsx /= 10) THEN
    PRINT *, "FAIL: npsx"
  ELSE
    PRINT *, "PASS: npsx"
  END IF

  IF (npk /= 40000) THEN
    PRINT *, "FAIL: npk"
  ELSE
    PRINT *, "PASS: npk"
  END IF

  IF (lmaxx /= 3) THEN
    PRINT *, "FAIL: lmaxx"
  ELSE
    PRINT *, "PASS: lmaxx"
  END IF

  IF (nchix /= 6) THEN
    PRINT *, "FAIL: nchix"
  ELSE
    PRINT *, "PASS: nchix"
  END IF

  IF (ndmx /= 2000) THEN
    PRINT *, "FAIL: ndmx"
  ELSE
    PRINT *, "PASS: ndmx"
  END IF

  IF (nbrx /= 28) THEN
    PRINT *, "FAIL: nbrx"
  ELSE
    PRINT *, "PASS: nbrx"
  END IF

  IF (lqmax /= 2*lmaxx+1) THEN
    PRINT *, "FAIL: lqmax"
  ELSE
    PRINT *, "PASS: lqmax"
  END IF

  IF (nqfx /= 8) THEN
    PRINT *, "FAIL: nqfx"
  ELSE
    PRINT *, "PASS: nqfx"
  END IF

  IF (nacx /= 10) THEN
    PRINT *, "FAIL: nacx"
  ELSE
    PRINT *, "PASS: nacx"
  END IF

  IF (nsx /= ntypx) THEN
    PRINT *, "FAIL: nsx"
  ELSE
    PRINT *, "PASS: nsx"
  END IF

  IF (natx /= 5000) THEN
    PRINT *, "FAIL: natx"
  ELSE
    PRINT *, "PASS: natx"
  END IF

  IF (npkx /= npk) THEN
    PRINT *, "FAIL: npkx"
  ELSE
    PRINT *, "PASS: npkx"
  END IF

  IF (ncnsx /= 101) THEN
    PRINT *, "FAIL: ncnsx"
  ELSE
    PRINT *, "PASS: ncnsx"
  END IF

  IF (nspinx /= 2) THEN
    PRINT *, "FAIL: nspinx"
  ELSE
    PRINT *, "PASS: nspinx"
  END IF

  IF (nhclm /= 4) THEN
    PRINT *, "FAIL: nhclm"
  ELSE
    PRINT *, "PASS: nhclm"
  END IF

  IF (max_nconstr /= 100) THEN
    PRINT *, "FAIL: max_nconstr"
  ELSE
    PRINT *, "PASS: max_nconstr"
  END IF
END PROGRAM testParameters