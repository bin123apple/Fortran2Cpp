module rrsw_kg22
  implicit none
  save

  ! Assuming kind parameters are defined
  integer, parameter :: kind_rb = selected_real_kind(p=15)
  integer, parameter :: no22 = 16
  integer, parameter :: ng22 = 16

  real(kind=kind_rb) :: kao(9,5,13,no22)
  real(kind=kind_rb) :: kbo(5,13:59,no22)
  real(kind=kind_rb) :: selfrefo(10,no22), forrefo(3,no22)
  real(kind=kind_rb) :: sfluxrefo(no22,9)

  real(kind=kind_rb) :: rayl

  real(kind=kind_rb) :: ka(9,5,13,ng22), absa(585,ng22)
  real(kind=kind_rb) :: kb(5,13:59,ng22), absb(235,ng22)
  real(kind=kind_rb) :: selfref(10,ng22), forref(3,ng22)
  real(kind=kind_rb) :: sfluxref(ng22,9)

  equivalence (ka, absa), (kb, absb)

contains

  subroutine test_equivalence
    ! A simple subroutine to demonstrate testing or using the module
    print *, 'Testing equivalence within rrsw_kg22 module'
    ka(1,1,1,1) = 123.456
    print *, 'If equivalence works, this should print 123.456:', absa(1,1)
  end subroutine test_equivalence

end module rrsw_kg22

program main
  use rrsw_kg22
  implicit none

  ! Call the test subroutine
  call test_equivalence

end program main