MODULE JD2CAL_MOD
  IMPLICIT NONE
CONTAINS
  SUBROUTINE iau_JD2CAL(DJ1, DJ2, IY, IM, ID, FD, J)
    IMPLICIT NONE
    DOUBLE PRECISION, INTENT(IN) :: DJ1, DJ2
    INTEGER, INTENT(OUT) :: IY, IM, ID, J
    DOUBLE PRECISION, INTENT(OUT) :: FD
    DOUBLE PRECISION :: DJMIN, DJMAX
    PARAMETER (DJMIN = -68569.5D0, DJMAX = 1D9)
    INTEGER :: JD, L, N, I, K
    DOUBLE PRECISION :: DJ, D1, D2, F1, F2, F, D

    DJ = DJ1 + DJ2
    IF (DJ .LT. DJMIN .OR. DJ .GT. DJMAX) THEN
      J = -1
      RETURN
    END IF

    J = 0

    IF (DJ1 .GE. DJ2) THEN
      D1 = DJ1
      D2 = DJ2
    ELSE
      D1 = DJ2
      D2 = DJ1
    END IF
    D2 = D2 - 0.5D0

    F1 = MOD(D1, 1D0)
    F2 = MOD(D2, 1D0)
    F = MOD(F1 + F2, 1D0)
    IF (F .LT. 0D0) F = F + 1D0
    D = ANINT(D1 - F1) + ANINT(D2 - F2) + ANINT(F1 + F2 - F)
    JD = NINT(D) + 1

    L = JD + 68569
    N = (4 * L) / 146097
    L = L - (146097 * N + 3) / 4
    I = (4000 * (L + 1)) / 1461001
    L = L - (1461 * I) / 4 + 31
    K = (80 * L) / 2447
    ID = L - (2447 * K) / 80
    L = K / 11
    IM = K + 2 - 12 * L
    IY = 100 * (N - 49) + I + L

    FD = F
  END SUBROUTINE iau_JD2CAL
END MODULE JD2CAL_MOD

PROGRAM TestIauJD2Cal
  USE JD2CAL_MOD
  IMPLICIT NONE
  DOUBLE PRECISION :: DJ1, DJ2, FD
  INTEGER :: IY, IM, ID, J

  ! Example Test Cases
  DJ1 = 2451545.0D0
  DJ2 = 0.5D0
  CALL iau_JD2CAL(DJ1, DJ2, IY, IM, ID, FD, J)
  PRINT *, "Test Case: ", IY, IM, ID, FD, J
END PROGRAM TestIauJD2Cal