! combined.f90
PROGRAM TestFunden
  IMPLICIT NONE
  DOUBLE PRECISION SAL, SED, TEM, EXPECTED, RESULT
  
  ! Test values
  SAL = 35.0
  SED = 1.5
  TEM = 15.0
  EXPECTED = 800.0  ! Note: Replace this with the actual expected value you're testing against
  
  RESULT = FUNDEN(SAL, SED, TEM)
  
  PRINT *, 'Testing FUNDEN with SAL=', SAL, ', SED=', SED, ', TEM=', TEM
  PRINT *, 'Expected:', EXPECTED, 'Result:', RESULT
  
  IF (ABS(EXPECTED - RESULT) < 0.0001) THEN
    PRINT *, 'Test Passed.'
  ELSE
    PRINT *, 'Test Failed.'
  END IF

CONTAINS

  FUNCTION FUNDEN(SAL, SED, TEM) RESULT(RHO)  
    IMPLICIT NONE
    DOUBLE PRECISION, INTENT(IN) :: SAL, SED, TEM
    DOUBLE PRECISION :: RHO
    DOUBLE PRECISION :: SSG, SDEN, SSTMP, TTMP, RHTMP
    
    SSG = 2.5  
    SDEN = 1./2500000.  
    SSTMP = SAL  
    TTMP = TEM  
    RHTMP = 999.842594+6.793952E-2*TTMP-9.095290E-3*TTMP*TTMP + &
            1.001685E-4*TTMP*TTMP*TTMP-1.120083E-6*TTMP*TTMP*TTMP*TTMP + &
            6.536332E-9*TTMP*TTMP*TTMP*TTMP*TTMP  
    RHO = RHTMP + SSTMP*(0.824493-4.0899E-3*TTMP+7.6438E-5*TTMP*TTMP - &
            8.2467E-7*TTMP*TTMP*TTMP+5.3875E-9*TTMP*TTMP*TTMP*TTMP) + &
            SQRT(SSTMP)*SSTMP*(-5.72466E-3+1.0227E-4*TTMP - &
            1.6546E-6*TTMP*TTMP)+4.8314E-4*SSTMP*SSTMP  
    RHO = RHO * ( (1.-SDEN*SED)+(SSG-1.)*SDEN*SED )
  END FUNCTION FUNDEN

END PROGRAM TestFunden