SUBROUTINE FGAUSS(X,A,Y,DYDA,NA)
      IMPLICIT NONE
      DOUBLE PRECISION X, A(*), Y, DYDA(*)
      INTEGER NA, I
      DOUBLE PRECISION ARG, EX, FAC

      Y=0.0D0
      DO I=1,NA-1,3
        ARG=(X-A(I+1))/A(I+2)
        EX=EXP(-ARG**2)
        FAC=A(I)*EX*2.0D0*ARG
        Y=Y+A(I)*EX
        DYDA(I)=EX
        DYDA(I+1)=FAC/A(I+2)
        DYDA(I+2)=FAC*ARG/A(I+2)
      END DO
      END SUBROUTINE FGAUSS

      PROGRAM TestFGauss
      IMPLICIT NONE
      DOUBLE PRECISION A(6), DYDA(6), Y, X
      INTEGER NA, I

      NA = 6
      A = (/1.0D0, 2.0D0, 3.0D0, 4.0D0, 5.0D0, 6.0D0/)
      X = 2.5D0

      CALL FGAUSS(X, A, Y, DYDA, NA)

      PRINT *, 'Y:', Y
      PRINT *, 'DYDA:'
      DO I = 1, NA
        PRINT *, DYDA(I)
      END DO
      END PROGRAM TestFGauss