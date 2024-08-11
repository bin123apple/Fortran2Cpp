module sizes
  implicit none
  private

  integer, parameter, public :: Ndim=3
  integer, dimension(Ndim), parameter, public :: mesh=(/ 100, 100, 100 /)
  integer, parameter, public :: meshx=mesh(1)
  integer, parameter, public :: meshy=mesh(2)
  integer, parameter, public :: meshz=mesh(3)
end module sizes

program test_sizes
  use sizes
  implicit none

  logical :: test_passed

  ! Test Ndim
  test_passed = (Ndim == 3)
  if (test_passed) then
      print *, "Ndim test passed"
  else
      print *, "Ndim test failed"
  end if

  ! Test mesh array and individual meshx, meshy, meshz
  test_passed = all(mesh == [100, 100, 100]) .and. &
                meshx == 100 .and. meshy == 100 .and. meshz == 100
  if (test_passed) then
      print *, "Mesh size tests passed"
  else
      print *, "Mesh size tests failed"
  end if
end program test_sizes