PROGRAM testLoop17
  IMPLICIT NONE
  INTEGER, PARAMETER :: N = 5
  REAL*8 :: x(N), a(N), b(N), c(N), d(N)
  INTEGER :: i
  LOGICAL :: testPassed

  ! Initialize test data
  DO i = 1, N
      a(i) = REAL(i)
      b(i) = REAL(i) * 2.0
      c(i) = REAL(i) * 3.0
      d(i) = REAL(i) * 4.0
  END DO
  
  ! Call the subroutine
  CALL loop17_F77(N, x, a, b, c, d)
  
  ! Check results
  testPassed = .TRUE.
  DO i = 1, N
      IF (x(i) /= (a(i) + b(i)) * (c(i) + d(i))) THEN
          testPassed = .FALSE.
          EXIT
      END IF
  END DO
  
  IF (testPassed) THEN
      PRINT *, "Test Passed"
  ELSE
      PRINT *, "Test Failed"
  END IF
END PROGRAM testLoop17

SUBROUTINE loop17_F77(N, x, a, b, c, d)
  INTEGER :: i, N
  REAL*8 :: x(N), a(N), b(N), c(N), d(N)
  
  ! Perform the operations
  DO i=1,N
      x(i)=(a(i)+b(i))*(c(i)+d(i))
  END DO
  RETURN
END

SUBROUTINE loop17_F77Overhead(N, x, a, b, c, d)
  INTEGER :: i, N
  REAL*8 :: x(N), a(N), b(N), c(N), d(N)
  ! This subroutine does nothing
  RETURN
END