module rrsw_kg16_mod
  use, intrinsic :: iso_fortran_env, only: real64
  implicit none
  save

  integer, parameter :: no16 = 16
  real(kind=real64) :: rayl
  real(kind=real64), dimension(585, no16) :: absa
  real(kind=real64), dimension(235, no16) :: absb

contains

  subroutine initialize()
    integer :: i
    rayl = 1.0_real64
    do i = 1, 585
      absa(i, 1) = real(i, real64)
    end do
    do i = 1, 235
      absb(i, 1) = real(i + 1000, real64)
    end do
  end subroutine initialize

end module rrsw_kg16_mod

program test_rrsw_kg16
  use rrsw_kg16_mod
  implicit none

  call initialize()

  ! Example checks
  print *, "rayl =", rayl
  print *, "First element of absa:", absa(1,1)
  print *, "First element of absb:", absb(1,1)
end program test_rrsw_kg16