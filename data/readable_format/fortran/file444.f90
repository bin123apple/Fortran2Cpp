! Combined Fortran program with CNTAB2 subroutine and a test program
      SUBROUTINE CNTAB2(NN,NI,NJ,H,HX,HY,HYGX,HXGY,UYGX,UXGY,UXY)
      INTEGER, PARAMETER :: MAXI=100,MAXJ=100
      REAL(8) :: TINY=1.E-30
      INTEGER :: NN(NI,NJ),I,J
      REAL(8) :: SUMI(MAXI),SUMJ(MAXJ),SUM,P,H,HX,HY,HYGX,HXGY,UYGX,UXGY,UXY

      SUM=0
      DO I=1,NI
        SUMI(I)=0.0
        DO J=1,NJ
          SUMI(I)=SUMI(I)+NN(I,J)
          SUM=SUM+NN(I,J)
        END DO
      END DO

      DO J=1,NJ
        SUMJ(J)=0.0
        DO I=1,NI
          SUMJ(J)=SUMJ(J)+NN(I,J)
        END DO
      END DO

      HX=0.0
      DO I=1,NI
        IF(SUMI(I).NE.0)THEN
          P=SUMI(I)/SUM
          HX=HX-P*LOG(P)
        END IF
      END DO

      HY=0.0
      DO J=1,NJ
        IF(SUMJ(J).NE.0)THEN
          P=SUMJ(J)/SUM
          HY=HY-P*LOG(P)
        END IF
      END DO

      H=0.0
      DO I=1,NI
        DO J=1,NJ
          IF(NN(I,J).NE.0)THEN
            P=NN(I,J)/SUM
            H=H-P*LOG(P)
          END IF
        END DO
      END DO

      HYGX=H-HX
      HXGY=H-HY
      UYGX=(HY-HYGX)/(HY+TINY)
      UXGY=(HX-HXGY)/(HX+TINY)
      UXY=2.*(HX+HY-H)/(HX+HY+TINY)

      RETURN
      END

      PROGRAM TestCNTAB2
      IMPLICIT NONE
      INTEGER, PARAMETER :: NI=2, NJ=2
      INTEGER :: NN(NI,NJ)
      DOUBLE PRECISION :: H, HX, HY, HYGX, HXGY, UYGX, UXGY, UXY

      ! Initialize a simple 2x2 contingency table
      NN(1,1) = 10
      NN(1,2) = 20
      NN(2,1) = 30
      NN(2,2) = 40

      CALL CNTAB2(NN, NI, NJ, H, HX, HY, HYGX, HXGY, UYGX, UXGY, UXY)

      PRINT *, 'H:', H
      PRINT *, 'HX:', HX
      PRINT *, 'HY:', HY
      PRINT *, 'HYGX:', HYGX
      PRINT *, 'HXGY:', HXGY
      PRINT *, 'UYGX:', UYGX
      PRINT *, 'UXGY:', UXGY
      PRINT *, 'UXY:', UXY

      END PROGRAM TestCNTAB2