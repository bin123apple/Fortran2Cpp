! grid2deg_fixed.f90
subroutine grid2deg(grid0, dlong, dlat)
  implicit none
  character(len=*), intent(in) :: grid0
  double precision, intent(out) :: dlong, dlat
  character(len=6) :: grid
  integer :: i

  grid = grid0
  i = ichar(grid(5:5))
  if (grid(5:5) .eq. ' ' .or. i .le. 64 .or. i .ge. 128) grid(5:6) = 'mm'

  ! Convert to uppercase if lowercase
  if (grid(1:1) .ge. 'a' .and. grid(1:1) .le. 'z') grid(1:1) = char(ichar(grid(1:1)) + ichar('A') - ichar('a'))
  if (grid(2:2) .ge. 'a' .and. grid(2:2) .le. 'z') grid(2:2) = char(ichar(grid(2:2)) + ichar('A') - ichar('a'))

  ! Convert to lowercase if uppercase
  if (grid(5:5) .ge. 'A' .and. grid(5:5) .le. 'Z') grid(5:5) = char(ichar(grid(5:5)) - ichar('A') + ichar('a'))
  if (grid(6:6) .ge. 'A' .and. grid(6:6) .le. 'Z') grid(6:6) = char(ichar(grid(6:6)) - ichar('A') + ichar('a'))

  ! Perform calculations with line continuation
  dlong = 180 - 20 * (ichar(grid(1:1)) - ichar('A')) - 2 * (ichar(grid(3:3)) - ichar('0')) - &
          5 * (ichar(grid(5:5)) - ichar('a') + 0.5) / 60.0
  dlat = -90 + 10 * (ichar(grid(2:2)) - ichar('A')) + (ichar(grid(4:4)) - ichar('0')) + &
          2.5 * (ichar(grid(6:6)) - ichar('a') + 0.5) / 60.0
end subroutine grid2deg

! Unit Test for Fortran
program testGrid2DegFortran
  use iso_fortran_env, only: real64
  implicit none
  character(len=6) :: testGrid
  real(real64) :: dlong, dlat

  ! Test 1
  testGrid = 'A1B2C3'
  call grid2deg(testGrid, dlong, dlat)
  print *, 'Fortran: Test 1: Grid=A1B2C3, Longitude=', dlong, ', Latitude=', dlat
end program testGrid2DegFortran