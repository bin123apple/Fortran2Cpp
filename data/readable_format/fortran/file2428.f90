! File: clascl2.f90
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

PROGRAM TestCLASCL2
  IMPLICIT NONE
  INTEGER :: M, N, LDX, I, J
  REAL, DIMENSION(3) :: D
  COMPLEX, DIMENSION(3, 2) :: X

  ! Initialize dimensions and data
  M = 3
  N = 2
  LDX = 3
  D = (/ 1.0, 2.0, 3.0 /)
  X = RESHAPE((/ (1.0, 0.0), (2.0, 0.0), (3.0, 0.0), &
                (4.0, 0.0), (5.0, 0.0), (6.0, 0.0) /), (/3, 2/))

  ! Call the subroutine
  CALL CLASCL2(M, N, D, X, LDX)

  ! Output the result for verification
  DO J = 1, N
     DO I = 1, M
        PRINT *, 'X(', I, ',', J, ') = ', X(I, J)
     END DO
  END DO
END PROGRAM TestCLASCL2