PROGRAM test_dzsum1
  IMPLICIT NONE
  COMPLEX*16, DIMENSION(5) :: cx
  DOUBLE PRECISION :: result
  INTEGER :: n, incx

  ! Initialize test data
  cx(1) = (1.0D0, 2.0D0)
  cx(2) = (2.0D0, 3.0D0)
  cx(3) = (3.0D0, 4.0D0)
  cx(4) = (4.0D0, 5.0D0)
  cx(5) = (5.0D0, 6.0D0)

  n = 5
  incx = 1

  result = DZSUM1(n, cx, incx)

  PRINT *, 'Result: ', result

CONTAINS

  DOUBLE PRECISION FUNCTION DZSUM1( N, CX, INCX )
    INTEGER, INTENT(IN) :: INCX, N
    COMPLEX*16, INTENT(IN) :: CX( * )
    INTEGER :: I, NINCX
    DOUBLE PRECISION :: STEMP

    DZSUM1 = 0.0D0
    STEMP = 0.0D0
    IF (N <= 0) THEN
      DZSUM1 = 0.0D0
      RETURN
    END IF

    IF (INCX == 1) THEN
      DO I = 1, N
        STEMP = STEMP + ABS(CX(I))
      END DO
    ELSE
      NINCX = N * INCX
      DO I = 1, NINCX, INCX
        STEMP = STEMP + ABS(CX(I))
      END DO
    END IF

    DZSUM1 = STEMP
  END FUNCTION DZSUM1

END PROGRAM test_dzsum1