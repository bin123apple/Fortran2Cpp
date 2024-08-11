PROGRAM testCLAR2V
  IMPLICIT NONE
  INTEGER, PARAMETER :: N = 3
  COMPLEX :: X(N), Y(N), Z(N), S(N)
  REAL :: C(N)
  INTEGER :: INCX, INCC, i

  ! Initialize inputs
  INCX = 1
  INCC = 1
  X = [(COMPLEX(i, i*2), i = 1, N)]
  Y = [(COMPLEX(i*2, i), i = 1, N)]
  Z = [(COMPLEX(i*3, i*2), i = 1, N)]
  C = [1.0, 0.5, 0.25]
  S = [(COMPLEX(0.5, 0.5), i = 1, N)]

  CALL CLAR2V(N, X, Y, Z, INCX, C, S, INCC)

  DO i = 1, N
     PRINT *, "X(", i, ") = ", X(i)
     PRINT *, "Y(", i, ") = ", Y(i)
     PRINT *, "Z(", i, ") = ", Z(i)
  END DO

END PROGRAM testCLAR2V

SUBROUTINE CLAR2V(N, X, Y, Z, INCX, C, S, INCC)
  INTEGER, INTENT(IN) :: N, INCX, INCC
  COMPLEX, INTENT(INOUT) :: X(*), Y(*), Z(*)
  REAL, INTENT(IN) :: C(*)
  COMPLEX, INTENT(IN) :: S(*)
  INTEGER :: I, IX, IC
  REAL :: XI, YI, CI, SII, SIR, T1I, T1R, T5, T6, ZII, ZIR
  COMPLEX :: ZI, SI, T2, T3, T4

  IX = 1
  IC = 1
  DO I = 1, N
     XI = REAL(X(IX))
     YI = REAL(Y(IX))
     ZI = Z(IX)
     ZIR = REAL(ZI)
     ZII = AIMAG(ZI)
     CI = C(IC)
     SI = S(IC)
     SIR = REAL(SI)
     SII = AIMAG(SI)
     T1R = SIR*ZIR - SII*ZII
     T1I = SIR*ZII + SII*ZIR
     T2 = CI*ZI
     T3 = T2 - CONJG(SI)*XI
     T4 = CONJG(T2) + SI*YI
     T5 = CI*XI + T1R
     T6 = CI*YI - T1R
     X(IX) = CI*T5 + (SIR*REAL(T4) + SII*AIMAG(T4))
     Y(IX) = CI*T6 - (SIR*REAL(T3) - SII*AIMAG(T3))
     Z(IX) = CI*T3 + CONJG(SI)*CMPLX(T6, T1I)
     IX = IX + INCX
     IC = IC + INCC
  END DO
END SUBROUTINE CLAR2V