REAL FUNCTION SLAPY3(X, Y, Z)
      REAL X, Y, Z
      REAL ZERO
      PARAMETER (ZERO = 0.0E0)
      REAL W, XABS, YABS, ZABS
      INTRINSIC ABS, MAX, SQRT
      XABS = ABS(X)
      YABS = ABS(Y)
      ZABS = ABS(Z)
      W = MAX(XABS, YABS, ZABS)
      IF (W .EQ. ZERO) THEN
         SLAPY3 = XABS + YABS + ZABS
      ELSE
         SLAPY3 = W * SQRT((XABS / W)**2 + (YABS / W)**2 + (ZABS / W)**2)
      END IF
      RETURN
      END

      PROGRAM TESTSLAPY3
      REAL SLAPY3
      PRINT *, 'Testing SLAPY3...'
      PRINT *, 'Test 1 (3, 4, 5): ', SLAPY3(3.0, 4.0, 5.0)
      PRINT *, 'Test 2 (-3, -4, -5): ', SLAPY3(-3.0, -4.0, -5.0)
      PRINT *, 'Test 3 (0, 0, 0): ', SLAPY3(0.0, 0.0, 0.0)
      PRINT *, 'Test 4 (10, 0, 0): ', SLAPY3(10.0, 0.0, 0.0)
      PRINT *, 'Test 5 (-5, 12, 0): ', SLAPY3(-5.0, 12.0, 0.0)
      END PROGRAM TESTSLAPY3