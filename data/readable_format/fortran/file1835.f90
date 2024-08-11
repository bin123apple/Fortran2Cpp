PROGRAM TEST_DLAMC3
      DOUBLE PRECISION DLAMC3
      DOUBLE PRECISION A, B, RESULT

      A = 1.0
      B = 2.0
      RESULT = DLAMC3(A, B)
      PRINT *, 'Test 1 (1.0 + 2.0): Expected: 3.0, Got:', RESULT

      A = -1.5
      B = 2.5
      RESULT = DLAMC3(A, B)
      PRINT *, 'Test 2 (-1.5 + 2.5): Expected: 1.0, Got:', RESULT

      A = 123456.789
      B = 987654.321
      RESULT = DLAMC3(A, B)
      PRINT *, 'Test 3 (123456.789 + 987654.321): Expected: 1111111.11, Got:', RESULT

      END

      DOUBLE PRECISION FUNCTION DLAMC3( A, B )
      DOUBLE PRECISION   A, B
      DLAMC3 = A + B
      RETURN
      END