! This is the SVBKSB subroutine combined with a test program
SUBROUTINE SVBKSB(U,W,V,M,N,MP,NP,B,X)
  INTEGER, INTENT(IN) :: M, N, MP, NP
  REAL, INTENT(IN) :: U(MP,NP), W(NP), V(NP,NP), B(MP)
  REAL, INTENT(OUT) :: X(NP)
  REAL, DIMENSION(NP) :: TMP
  REAL S
  INTEGER I, J, JJ
  
  DO J=1,N
    S=0.0
    IF(W(J).NE.0.0)THEN
      DO I=1,M
        S=S+U(I,J)*B(I)
      END DO
      S=S/W(J)
    ENDIF
    TMP(J)=S
  END DO
  
  DO J=1,N
    S=0.0
    DO JJ=1,N
      S=S+V(J,JJ)*TMP(JJ)
    END DO
    X(J)=S
  END DO
END SUBROUTINE SVBKSB

PROGRAM testSVBKSB
  IMPLICIT NONE
  INTEGER, PARAMETER :: M=3, N=3, MP=3, NP=3
  REAL :: U(MP,NP) = RESHAPE([1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0], [MP, NP])
  REAL :: W(NP) = [1.0, 2.0, 3.0]
  REAL :: V(NP,NP) = RESHAPE([1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0], [NP, NP])
  REAL :: B(MP) = [1.0, 2.0, 3.0]
  REAL :: X(NP)
  INTEGER :: I
  
  CALL SVBKSB(U, W, V, M, N, MP, NP, B, X)
  
  PRINT *, 'X:'
  DO I = 1, NP
    PRINT *, X(I)
  END DO
END PROGRAM testSVBKSB