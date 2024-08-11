! clascl2.f90
SUBROUTINE CLASCL2 ( M, N, D, X, LDX )
  INTEGER            M, N, LDX
  REAL               D( * )
  COMPLEX            X( LDX, * )
  INTEGER            I, J

  DO J = 1, N
     DO I = 1, M
        X( I, J ) = X( I, J ) * D( I )
     END DO
  END DO

END SUBROUTINE CLASCL2

PROGRAM test_clascl2
  IMPLICIT NONE
  INTEGER, PARAMETER :: M=2, N=3, LDX=2
  REAL :: D(M) = [2.0, 3.0]
  COMPLEX :: X(LDX,N) = RESHAPE([ (1.0,1.0), (2.0,2.0), (3.0,3.0), (4.0,4.0), (5.0,5.0), (6.0,6.0) ], [LDX,N])
  INTEGER :: i, j

  CALL CLASCL2(M, N, D, X, LDX)

  PRINT *, "Scaled Matrix X:"
  DO j = 1, N
     PRINT '(2(F6.1,A))', (REAL(X(I, j)), AIMAG(X(I, j)), " ", I=1, M)
  END DO

END PROGRAM test_clascl2