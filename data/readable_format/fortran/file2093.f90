PROGRAM TestLagzo
    IMPLICIT NONE
    INTEGER, PARAMETER :: dp = KIND(1.0D0)
    INTEGER, PARAMETER :: N = 5
    REAL(KIND=dp) :: X(N), W(N)
    INTEGER :: i

    CALL LAGZO(N, X, W)

    PRINT *, 'X:', (X(i), i = 1, N)
    PRINT *, 'W:', (W(i), i = 1, N)

END PROGRAM TestLagzo

! The LAGZO subroutine definition follows directly
SUBROUTINE LAGZO(N,X,W)
    IMPLICIT DOUBLE PRECISION (A-H,O-Z)
    INTEGER N
    DOUBLE PRECISION X(N),W(N)
    DOUBLE PRECISION HN,Z,Z0,P,F0,F1,PF,PD,FD,Q,WP,GD
    INTEGER NR,I,K,IT,J

    HN=1.0D0/N
    DO 35 NR=1,N
       IF (NR.EQ.1) Z=HN
       IF (NR.GT.1) Z=X(NR-1)+HN*NR**1.27
       IT=0
10     IT=IT+1
       Z0=Z
       P=1.0D0
       DO 15 I=1,NR-1
15         P=P*(Z-X(I))
       F0=1.0D0
       F1=1.0D0-Z
       DO 20 K=2,N
          PF=((2.0D0*K-1.0D0-Z)*F1-(K-1.0D0)*F0)/K
          F0=F1
20        F1=PF
       PD=N/Z*(F1-F0)  ! Correction in the calculation of PD
       FD=F1/P
       Q=0.0D0
       DO 30 I=1,NR-1
          WP=1.0D0
          DO 25 J=1,NR-1
             IF (J.EQ.I) GO TO 25
             WP=WP*(Z-X(J))
25        CONTINUE
          Q=Q+WP
30     CONTINUE
       GD=(PD-Q*FD)/P
       Z=Z-FD/GD
       IF (IT.LE.40.AND.DABS((Z-Z0)/Z).GT.1.0D-15) GO TO 10
       X(NR)=Z
       W(NR)=1.0D0/(Z*PD*PD)
35  CONTINUE
    RETURN
END SUBROUTINE LAGZO