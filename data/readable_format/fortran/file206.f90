PROGRAM TestDROTG
      IMPLICIT NONE

      DOUBLE PRECISION DA,DB,C,S

      ! Test 1
      DA = 3.0D0
      DB = 4.0D0
      CALL DROTG(DA,DB,C,S)
      PRINT *, 'Test 1: ', DA, DB, C, S

      ! Test 2
      DA = 0.0D0
      DB = 0.0D0
      CALL DROTG(DA,DB,C,S)
      PRINT *, 'Test 2: ', DA, DB, C, S

      ! Test 3
      DA = -3.0D0
      DB = 4.0D0
      CALL DROTG(DA,DB,C,S)
      PRINT *, 'Test 3: ', DA, DB, C, S

      CONTAINS

      SUBROUTINE DROTG(DA,DB,C,S)

      DOUBLE PRECISION DA,DB,C,S,ROE,SCALE,R,Z,ONE,ZERO
      DATA ONE, ZERO /1.0D+00, 0.0D+00/

      ROE = DB
      IF( ABS(DA) .GT. ABS(DB) ) ROE = DA
      SCALE = ABS(DA) + ABS(DB)
      IF( SCALE .NE. ZERO ) GO TO 10
         C = ONE
         S = ZERO
         R = ZERO
         GO TO 20
   10 R = SCALE*SQRT((DA/SCALE)**2 + (DB/SCALE)**2)
      R = SIGN(ONE,ROE)*R
      C = DA/R
      S = DB/R
   20 Z = S
      IF( ABS(C) .GT. ZERO .AND. ABS(C) .LE. S ) Z = ONE/C
      DA = R
      DB = Z
      RETURN
      END SUBROUTINE DROTG

      END PROGRAM TestDROTG