MODULE arrays

  IMPLICIT NONE

CONTAINS

  FUNCTION array_in(n, x) RESULT(y)
    INTEGER, INTENT(in) :: n
    INTEGER, INTENT(in) :: x(n)
    INTEGER :: y
    y = SUM(x)
  END FUNCTION array_in

  SUBROUTINE array_out(nx, ny, x, y)
    INTEGER, INTENT(in) :: nx, ny
    INTEGER, INTENT(out) :: x(nx)
    INTEGER, DIMENSION(ny), INTENT(out) :: y
    x = 20
    y = 30
  END SUBROUTINE array_out

  FUNCTION inner_prod(n, a, b) RESULT(y)
    INTEGER, INTENT(in) :: n
    INTEGER, INTENT(in), dimension(n) :: a, b
    INTEGER :: y
    y = DOT_PRODUCT(a, b)
  END FUNCTION inner_prod

  FUNCTION inner_prod_2(n, a, b) RESULT(y)
    INTEGER, INTENT(in) :: n
    INTEGER, INTENT(in), DIMENSION(*) :: a
    INTEGER, INTENT(in) :: b(*)
    INTEGER :: y
    y = DOT_PRODUCT(a(1:n), b(1:n))
  END FUNCTION inner_prod_2

END MODULE arrays

PROGRAM test_arrays
  USE arrays
  IMPLICIT NONE
  INTEGER :: n, res, i
  INTEGER, ALLOCATABLE :: a(:), b(:), x(:), y(:)

  ! Test array_in
  n = 5
  ALLOCATE(a(n))
  a = (/1, 2, 3, 4, 5/)
  res = array_in(n, a)
  PRINT *, "Test array_in: Expected 15, Got", res

  ! Test array_out
  ALLOCATE(x(3), y(2))
  CALL array_out(3, 2, x, y)
  PRINT *, "Test array_out: Expected all 20s for x and all 30s for y"
  PRINT *, "Got x:", x
  PRINT *, "Got y:", y

  ! Test inner_prod
  ALLOCATE(b(n))
  b = (/5, 4, 3, 2, 1/)
  res = inner_prod(n, a, b)
  PRINT *, "Test inner_prod: Expected 35, Got", res

  ! Test inner_prod_2
  res = inner_prod_2(n, a, b)
  PRINT *, "Test inner_prod_2: Expected 35, Got", res

  DEALLOCATE(a, b, x, y)
END PROGRAM test_arrays