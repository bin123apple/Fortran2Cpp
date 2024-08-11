SUBROUTINE GRID2TRIPLE(X,Y,Z,MX,NY,D,LDMAX,LD,ZMSG,IER)
      IMPLICIT NONE
      INTEGER MX,NY,LDMAX
      DOUBLE PRECISION X(MX),Y(NY),Z(MX,NY),ZMSG
      INTEGER LD,IER
      DOUBLE PRECISION D(LDMAX,3)

      INTEGER M,N

      LD = 0
      IER = 0

      DO N = 1,NY
          DO M = 1,MX
              IF (Z(M,N).NE.ZMSG) THEN
                  IF (LD .LT. LDMAX) THEN
                      LD = LD + 1
                      D(LD,1) = X(M)
                      D(LD,2) = Y(N)
                      D(LD,3) = Z(M,N)
                  ELSE
                      IER = -11
                      RETURN
                  END IF
              END IF
          END DO
      END DO

      IF (LD.EQ.0) THEN
          IER = -10
      END IF
      RETURN
      END

      PROGRAM test_grid2triple
      IMPLICIT NONE
      INTEGER, PARAMETER :: MX=2, NY=2, LDMAX=4
      DOUBLE PRECISION X(MX), Y(NY), Z(MX,NY), ZMSG, D(LDMAX,3)
      INTEGER LD, IER, M, N

      ! Scenario 1: All Z values are different from ZMSG
      PRINT *, 'Scenario 1'
      ZMSG = -999.0
      LD = 0
      DO N = 1, NY
          DO M = 1, MX
              X(M) = M
              Y(N) = N
              Z(M,N) = M + N
          END DO
      END DO
      CALL GRID2TRIPLE(X,Y,Z,MX,NY,D,LDMAX,LD,ZMSG,IER)
      PRINT *, 'LD = ', LD
      PRINT *, 'D = ', D
      PRINT *, 'IER = ', IER

      ! Scenario 2: Some Z values equal to ZMSG
      PRINT *, 'Scenario 2'
      Z(1,1) = ZMSG
      CALL GRID2TRIPLE(X,Y,Z,MX,NY,D,LDMAX,LD,ZMSG,IER)
      PRINT *, 'LD = ', LD
      PRINT *, 'D = ', D
      PRINT *, 'IER = ', IER

      ! Scenario 3: All Z values equal to ZMSG
      PRINT *, 'Scenario 3'
      DO N = 1, NY
          DO M = 1, MX
              Z(M,N) = ZMSG
          END DO
      END DO
      CALL GRID2TRIPLE(X,Y,Z,MX,NY,D,LDMAX,LD,ZMSG,IER)
      PRINT *, 'LD = ', LD
      PRINT *, 'IER = ', IER

      END PROGRAM test_grid2triple