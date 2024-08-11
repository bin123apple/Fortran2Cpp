PROGRAM TEST_FBARS
  IMPLICIT NONE
  COMPLEX :: RESULT
  COMPLEX :: ARG
  REAL :: TOSP, ACCS, SP
  
  TOSP = 1.128379167
  ACCS = 1.E-12
  SP = 1.772453851
  
  ARG = CMPLX(1.0, 1.0)
  RESULT = FBAR(ARG, TOSP, ACCS, SP)
  PRINT *, 'Test 1: FBAR(1.0, 1.0) = ', RESULT
  
  ARG = CMPLX(2.0, -1.0)
  RESULT = FBAR(ARG, TOSP, ACCS, SP)
  PRINT *, 'Test 2: FBAR(2.0, -1.0) = ', RESULT
  
  ARG = CMPLX(-2.0, 2.0)
  RESULT = FBAR(ARG, TOSP, ACCS, SP)
  PRINT *, 'Test 3: FBAR(-2.0, 2.0) = ', RESULT
  
  ARG = CMPLX(0.5, 0.5)
  RESULT = FBAR(ARG, TOSP, ACCS, SP)
  PRINT *, 'Test 4: FBAR(0.5, 0.5) = ', RESULT

CONTAINS

  COMPLEX FUNCTION FBAR(P, TOSP, ACCS, SP)
    COMPLEX, INTENT(IN) :: P
    REAL, INTENT(IN) :: TOSP, ACCS, SP
    COMPLEX :: Z, ZS, SUM, POW, TERM
    REAL :: TMS, SMS
    INTEGER :: I
    LOGICAL :: MINUS
    COMPLEX, DIMENSION(2) :: FJX = (/ (0.0, 0.0), (1.0, 0.0) /)
    
    Z = FJX(2) * CSQRT(P)
    IF (CABS(Z) > 3.0) THEN
      IF (REAL(Z) < 0.0) THEN
        MINUS = .TRUE.
        Z = -Z
      ELSE
        MINUS = .FALSE.
      END IF
      ZS = 0.5 / (Z * Z)
      SUM = (0.0, 0.0)
      TERM = (1.0, 0.0)
      DO I = 1, 6
        TERM = -TERM * (2.0 * REAL(I) - 1.0) * ZS
        SUM = SUM + TERM
      END DO
      IF (MINUS) THEN
        SUM = SUM - 2.0 * SP * Z * CEXP(Z * Z)
      END IF
      FBAR = -SUM
    ELSE
      ZS = Z * Z
      SUM = Z
      POW = Z
      DO I = 1, 100
        POW = -POW * ZS / REAL(I)
        TERM = POW / (2.0 * REAL(I) + 1.0)
        SUM = SUM + TERM
        TMS = REAL(TERM * CONJG(TERM))
        SMS = REAL(SUM * CONJG(SUM))
        IF (TMS / SMS < ACCS) EXIT
      END DO
      FBAR = 1.0 - (1.0 - SUM * TOSP) * Z * CEXP(ZS) * SP
    END IF
  END FUNCTION FBAR

END PROGRAM TEST_FBARS