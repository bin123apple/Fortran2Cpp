module permanent_arrays
  implicit none
  ! Use a predefined parameter for double precision if needed or define your own
  integer, parameter :: double = selected_real_kind(15, 307)
  ! Declare your arrays here
  integer, dimension (:), allocatable :: labels
  real(double), dimension (:), allocatable :: xparam
  character(len=4), dimension (:), allocatable :: simbol
end module permanent_arrays

program test_permanent_arrays
  use permanent_arrays
  implicit none

  ! Allocate arrays
  allocate(labels(5))
  allocate(xparam(5))
  allocate(simbol(2))

  ! Assign some values
  labels = (/1, 2, 3, 4, 5/)
  xparam = (/1.0_double, 2.0_double, 3.0_double, 4.0_double, 5.0_double/)
  simbol(1) = "H"
  simbol(2) = "He"

  ! Print values to verify
  print *, "Labels: ", labels
  print *, "XParam: ", xparam
  print *, "Simbol: ", simbol

  ! Clean up
  deallocate(labels)
  deallocate(xparam)
  deallocate(simbol)
end program test_permanent_arrays