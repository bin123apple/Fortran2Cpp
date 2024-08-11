module probleme_mod
  implicit none
contains

subroutine probleme(p)
  real(kind=8), dimension(:), intent(in) :: p
  integer :: nx
  integer :: nix

  nx = size(p, 1)
  nix = nx

  ! For testing purposes, print the values
  print *, "nx =", nx
  print *, "nix =", nix
end subroutine probleme

end module probleme_mod

program test
  use probleme_mod
  implicit none
  real(kind=8), dimension(3) :: p = [1.0d0, 2.0d0, 3.0d0]

  call probleme(p)
end program test