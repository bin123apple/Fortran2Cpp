PROGRAM test_clascl2
  IMPLICIT NONE
  INTEGER, PARAMETER :: M = 2, N = 3, LDX = 2
  REAL, DIMENSION(M) :: D
  COMPLEX, DIMENSION(LDX,N) :: X
  INTEGER :: i, j

  ! Initialize D and X with test values
  D = (/2.0, 0.5/)
  X = RESHAPE((/(1.0, 0.0), (0.0, 1.0), (2.0, 2.0), (3.0, -1.0), (4.0, 4.0), (5.0, -2.0)/), SHAPE(X))

  ! Call the subroutine
  CALL CLASCL2(M, N, D, X, LDX)

  ! Print the result
  DO j = 1, N
    WRITE(*,*) "Column ", j, ":"
    DO i = 1, M
      WRITE(*,'(2F6.2)') REAL(X(i,j)), AIMAG(X(i,j))
    END DO
  END DO

END PROGRAM test_clascl2

SUBROUTINE CLASCL2 ( M, N, D, X, LDX )
  IMPLICIT NONE
  INTEGER            M, N, LDX
  REAL               D( * )
  COMPLEX            X( LDX, * )
  INTEGER            I, J

  DO J = 1, N
     DO I = 1, M
        X( I, J ) = X( I, J ) * D( I )
     END DO
  END DO

  RETURN
END