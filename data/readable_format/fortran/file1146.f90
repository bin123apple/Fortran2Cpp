! clawpack5_setaux.f90
SUBROUTINE clawpack5_setaux(mbc, mx, my, xlower, ylower, dx, dy, maux, aux)
  IMPLICIT NONE

  INTEGER, INTENT(IN) :: mbc, mx, my, maux
  DOUBLE PRECISION, INTENT(IN) :: xlower, ylower, dx, dy
  DOUBLE PRECISION, DIMENSION(maux, 1-mbc:mx+mbc, 1-mbc:my+mbc), INTENT(OUT) :: aux

  DOUBLE PRECISION :: rhol, cl, rhor, cr
  COMMON /comaux/ rhol, cl, rhor, cr

  INTEGER :: i, j
  DOUBLE PRECISION :: xcell

  DO j = 1-mbc, my+mbc
     DO i = 1-mbc, mx+mbc
        xcell = xlower + (i-0.5d0)*dx
        IF (xcell .LT. 0.5d0) THEN
           aux(1,i,j) = rhol
           aux(2,i,j) = cl
        ELSE
           aux(1,i,j) = rhor
           aux(2,i,j) = cr
        ENDIF
     ENDDO
  ENDDO
END SUBROUTINE clawpack5_setaux

PROGRAM test_clawpack5_setaux
  IMPLICIT NONE

  INTEGER :: mbc, mx, my, maux
  DOUBLE PRECISION :: xlower, ylower, dx, dy
  DOUBLE PRECISION, ALLOCATABLE :: aux(:,:,:)
  INTEGER :: i, j

  ! Initialize common block variables
  DOUBLE PRECISION :: rhol, cl, rhor, cr
  COMMON /comaux/ rhol, cl, rhor, cr

  ! Test parameters
  mbc = 2
  mx = 5
  my = 5
  maux = 2
  xlower = 0.0
  ylower = 0.0
  dx = 0.1
  dy = 0.1

  ! Initialize common block values
  rhol = 1.0
  cl = 2.0
  rhor = 3.0
  cr = 4.0

  ALLOCATE(aux(maux, 1-mbc:mx+mbc, 1-mbc:my+mbc))
  CALL clawpack5_setaux(mbc, mx, my, xlower, ylower, dx, dy, maux, aux)

  ! Output aux for verification
  DO j = 1-mbc, my+mbc
     DO i = 1-mbc, mx+mbc
        PRINT *, 'aux(:,', i, ',', j, ') = ', aux(:,i,j)
     ENDDO
  ENDDO

  DEALLOCATE(aux)
END PROGRAM test_clawpack5_setaux