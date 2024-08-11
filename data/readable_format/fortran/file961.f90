PROGRAM TestODFNRM
  IMPLICIT NONE
  REAL :: result

  ! Test 1:
  result = ODFNRM(0.5, 20.0)
  PRINT *, 'Test 1 (D=0.5, S=20):', result

  ! Test 2: Edge case where S < SMIN
  result = ODFNRM(0.5, 0.5)
  PRINT *, 'Test 2 (D=0.5, S=0.5):', result

  ! Test 3: Edge case where S > SMAX
  result = ODFNRM(0.5, 150.0)
  PRINT *, 'Test 3 (D=0.5, S=150):', result

  ! Test 4: D=0 (should return 4*PI)
  result = ODFNRM(0.0, 10.0)
  PRINT *, 'Test 4 (D=0, S=10):', result

  ! Test 5: S=1, specific case
  result = ODFNRM(0.5, 1.0)
  PRINT *, 'Test 5 (D=0.5, S=1):', result

CONTAINS

  REAL FUNCTION ODFNRM(D,S)
    IMPLICIT NONE
    REAL, INTENT(IN) :: D, S
    REAL :: PI, SMAX, SMIN
    REAL :: AMB, ONEMS, SAdjusted

    PARAMETER(PI=3.14159265, SMAX=100.0, SMIN=1.0)

    ODFNRM = 0.0
    SAdjusted = S

    IF(SAdjusted < SMIN) SAdjusted = SMIN
    IF(SAdjusted > SMAX) SAdjusted = SMAX

    IF(D > 0.0) THEN
      AMB = 1.0 + 2.0*D

      IF(SAdjusted > 1.0) THEN
        ONEMS = 1.0 - SAdjusted
        ODFNRM = 2.0*PI*(AMB**ONEMS - 1.0)/(D*ONEMS)
      ELSE
        ODFNRM = 2.0*PI*LOG(AMB)/D
      ENDIF
    ELSE
      ODFNRM = 4.0*PI
    ENDIF
  END FUNCTION ODFNRM

END PROGRAM TestODFNRM