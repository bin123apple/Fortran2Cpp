program test_qinit
  implicit none
  double precision :: dx, xlower
  integer :: maxmx, meqn, mbc, mx, maux
  double precision, allocatable :: q(:,:), aux(:,:)
  double precision :: beta
  integer :: i, j

  ! Initialize variables
  maxmx = 10
  meqn = 1
  mbc = 2
  mx = 5
  xlower = -0.5
  dx = 0.2
  maux = 0
  beta = 0.0

  ! Allocate arrays
  allocate(q(1-mbc:maxmx+mbc, meqn))
  ! Assuming aux is not used in this test, but allocated to comply with subroutine arguments
  allocate(aux(1-mbc:maxmx+mbc, 1))

  ! Call the subroutine
  call qinit(maxmx, meqn, mbc, mx, xlower, dx, q, maux, aux)

  ! Check results
  do i = 1, mx
    if (i <= 2) then
      if (q(i,1) /= 0.13d0) then
        print *, "Test failed for i=", i
        stop
      end if
    else
      if (q(i,1) /= 0.1d0) then
        print *, "Test failed for i=", i
        stop
      end if
    end if
  end do

  print *, "Fortran test passed."

  contains

    subroutine qinit(maxmx,meqn,mbc,mx,xlower,dx,q,maux,aux)
      implicit double precision (a-h,o-z)
      integer :: maxmx, meqn, mbc, mx, maux
      double precision :: xlower, dx
      double precision, dimension(1-mbc:maxmx+mbc, meqn) :: q
      double precision, dimension(1-mbc:maxmx+mbc, *) :: aux
      double precision :: xcell, ql, qr
      integer :: i

      common /comic/ beta

      ql = 0.13d0
      qr = 0.1d0

      do i=1,mx
         xcell = xlower + (i-0.5d0)*dx
         if (xcell .lt. 0.d0) then
             q(i,1) = ql
           else
             q(i,1) = qr
           endif
      end do

      return
    end subroutine qinit

end program test_qinit