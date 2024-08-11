program test_rpn2cons
  implicit none

  integer, parameter :: meqn = 5, maux = 3
  double precision :: q(meqn), flux(meqn)
  double precision :: auxvec_center(maux), auxvec_edge(maux)
  integer :: i
  double precision :: ubar, vbar
  common /comrp/ ubar, vbar

  ! Initialize variables for testing
  q = (/1.0, 2.0, 3.0, 4.0, 5.0/)
  auxvec_center = (/0.0, 0.0, 0.0/)
  auxvec_edge = (/0.0, 0.0, 0.0/)
  flux = 0.0

  ! Initialize shared variables
  ubar = 2.0
  vbar = 3.0

  ! Test rpn2cons_update with idir = 0
  call rpn2cons_update(meqn, maux, 0, 0, q, auxvec_center, auxvec_edge, flux)
  
  print *, "Testing rpn2cons_update with idir = 0..."
  do i = 1, meqn
     print *, "flux(", i, ") = ", flux(i)
  end do

  ! Reset flux for the next test
  flux = 0.0

  ! Test rpn2_cons_update_zero
  call rpn2_cons_update_zero(meqn, maux, 0, 0, q, auxvec_center, auxvec_edge, flux)
  
  print *, "Testing rpn2_cons_update_zero..."
  do i = 1, meqn
     print *, "flux(", i, ") = ", flux(i)
  end do

contains

  subroutine rpn2cons_update(meqn, maux, idir, iface, q, auxvec_center, auxvec_edge, flux)
    implicit none
    integer meqn, maux, idir, m, iface
    double precision q(meqn), flux(meqn)
    double precision auxvec_center(maux), auxvec_edge(maux)
    double precision urot
    double precision ubar, vbar
    common /comrp/ ubar, vbar

    if (idir .eq. 0) then
       urot = ubar
    else
       urot = vbar
    endif

    do m = 1, meqn
        flux(m) = urot*q(m)
    enddo
  end subroutine rpn2cons_update

  subroutine rpn2_cons_update_zero(meqn, maux, idir, iface, q, auxvec_center, auxvec_edge, flux)
    implicit none
    integer meqn, maux, idir, iface
    double precision q(meqn), flux(meqn)
    double precision auxvec_center(maux), auxvec_edge(maux)
    integer m

    do m = 1, meqn
        flux(m) = 0.0
    enddo
  end subroutine rpn2_cons_update_zero

end program test_rpn2cons