! Filename: slar2v.f90

SUBROUTINE SLAR2V( N, X, Y, Z, INCX, C, S, INCC )
      INTEGER            INCC, INCX, N
      REAL               C( * ), S( * ), X( * ), Y( * ), Z( * )
      INTEGER            I, IC, IX
      REAL               CI, SI, T1, T2, T3, T4, T5, T6, XI, YI, ZI

      IX = 1
      IC = 1
      DO I = 1, N
         XI = X( IX )
         YI = Y( IX )
         ZI = Z( IX )
         CI = C( IC )
         SI = S( IC )
         T1 = SI*ZI
         T2 = CI*ZI
         T3 = T2 - SI*XI
         T4 = T2 + SI*YI
         T5 = CI*XI + T1
         T6 = CI*YI - T1
         X( IX ) = CI*T5 + SI*T4
         Y( IX ) = CI*T6 - SI*T3
         Z( IX ) = CI*T4 - SI*T5
         IX = IX + INCX
         IC = IC + INCC
      END DO

END SUBROUTINE SLAR2V

PROGRAM TestSLAR2V
  IMPLICIT NONE
  INTEGER :: N, INCX, INCC
  REAL, DIMENSION(:), ALLOCATABLE :: X, Y, Z, C, S
  
  N = 3
  INCX = 1
  INCC = 1
  ALLOCATE(X(N), Y(N), Z(N), C(N), S(N))
  
  X = [1.0, 2.0, 3.0]
  Y = [4.0, 5.0, 6.0]
  Z = [7.0, 8.0, 9.0]
  C = [0.5, 0.5, 0.5]
  S = [0.5, 0.5, 0.5]
  
  CALL SLAR2V(N, X, Y, Z, INCX, C, S, INCC)
  
  PRINT *, 'X:', X
  PRINT *, 'Y:', Y
  PRINT *, 'Z:', Z
  
  DEALLOCATE(X, Y, Z, C, S)
END PROGRAM TestSLAR2V