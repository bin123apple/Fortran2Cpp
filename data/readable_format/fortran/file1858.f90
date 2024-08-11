module rrlw_kg04
  implicit none
  save

  integer(kind=4), parameter :: no4 = 16, ng4 = 14
  real(kind=8) :: fracrefao(no4,9), fracrefbo(no4,5)
  real(kind=8) :: kao(9,5,13,no4)
  real(kind=8) :: kbo(5,5,47,no4) ! Adjusted for 13:59 range
  real(kind=8) :: selfrefo(10,no4), forrefo(4,no4)

  real(kind=8) :: fracrefa(ng4,9), fracrefb(ng4,5)
  real(kind=8) :: ka(9,5,13,ng4)
  real(kind=8) :: kb(5,5,47,ng4) ! Adjusted for 13:59 range
  real(kind=8) :: absa(585,ng4)
  real(kind=8) :: absb(1175,ng4)
  real(kind=8) :: selfref(10,ng4), forref(4,ng4)

  equivalence (ka(1,1,1,1), absa(1,1)), (kb(1,1,13,1), absb(1,1))
end module rrlw_kg04

program test_rrlw_kg04
  use rrlw_kg04
  implicit none

  ! Initialize some values
  fracrefao(1,1) = 1.0
  fracrefbo(1,1) = 2.0
  kao(1,1,1,1) = 3.0
  kbo(1,1,13,1) = 4.0
  selfrefo(1,1) = 5.0
  forrefo(1,1) = 6.0

  fracrefa(1,1) = 7.0
  fracrefb(1,1) = 8.0
  ka(1,1,1,1) = 9.0
  absa(1,1) = 10.0
  kb(1,1,13,1) = 11.0
  absb(1,1) = 12.0
  selfref(1,1) = 13.0
  forref(1,1) = 14.0

  print *, 'Fortran test results:'
  print *, 'fracrefao(1,1) =', fracrefao(1,1)
  print *, 'fracrefbo(1,1) =', fracrefbo(1,1)
  print *, 'kao(1,1,1,1) =', kao(1,1,1,1)
  print *, 'kbo(1,1,13,1) =', kbo(1,1,13,1)
  print *, 'selfrefo(1,1) =', selfrefo(1,1)
  print *, 'forrefo(1,1) =', forrefo(1,1)
  print *, 'fracrefa(1,1) =', fracrefa(1,1)
  print *, 'fracrefb(1,1) =', fracrefb(1,1)
  print *, 'ka(1,1,1,1) =', ka(1,1,1,1)
  print *, 'absa(1,1) =', absa(1,1)
  print *, 'kb(1,1,13,1) =', kb(1,1,13,1)
  print *, 'absb(1,1) =', absb(1,1)
  print *, 'selfref(1,1) =', selfref(1,1)
  print *, 'forref(1,1) =', forref(1,1)
end program test_rrlw_kg04