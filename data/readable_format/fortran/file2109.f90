SUBROUTINE ZLAR2V( N, X, Y, Z, INCX, C, S, INCC )
      INTEGER            INCC, INCX, N
      DOUBLE PRECISION   C( * )
      COMPLEX*16         S( * ), X( * ), Y( * ), Z( * )
      INTEGER            I, IC, IX
      DOUBLE PRECISION   CI, SII, SIR, T1I, T1R, T5, T6, XI, YI, ZII, ZIR
      COMPLEX*16         SI, T2, T3, T4, ZI
      INTRINSIC          DBLE, DCMPLX, DCONJG, DIMAG

      IX = 1
      IC = 1
      DO I = 1, N
         XI = DBLE( X( IX ) )
         YI = DBLE( Y( IX ) )
         ZI = Z( IX )
         ZIR = DBLE( ZI )
         ZII = DIMAG( ZI )
         CI = C( IC )
         SI = S( IC )
         SIR = DBLE( SI )
         SII = DIMAG( SI )
         T1R = SIR*ZIR - SII*ZII
         T1I = SIR*ZII + SII*ZIR
         T2 = CI*ZI
         T3 = T2 - DCONJG( SI )*XI
         T4 = DCONJG( T2 ) + SI*YI
         T5 = CI*XI + T1R
         T6 = CI*YI - T1R
         X( IX ) = CI*T5 + ( SIR*DBLE( T4 ) + SII*DIMAG( T4 ) )
         Y( IX ) = CI*T6 - ( SIR*DBLE( T3 ) - SII*DIMAG( T3 ) )
         Z( IX ) = CI*T3 + DCONJG( SI )*DCMPLX( T6, T1I )
         IX = IX + INCX
         IC = IC + INCC
      END DO
      RETURN
      END

      PROGRAM testZLAR2V
      IMPLICIT NONE
      INTEGER, PARAMETER :: N = 3
      INTEGER :: INCX, INCC
      DOUBLE PRECISION :: C(N)
      COMPLEX*16 :: S(N), X(N), Y(N), Z(N)
      INTEGER :: i

      INCX = 1
      INCC = 1
      C = (/1.0D0, 2.0D0, 3.0D0/)
      S = (/(1.0D0, 2.0D0), (2.0D0, 3.0D0), (3.0D0, 4.0D0)/)
      X = (/(1.0D0, 1.0D0), (2.0D0, 2.0D0), (3.0D0, 3.0D0)/)
      Y = (/(4.0D0, 4.0D0), (5.0D0, 5.0D0), (6.0D0, 6.0D0)/)
      Z = (/(7.0D0, 7.0D0), (8.0D0, 8.0D0), (9.0D0, 9.0D0)/)

      CALL ZLAR2V(N, X, Y, Z, INCX, C, S, INCC)

      PRINT *, 'X:'
      DO i = 1, N
          PRINT *, X(i)
      END DO

      PRINT *, 'Y:'
      DO i = 1, N
          PRINT *, Y(i)
      END DO

      PRINT *, 'Z:'
      DO i = 1, N
          PRINT *, Z(i)
      END DO
      END PROGRAM testZLAR2V