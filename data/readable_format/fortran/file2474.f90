PROGRAM test_ddawts
  IMPLICIT NONE

  INTEGER, PARAMETER :: NEQ = 5
  INTEGER :: IWT, IPAR(1)
  DOUBLE PRECISION :: RTOL(NEQ), ATOL(NEQ), Y(NEQ), WT(NEQ), RPAR(1)
  INTEGER :: I

  ! Initialize input arrays
  IWT = 1
  DO I = 1, NEQ
     RTOL(I) = 0.01D0 * I
     ATOL(I) = 0.001D0 * I
     Y(I) = 1.0D0 * I
  END DO

  ! Call the subroutine
  CALL DDAWTS(NEQ, IWT, RTOL, ATOL, Y, WT, RPAR, IPAR)

  ! Print the results
  PRINT *, 'WT:'
  DO I = 1, NEQ
     PRINT *, WT(I)
  END DO

  CONTAINS

    SUBROUTINE DDAWTS (NEQ, IWT, RTOL, ATOL, Y, WT, RPAR, IPAR)
      INTEGER  NEQ, IWT, IPAR(*)
      DOUBLE PRECISION  RTOL(*), ATOL(*), Y(*), WT(*), RPAR(*)

      INTEGER  I
      DOUBLE PRECISION  ATOLI, RTOLI

      RTOLI=RTOL(1)
      ATOLI=ATOL(1)
      DO 20 I=1,NEQ
         IF (IWT .EQ.0) GO TO 10
           RTOLI=RTOL(I)
           ATOLI=ATOL(I)
10         WT(I)=RTOLI*ABS(Y(I))+ATOLI
20       CONTINUE
      RETURN
      END SUBROUTINE DDAWTS
END PROGRAM test_ddawts