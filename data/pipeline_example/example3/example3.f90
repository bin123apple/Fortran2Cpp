PROGRAM TEST_PGCT01
  IMPLICIT NONE

  REAL(KIND=8), PARAMETER :: TOL = 1E-6
  REAL(KIND=8) :: result

  INTERFACE
     REAL(KIND=8) FUNCTION PGCT01(RGB, CI, CIMIN, CIMAX)
       INTEGER, INTENT(IN) :: RGB, CI, CIMIN, CIMAX
     END FUNCTION PGCT01
  END INTERFACE

  ! Test cases
  result = PGCT01(1, 1, 0, 10)
  IF (ABS(result - SIN(1.0D0 / 10.0D0 * 3.0D0)**2) > TOL) THEN
     WRITE(*,*) "Test case 1 failed: assertion failed"
     CALL EXIT(1)
  END IF

  result = PGCT01(2, 5, 0, 10)
  IF (ABS(result - SIN(5.0D0 / 10.0D0 * 5.0D0)**2) > TOL) THEN
     WRITE(*,*) "Test case 2 failed: assertion failed"
     CALL EXIT(1)
  END IF

  result = PGCT01(3, 7, 0, 10)
  IF (ABS(result - SIN(7.0D0 / 10.0D0 * 7.0D0)**2) > TOL) THEN
     WRITE(*,*) "Test case 3 failed: assertion failed"
     CALL EXIT(1)
  END IF

  WRITE(*,*) "All test cases passed."

END PROGRAM TEST_PGCT01


REAL(KIND=8) FUNCTION PGCT01(RGB, CI, CIMIN, CIMAX)
  IMPLICIT NONE
  INTEGER, INTENT(IN) :: RGB, CI, CIMIN, CIMAX
  REAL(KIND=8) :: X
  INTEGER, PARAMETER :: R=1, G=2, B=3

  X = REAL(CI - CIMIN, KIND=8) / REAL(CIMAX - CIMIN, KIND=8)
  IF (RGB .EQ. R) THEN
    PGCT01 = SIN(X * 3.0D0)**2
  ELSEIF (RGB .EQ. G) THEN
    PGCT01 = SIN(X * 5.0D0)**2
  ELSEIF (RGB .EQ. B) THEN
    PGCT01 = SIN(X * 7.0D0)**2
  ELSE
    PGCT01 = 0.0D0  ! Default case
  END IF
END FUNCTION PGCT01