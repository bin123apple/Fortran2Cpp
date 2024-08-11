PROGRAM TESTCHECK
      IMPLICIT NONE
      INTEGER :: MIN, MAX, I

      ! Test case 1
      MIN = 0
      MAX = 10
      I = 5
      CALL CHECK(MIN, MAX, I)
      PRINT *, 'Test 1: MIN=', MIN, 'MAX=', MAX

      ! Test case 2
      MIN = -1
      MAX = 6
      I = 5
      CALL CHECK(MIN, MAX, I)
      PRINT *, 'Test 2: MIN=', MIN, 'MAX=', MAX

      ! Test case 3
      MIN = 2
      MAX = 1
      I = 3
      CALL CHECK(MIN, MAX, I)
      PRINT *, 'Test 3: MIN=', MIN, 'MAX=', MAX

      END PROGRAM TESTCHECK

      SUBROUTINE CHECK (MIN, MAX, I)
      IF (MIN .LT. 1) MIN = 1
      IF (MAX .GT. I) MAX = I
      IF (MAX .LT. MIN) MAX = MIN
      RETURN
      END