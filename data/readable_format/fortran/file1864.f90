PROGRAM testZLASCL2
  IMPLICIT NONE
  INTEGER, PARAMETER :: M = 2, N = 2, LDX = 2
  DOUBLE PRECISION :: D(M) = (/2.0, 3.0/)
  COMPLEX*16 :: X(LDX,N)
  INTEGER :: i, j
  
  ! Initialize the matrix X
  X(1,1) = (1.0, 0.0)
  X(2,1) = (2.0, 0.0)
  X(1,2) = (3.0, 0.0)
  X(2,2) = (4.0, 0.0)

  CALL ZLASCL2(M, N, D, X, LDX)

  PRINT *, "Scaled Matrix:"
  DO j = 1, N
     DO i = 1, M
        PRINT *, "X(", i, ",", j, ") = ", X(i, j)
     END DO
  END DO
END PROGRAM testZLASCL2

SUBROUTINE ZLASCL2 ( M, N, D, X, LDX )
  INTEGER            M, N, LDX
  DOUBLE PRECISION   D( * )
  COMPLEX*16         X( LDX, * )
  INTEGER            I, J
  DO J = 1, N
     DO I = 1, M
        X( I, J ) = X( I, J ) * D( I )
     END DO
  END DO
  RETURN
END