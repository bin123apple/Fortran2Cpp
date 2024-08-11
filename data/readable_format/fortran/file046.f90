! TBKSB.f90
SUBROUTINE TBKSB(W,V,N,NP,B,X)
  IMPLICIT NONE
  INTEGER N,NP
  DOUBLE PRECISION V(NP,NP),W(NP),B(NP),X(NP)
  DOUBLE PRECISION S,WTMP,VTMP,XTMP,BTMP
  INTEGER I,J,K
  DO I=1,N
     X(I) = 0.0D0
  END DO
  DO K=1,N
     IF(W(K).NE.0.0D0)THEN
        WTMP = 1.0D0/W(K)
        DO I=1,N
           X(I) = X(I) + V(I,K)*WTMP*V(I,K)*B(I)
        END DO
        DO I=1,N-1
           XTMP = X(I)
           BTMP = B(I)
           VTMP = V(I,K)
           DO J=I+1,N
              S = VTMP*WTMP*V(J,K)
              XTMP = XTMP + S*B(J)
              X(J) = X(J) + S*BTMP
           END DO
           X(I) = XTMP
        END DO
     ENDIF
  END DO
END SUBROUTINE TBKSB

PROGRAM testTBKSB
  IMPLICIT NONE
  INTEGER, PARAMETER :: NP=3, N=3
  DOUBLE PRECISION, DIMENSION(NP,NP) :: V
  DOUBLE PRECISION, DIMENSION(NP) :: W, B, X
  INTEGER :: i
  
  ! Initialize inputs
  W = (/1.0D0, 2.0D0, 3.0D0/)
  V = RESHAPE((/1.0D0, 0.0D0, 0.0D0, 0.0D0, 1.0D0, 0.0D0, 0.0D0, 0.0D0, 1.0D0/), SHAPE(V))
  B = (/1.0D0, 2.0D0, 3.0D0/)
  
  ! Call the subroutine
  CALL TBKSB(W,V,N,NP,B,X)
  
  ! Output the result for verification
  PRINT *, 'Output X:'
  DO i=1,NP
     PRINT *, X(i)
  END DO
END PROGRAM testTBKSB