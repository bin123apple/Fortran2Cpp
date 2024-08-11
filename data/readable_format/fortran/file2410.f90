PROGRAM TestFloop18
  IMPLICIT NONE
  INTEGER :: N, i
  REAL*4, ALLOCATABLE :: x(:), a(:), b(:)
  REAL*4 :: u, v

  N = 10
  ALLOCATE(x(N), a(N), b(N))

  u = 1.0
  v = 2.0

  ! Initialize a and b arrays
  DO i = 1, N
    a(i) = REAL(i - 1) ! Adjusted to match C++ initialization
    b(i) = REAL(i)
  END DO

  ! Call the Fortran subroutine
  CALL floop18_F90(N, x, a, b, u, v)

  ! Print the result
  PRINT *, "Results from Fortran:"
  DO i = 1, N
    PRINT *, "x(", i, ") = ", x(i)
  END DO

  DEALLOCATE(x, a, b)
END PROGRAM TestFloop18

SUBROUTINE floop18_F90(N, x, a, b, u, v)
  INTEGER :: i, N
  REAL*4 :: x(N), a(N), b(N), u, v

  DO i = 1, N
    x(i) = (u + a(i)) * (v + b(i))
  END DO
END SUBROUTINE floop18_F90

SUBROUTINE floop18_F90Overhead(N, x, a, b, u, v)
  INTEGER :: i, N
  REAL*4 :: x(N), a(N), b(N), u, v
  RETURN
END SUBROUTINE floop18_F90Overhead