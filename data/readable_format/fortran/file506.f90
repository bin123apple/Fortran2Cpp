! CombinedModuleAndProgram.f90
MODULE DCOPY__genmod
  IMPLICIT NONE
CONTAINS
  SUBROUTINE DCOPY(N, DX, INCX, DY, INCY)
    INTEGER, INTENT(IN) :: N, INCX, INCY
    REAL(KIND=8), INTENT(IN) :: DX(*)
    REAL(KIND=8), INTENT(OUT) :: DY(*)
    INTEGER :: i, ix, iy
    
    ix = 1
    iy = 1
    DO i = 1, N
      DY(iy) = DX(ix)
      ix = ix + INCX
      iy = iy + INCY
    END DO
  END SUBROUTINE DCOPY
END MODULE DCOPY__genmod

PROGRAM TestDCOPY
  USE DCOPY__genmod
  IMPLICIT NONE
  INTEGER :: n, incx, incy
  REAL(KIND=8), ALLOCATABLE :: dx(:), dy(:)
  
  ! Example usage
  n = 5
  incx = 1
  incy = 1
  ALLOCATE(dx(n), dy(n))
  dx = [1.0D0, 2.0D0, 3.0D0, 4.0D0, 5.0D0]
  dy = 0.0D0
  
  CALL DCOPY(n, dx, incx, dy, incy)
  
  PRINT *, "DX:", dx
  PRINT *, "DY after DCOPY:", dy
  
END PROGRAM TestDCOPY