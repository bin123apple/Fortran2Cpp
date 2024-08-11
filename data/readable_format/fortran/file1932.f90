! This program combines the SLAG2D subroutine and a test program into a single file.
PROGRAM TestSLAG2D
  IMPLICIT NONE
  INTEGER, PARAMETER :: M = 2, N = 3
  REAL, DIMENSION(M,N) :: SA = RESHAPE([1.0, 2.0, 3.0, 4.0, 5.0, 6.0], [M, N])
  DOUBLE PRECISION, DIMENSION(M,N) :: A
  INTEGER :: INFO, i, j

  CALL SLAG2D(M, N, SA, M, A, M, INFO)

  PRINT *, 'Converted matrix A:'
  DO i = 1, M
     PRINT '(3F6.2)', (A(i, j), j=1, N)
  END DO

CONTAINS

  SUBROUTINE SLAG2D( M, N, SA, LDSA, A, LDA, INFO )
    INTEGER            INFO, LDA, LDSA, M, N
    REAL               SA( LDSA, * )
    DOUBLE PRECISION   A( LDA, * )
    INTEGER            I, J

    INFO = 0
    DO J = 1, N
       DO I = 1, M
          A( I, J ) = SA( I, J )
       END DO
    END DO
  END SUBROUTINE SLAG2D

END PROGRAM TestSLAG2D