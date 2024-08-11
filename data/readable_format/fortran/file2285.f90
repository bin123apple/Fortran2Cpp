module updat_mod
  implicit none
  save

contains

  subroutine updat(u, udt, udtt, ui, neq, a6, a7, a8, a9, a10)
    implicit none
    integer, intent(in) :: neq
    real(8), intent(in) :: a6, a7, a8, a9, a10
    real(8), intent(inout) :: u(neq), udt(neq), udtt(neq), ui(neq)
    integer :: i
    real(8) :: udttld

    do i = 1, neq
      u(i) = u(i) + ui(i)
    end do

    do i = 1, neq
      udttld = udtt(i)
      udtt(i) = a6 * ui(i) + a7 * udt(i) + a8 * udttld
      udt(i) = udt(i) + a9 * udttld + a10 * udtt(i)
    end do
  end subroutine updat

end module updat_mod

program test_updat
  use updat_mod
  implicit none

  integer :: neq
  real(8) :: a6, a7, a8, a9, a10
  real(8), allocatable :: u(:), udt(:), udtt(:), ui(:)

  ! Initialize test variables
  neq = 5
  a6 = 1.0
  a7 = 1.0
  a8 = 1.0
  a9 = 1.0
  a10 = 1.0
  allocate(u(neq), udt(neq), udtt(neq), ui(neq))
  u = (/1.0, 2.0, 3.0, 4.0, 5.0/)
  udt = (/0.1, 0.2, 0.3, 0.4, 0.5/)
  udtt = (/0.01, 0.02, 0.03, 0.04, 0.05/)
  ui = (/0.5, 0.5, 0.5, 0.5, 0.5/)

  call updat(u, udt, udtt, ui, neq, a6, a7, a8, a9, a10)

  print *, "u: ", u
  print *, "udt: ", udt
  print *, "udtt: ", udtt
end program test_updat