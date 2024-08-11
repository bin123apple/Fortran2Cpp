PROGRAM TestDLAPY2
      DOUBLE PRECISION DLAPY2
      DOUBLE PRECISION X, Y, RESULT

      ! Test case 1
      X = 3.0D0
      Y = 4.0D0
      RESULT = DLAPY2(X, Y)
      PRINT *, 'Test 1 (3,4): Expected: 5, Got: ', RESULT

      ! Test case 2
      X = 5.0D0
      Y = 12.0D0
      RESULT = DLAPY2(X, Y)
      PRINT *, 'Test 2 (5,12): Expected: 13, Got: ', RESULT

      ! Test case 3
      X = 8.0D0
      Y = 0.0D0
      RESULT = DLAPY2(X, Y)
      PRINT *, 'Test 3 (8,0): Expected: 8, Got: ', RESULT

      ! Test case 4
      X = 0.0D0
      Y = 0.0D0
      RESULT = DLAPY2(X, Y)
      PRINT *, 'Test 4 (0,0): Expected: 0, Got: ', RESULT

      END PROGRAM TestDLAPY2

      DOUBLE PRECISION FUNCTION DLAPY2( X, Y )
      DOUBLE PRECISION   X, Y

      DOUBLE PRECISION   ZERO
      PARAMETER          ( ZERO = 0.0D0 )
      DOUBLE PRECISION   ONE
      PARAMETER          ( ONE = 1.0D0 )

      DOUBLE PRECISION   W, XABS, YABS, Z

      INTRINSIC          ABS, MAX, MIN, SQRT

      XABS = ABS( X )
      YABS = ABS( Y )
      W = MAX( XABS, YABS )
      Z = MIN( XABS, YABS )
      IF( Z.EQ.ZERO ) THEN
         DLAPY2 = W
      ELSE
         DLAPY2 = W*SQRT( ONE+( Z / W )**2 )
      END IF
      RETURN

      END