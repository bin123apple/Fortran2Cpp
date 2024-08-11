PROGRAM main
  IMPLICIT NONE
  REAL :: di(5)
  INTEGER :: i

  i = 1
  di = 0.0
  CALL sub(di, i)

  IF (fun(di, 1, 2) /= 5.0) CALL abort()
  IF (i /= 4) CALL abort()

  PRINT *, "All tests passed successfully."

CONTAINS

  SUBROUTINE sub(vec, ny)
    IMPLICIT NONE
    REAL, DIMENSION(:), INTENT(INOUT) :: vec
    INTEGER, INTENT(INOUT) :: ny
    ny = fun(vec, ny, 1)
  END SUBROUTINE sub

  REAL FUNCTION fun(r1, i1, i2)
    REAL, DIMENSION(:), INTENT(INOUT) :: r1
    INTEGER, INTENT(IN) :: i1, i2
    r1(i1) = i1 + 1.0
    r1(i2) = i2 + 1.0
    fun = r1(i1) + r1(i2)
  END FUNCTION fun

END PROGRAM main