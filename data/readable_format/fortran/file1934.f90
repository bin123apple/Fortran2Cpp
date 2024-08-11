program test_equivalence_and_save
  implicit none

  ! Variables declaration
  real :: a, b, c, d
  integer :: e, f
  real, save :: saved_d = 0.0  ! Using manual save
  integer, save :: saved_e = 0 ! Using manual save

  ! First call to emulate subroutine behavior
  a = 1.0
  d = 2.0
  e = 3

  ! Manual "equivalence" by direct assignment
  b = a
  c = b
  d = c
  saved_d = d  ! Save 'd' manually
  f = e
  saved_e = e  ! Save 'e' manually

  print *, "After first call:"
  print *, "a, b, c, d:", a, b, c, d
  print *, "e, f:", e, f

  ! Second call to test save effect
  a = 4.0
  e = 5

  ! Manual "equivalence" by direct assignment
  b = a
  c = b
  d = saved_d  ! Retrieve 'd' from saved value
  f = saved_e   ! Retrieve 'e' from saved value

  print *, "After second call (testing save):"
  print *, "a, b, c, d:", a, b, c, d
  print *, "e, f:", e, f

end program test_equivalence_and_save