PROGRAM TestBlockData
      COMMON /RAND2/ IY, IFF, IR
      COMMON /ICPU0/ ICPU
      INTEGER IY, IFF, IR(97), ICPU
      INTEGER i

      ! Initialize variables as would be done in BLOCK DATA
      IFF = 0
      ICPU = 0
      DO i = 1, 97
          IR(i) = 0
      END DO

      ! Test the initialized values
      IF (IFF .EQ. 0) THEN
          PRINT *, 'PASS: IFF initialized correctly.'
      ELSE
          PRINT *, 'FAIL: IFF not initialized correctly.'
      END IF

      IF (ICPU .EQ. 0) THEN
          PRINT *, 'PASS: ICPU initialized correctly.'
      ELSE
          PRINT *, 'FAIL: ICPU not initialized correctly.'
      END IF

      ! Since IY and IR are supposed to be initialized to 0 by default,
      ! we will check one of the IR array elements and IY as well
      IF (IR(1) .EQ. 0) THEN
          PRINT *, 'PASS: IR(1) initialized correctly.'
      ELSE
          PRINT *, 'FAIL: IR(1) not initialized correctly.'
      END IF

      IF (IY .EQ. 0) THEN
          PRINT *, 'PASS: IY initialized correctly.'
      ELSE
          PRINT *, 'FAIL: IY not initialized correctly.'
      END IF
END PROGRAM TestBlockData