PROGRAM TestCLAESY
  IMPLICIT NONE
  COMPLEX :: A, B, C, RT1, RT2, EVSCAL, CS1, SN1

  ! Test case
  A = CMPLX(1.0, 2.0)
  B = CMPLX(2.0, 3.0)
  C = CMPLX(3.0, 4.0)

  CALL CLAESY(A, B, C, RT1, RT2, EVSCAL, CS1, SN1)

  PRINT *, 'RT1 = ', RT1
  PRINT *, 'RT2 = ', RT2
  PRINT *, 'EVSCAL = ', EVSCAL
  PRINT *, 'CS1 = ', CS1
  PRINT *, 'SN1 = ', SN1

END PROGRAM TestCLAESY

SUBROUTINE CLAESY(A, B, C, RT1, RT2, EVSCAL, CS1, SN1)
  COMPLEX :: A, B, C, CS1, EVSCAL, RT1, RT2, SN1
  REAL :: ZERO
  PARAMETER (ZERO = 0.0E0)
  REAL :: ONE
  PARAMETER (ONE = 1.0E0)
  COMPLEX :: CONE
  PARAMETER (CONE = (1.0E0, 0.0E0))
  REAL :: HALF
  PARAMETER (HALF = 0.5E0)
  REAL :: THRESH
  PARAMETER (THRESH = 0.1E0)
  REAL :: BABS, EVNORM, TABS, Z
  COMPLEX :: S, T, TMP
  IF(ABS(B) == ZERO) THEN
    RT1 = A
    RT2 = C
    IF(ABS(RT1) < ABS(RT2)) THEN
      TMP = RT1
      RT1 = RT2
      RT2 = TMP
      CS1 = ZERO
      SN1 = ONE
    ELSE
      CS1 = ONE
      SN1 = ZERO
    END IF
  ELSE
    S = (A + C) * HALF
    T = (A - C) * HALF
    BABS = ABS(B)
    TABS = ABS(T)
    Z = MAX(BABS, TABS)
    IF(Z > ZERO) THEN
      T = Z * SQRT((T / Z)**2 + (B / Z)**2)
    END IF
    RT1 = S + T
    RT2 = S - T
    IF(ABS(RT1) < ABS(RT2)) THEN
      TMP = RT1
      RT1 = RT2
      RT2 = TMP
    END IF
    SN1 = (RT1 - A) / B
    TABS = ABS(SN1)
    IF(TABS > ONE) THEN
      T = TABS * SQRT((ONE / TABS)**2 + (SN1 / TABS)**2)
    ELSE
      T = SQRT(CONE + SN1 * SN1)
    END IF
    EVNORM = ABS(T)
    IF(EVNORM >= THRESH) THEN
      EVSCAL = CONE / T
      CS1 = EVSCAL
      SN1 = SN1 * EVSCAL
    ELSE
      EVSCAL = ZERO
    END IF
  END IF
END SUBROUTINE CLAESY