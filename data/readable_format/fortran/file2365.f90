REAL FUNCTION D1(Y, H, N)
      REAL, DIMENSION(N) :: Y
      REAL H
      INTEGER N
      REAL C1, C2, C3, C4, R20
      INTEGER I, IP
      REAL SIGN
      DATA C1 /-21.0/, C2 /13.0/, C3 /17.0/, C4 /-9.0/, R20 /0.05/

      I = 1
      IP = 1
      SIGN = 1.0
      D1 = SIGN * (C1*Y(IP)+C2*Y(IP+I)+C3*Y(IP+2*I)+C4*Y(IP+3*I)) * R20 / H
      RETURN
      END

      REAL FUNCTION DN(Y, H, N)
      REAL, DIMENSION(N) :: Y
      REAL H
      INTEGER N
      REAL C1, C2, C3, C4, R20
      INTEGER I, IP
      REAL SIGN
      DATA C1 /-21.0/, C2 /13.0/, C3 /17.0/, C4 /-9.0/, R20 /0.05/

      I = -1
      IP = N
      SIGN = -1.0
      DN = SIGN * (C1*Y(IP)+C2*Y(IP+I)+C3*Y(IP+2*I)+C4*Y(IP+3*I)) * R20 / H
      RETURN
      END

      PROGRAM TestD1DN
      REAL Y(5)
      REAL H
      INTEGER N
      REAL D1_RESULT, DN_RESULT

      Y(1) = 1.0
      Y(2) = 2.0
      Y(3) = 3.0
      Y(4) = 4.0
      Y(5) = 5.0
      H = 1.0
      N = 5

      D1_RESULT = D1(Y, H, N)
      DN_RESULT = DN(Y, H, N)

      PRINT *, 'D1 Result: ', D1_RESULT
      PRINT *, 'DN Result: ', DN_RESULT
      PRINT *, 'Expected D1: ', (-21.0*1.0 + 13.0*2.0 + 17.0*3.0 - 9.0*4.0) * 0.05 / H
      PRINT *, 'Expected DN: ', (-21.0*5.0 + 13.0*4.0 + 17.0*3.0 - 9.0*2.0) * 0.05 * -1.0 / H

      END PROGRAM TestD1DN