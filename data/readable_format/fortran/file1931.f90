PROGRAM testZLASCL2
  IMPLICIT NONE
  INTEGER, PARAMETER :: M = 2, N = 2, LDX = 2
  DOUBLE PRECISION, DIMENSION(M) :: D
  COMPLEX*16, DIMENSION(LDX,N) :: X
  INTEGER :: I, J

  ! Initialize D and X
  D = (/2.0d0, 3.0d0/)
  X(1,1) = (1.0d0, 0.0d0)
  X(1,2) = (2.0d0, -1.0d0)
  X(2,1) = (-1.0d0, 1.0d0)
  X(2,2) = (0.0d0, 2.0d0)

  CALL ZLASCL2(M, N, D, X, LDX)

  ! Print the results
  DO J = 1, N
     DO I = 1, M
        WRITE(*,*) 'X(',I,',',J,') = ', X(I,J)
     END DO
  END DO

END PROGRAM testZLASCL2

SUBROUTINE ZLASCL2 ( M, N, D, X, LDX )
  IMPLICIT NONE
  INTEGER            M, N, LDX
  DOUBLE PRECISION   D( * )
  COMPLEX*16         X( LDX, * )
  INTEGER            I, J

  DO J = 1, N
     DO I = 1, M
        X(I,J) = X(I,J) * D(I)
     END DO
  END DO

  RETURN
END