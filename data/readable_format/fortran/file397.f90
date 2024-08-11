program test_machpi
  IMPLICIT NONE
  REAL*8 :: MACH, PI, kappa, rgas

  ! Test case 1
  kappa = 1.4
  rgas = 287.0
  PI = 0.8
  CALL machpi(MACH, PI, kappa, rgas)
  PRINT *, 'Test 1: MACH = ', MACH

  ! Test case 2
  PI = 1.0
  CALL machpi(MACH, PI, kappa, rgas)
  PRINT *, 'Test 2: MACH = ', MACH

  ! Test case 3
  PI = 0.0
  CALL machpi(MACH, PI, kappa, rgas)
  PRINT *, 'Test 3: MACH = ', MACH

END PROGRAM test_machpi

subroutine machpi (MACH, PI, kappa, rgas)
  IMPLICIT CHARACTER*1 (A-Z)
  REAL*8    PI, MACH, MA2, kappa, rgas, kappam, kappax, pikrit

  kappax = (kappa-1)/kappa
  KAPPAM = 2.d0 / (KAPPA - 1.d0)
  PIKRIT = (2.d0/(KAPPA+1.d0)) ** (KAPPA/(KAPPA-1.d0))

  IF (PI.GE.1.d0) THEN
    MACH = 0.d0
  ELSEIF (PI.GT.PIKRIT) THEN
    MA2  = KAPPAM * (PI**(-KAPPAX) - 1.d0)
    IF (MA2.GT.0.d0) THEN
      MACH = SQRT (MA2)
    ELSE
      MACH = 0.d0
    ENDIF
  ELSEIF (PI.GT.0.d0) THEN
    MACH = 1.d0
  ELSE
    MACH = 1.d20
  ENDIF

  RETURN
END