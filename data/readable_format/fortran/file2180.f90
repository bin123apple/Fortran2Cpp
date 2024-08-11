PROGRAM test_dlar2v
  IMPLICIT NONE
  INTEGER :: N, INCX, INCC, I
  DOUBLE PRECISION, ALLOCATABLE :: X(:), Y(:), Z(:), C(:), S(:)

  N = 3
  INCX = 1
  INCC = 1

  ALLOCATE(X(N), Y(N), Z(N), C(N), S(N))
  
  ! Example inputs
  X = (/ 1.0D0, 2.0D0, 3.0D0 /)
  Y = (/ 4.0D0, 5.0D0, 6.0D0 /)
  Z = (/ 7.0D0, 8.0D0, 9.0D0 /)
  C = (/ 0.5D0, 0.5D0, 0.5D0 /)
  S = (/ 0.5D0, 0.5D0, 0.5D0 /)

  CALL DLAR2V(N, X, Y, Z, INCX, C, S, INCC)

  ! Expected outputs
  PRINT *, 'X:', X
  PRINT *, 'Y:', Y
  PRINT *, 'Z:', Z

  DEALLOCATE(X, Y, Z, C, S)
END PROGRAM test_dlar2v

SUBROUTINE DLAR2V(N, X, Y, Z, INCX, C, S, INCC)
  INTEGER            INCC, INCX, N
  DOUBLE PRECISION   C(*), S(*), X(*), Y(*), Z(*)
  INTEGER            I, IC, IX
  DOUBLE PRECISION   CI, SI, T1, T2, T3, T4, T5, T6, XI, YI, ZI
  IX = 1
  IC = 1
  DO 10 I = 1, N
     XI = X(IX)
     YI = Y(IX)
     ZI = Z(IX)
     CI = C(IC)
     SI = S(IC)
     T1 = SI * ZI
     T2 = CI * ZI
     T3 = T2 - SI * XI
     T4 = T2 + SI * YI
     T5 = CI * XI + T1
     T6 = CI * YI - T1
     X(IX) = CI * T5 + SI * T4
     Y(IX) = CI * T6 - SI * T3
     Z(IX) = CI * T4 - SI * T5
     IX = IX + INCX
     IC = IC + INCC
10 CONTINUE
  RETURN
END