module m_phys_constants

  implicit none

  integer, parameter :: kint = selected_int_kind(15)

  integer(kind=kint), parameter :: n_scalar = 1
  integer(kind=kint), parameter :: n_vector = 3
  integer(kind=kint), parameter :: n_sym_tensor = 6
  integer(kind=kint), parameter :: n_asym_tensor = 3
  integer(kind=kint), parameter :: n_solenoid = 2

  integer(kind=kint), parameter :: l_sim_t(3,3) = reshape( &
       (/0, 1, 2, 1, 3, 4, 2, 4, 5/), shape=(/3,3/))

  integer(kind=kint), parameter :: l_asim_t(3,3,2) = reshape( &
       (/0, 0, 2, 0, 0, 1, 2, 1, 0, 0, 1, -1, -1, 0, 1, 1, -1, 0/), &
       shape=(/3,3,2/))

  integer(kind=kint), parameter :: lst_sim_t(3) = (/0, 3, 5/)

end module m_phys_constants

program test_phys_constants
  use m_phys_constants
  implicit none

  print *, "n_scalar =", n_scalar
  print *, "n_vector =", n_vector
  print *, "n_sym_tensor =", n_sym_tensor
  print *, "n_asym_tensor =", n_asym_tensor
  print *, "n_solenoid =", n_solenoid

  print *, "l_sim_t(1,1) =", l_sim_t(1,1)
  print *, "l_sim_t(3,3) =", l_sim_t(3,3)

  print *, "l_asim_t(1,3,2) =", l_asim_t(1,3,2)
  print *, "l_asim_t(3,3,2) =", l_asim_t(3,3,2)

  print *, "lst_sim_t(1) =", lst_sim_t(1)
  print *, "lst_sim_t(3) =", lst_sim_t(3)

end program test_phys_constants