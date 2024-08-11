MODULE loop10Module
  IMPLICIT NONE
CONTAINS
  SUBROUTINE loop10_F90(N, x, a, b, c, u)
    INTEGER, INTENT(IN) :: N
    REAL(KIND=8), INTENT(INOUT) :: x(N)
    REAL(KIND=8), INTENT(IN) :: a(N), b(N), c(N), u
    INTEGER :: i

    DO i = 1, N
      x(i) = u + a(i) + b(i) + c(i)
    END DO
  END SUBROUTINE loop10_F90

  SUBROUTINE loop10_F90Overhead(N, x, a, b, c, u)
    INTEGER, INTENT(IN) :: N
    REAL(KIND=8), INTENT(INOUT) :: x(N)
    REAL(KIND=8), INTENT(IN) :: a(N), b(N), c(N), u
    ! This subroutine intentionally left blank
  END SUBROUTINE loop10_F90Overhead
END MODULE loop10Module

PROGRAM testLoop10
  USE loop10Module
  IMPLICIT NONE
  INTEGER :: N, i
  REAL(KIND=8), ALLOCATABLE :: x(:), a(:), b(:), c(:)
  REAL(KIND=8) :: u
  REAL(KIND=8), PARAMETER :: TOL = 1.0E-12
  LOGICAL :: testPassed

  N = 5
  u = 2.0
  ALLOCATE(x(N), a(N), b(N), c(N))

  ! Initialize arrays
  a = (/1.0, 2.0, 3.0, 4.0, 5.0/)
  b = (/5.0, 4.0, 3.0, 2.0, 1.0/)
  c = (/2.0, 2.0, 2.0, 2.0, 2.0/)

  CALL loop10_F90(N, x, a, b, c, u)

  ! Check results
  testPassed = .TRUE.
  DO i = 1, N
    IF (ABS(x(i) - (u + a(i) + b(i) + c(i))) > TOL) THEN
      testPassed = .FALSE.
      EXIT
    END IF
  END DO

  IF (testPassed) THEN
    PRINT *, "TEST PASSED"
  ELSE
    PRINT *, "TEST FAILED"
  END IF

  DEALLOCATE(x, a, b, c)
END PROGRAM testLoop10