MODULE daxpy_module
  IMPLICIT NONE
  CONTAINS
    SUBROUTINE daxpy(N, DA, DX, INCX, DY, INCY)
      INTEGER, INTENT(IN) :: N
      REAL, INTENT(IN) :: DA
      REAL, DIMENSION(*), INTENT(IN) :: DX
      INTEGER, INTENT(IN) :: INCX
      REAL, DIMENSION(*), INTENT(INOUT) :: DY
      INTEGER, INTENT(IN) :: INCY
      INTEGER :: i

      DO i = 1, N, INCX
        DY(i) = DA * DX(i) + DY(i)
      END DO
    END SUBROUTINE daxpy
END MODULE daxpy_module

PROGRAM test_daxpy
  USE daxpy_module
  IMPLICIT NONE
  INTEGER :: N = 5
  REAL :: DA = 2.0
  REAL, DIMENSION(5) :: DX = [1.0, 2.0, 3.0, 4.0, 5.0]
  REAL, DIMENSION(5) :: DY = [1.0, 1.0, 1.0, 1.0, 1.0]
  INTEGER :: INCX = 1, INCY = 1
  INTEGER :: i

  CALL daxpy(N, DA, DX, INCX, DY, INCY)

  PRINT *, "Result DY:"
  DO i = 1, N
    PRINT *, DY(i)
  END DO
END PROGRAM test_daxpy