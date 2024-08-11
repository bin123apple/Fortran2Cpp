PROGRAM MonteCarloPi
  IMPLICIT NONE
  INTEGER, PARAMETER :: npts = 1000000
  INTEGER :: i
  DOUBLE PRECISION :: x, y, pi_estimate
  DOUBLE PRECISION :: inside_circle
  DOUBLE PRECISION :: rnd_x, rnd_y

  ! Initialize random seed
  CALL RANDOM_SEED()

  inside_circle = 0
  DO i = 1, npts
    CALL RANDOM_NUMBER(rnd_x)
    CALL RANDOM_NUMBER(rnd_y)
    x = rnd_x * 2.0 - 1.0  ! Scale x to [-1,1]
    y = rnd_y * 2.0 - 1.0  ! Scale y to [-1,1]
    IF (x**2 + y**2 <= 1.0) THEN
      inside_circle = inside_circle + 1
    END IF
  END DO

  pi_estimate = 4.0 * inside_circle / npts
  PRINT *, 'Estimated value of Pi:', pi_estimate

END PROGRAM MonteCarloPi