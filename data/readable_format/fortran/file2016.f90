PROGRAM TestMDIAN2
      IMPLICIT NONE
      REAL, DIMENSION(5) :: X = (/1.0, 3.0, 2.0, 5.0, 4.0/)
      REAL :: XMED
      INTEGER :: N

      N = 5
      CALL MDIAN2(X, N, XMED)
      PRINT *, "Median is: ", XMED

      CONTAINS

      SUBROUTINE MDIAN2(X,N,XMED)
        INTEGER, INTENT(IN) :: N
        REAL, DIMENSION(N), INTENT(IN) :: X
        REAL, INTENT(OUT) :: XMED
        REAL, DIMENSION(N) :: XCOPY
        REAL :: BIG, AFAC, AMP, A, EPS, AP, AM, SUM, SUMX, XP, XM, XX, AA, DUM
        INTEGER :: J, NP, NM
        PARAMETER (BIG=1.E30,AFAC=1.5,AMP=1.5)
        XCOPY = X
        A=0.5*(XCOPY(1)+XCOPY(N))
        EPS=ABS(XCOPY(N)-XCOPY(1))
        AP=BIG
        AM=-BIG

1       SUM=0.
        SUMX=0.
        NP=0
        NM=0
        XP=BIG
        XM=-BIG
        DO 11 J=1,N
          XX=XCOPY(J)
          IF(XX.NE.A)THEN
            IF(XX.GT.A)THEN
              NP=NP+1
              IF(XX.LT.XP)XP=XX
            ELSE IF(XX.LT.A)THEN
              NM=NM+1
              IF(XX.GT.XM)XM=XX
            ENDIF
            DUM=1./(EPS+ABS(XX-A))
            SUM=SUM+DUM
            SUMX=SUMX+XX*DUM
          ENDIF
11      CONTINUE
        IF(NP-NM.GE.2)THEN
          AM=A
          AA=XP+MAX(0.,SUMX/SUM-A)*AMP
          IF(AA.GT.AP)AA=0.5*(A+AP)
          EPS=AFAC*ABS(AA-A)
          A=AA
          GO TO 1
        ELSE IF(NM-NP.GE.2)THEN
          AP=A
          AA=XM+MIN(0.,SUMX/SUM-A)*AMP
          IF(AA.LT.AM)AA=0.5*(A+AM)
          EPS=AFAC*ABS(AA-A)
          A=AA
          GO TO 1
        ELSE
          IF(MOD(N,2).EQ.0)THEN
            IF(NP.EQ.NM)THEN
              XMED=0.5*(XP+XM)
            ELSE IF(NP.GT.NM)THEN
              XMED=0.5*(A+XP)
            ELSE
              XMED=0.5*(XM+A)
            ENDIF
          ELSE
            IF(NP.EQ.NM)THEN
              XMED=A
            ELSE IF(NP.GT.NM)THEN
              XMED=XP
            ELSE
              XMED=XM
            ENDIF
          ENDIF
        ENDIF
        RETURN
      END SUBROUTINE MDIAN2

END PROGRAM TestMDIAN2