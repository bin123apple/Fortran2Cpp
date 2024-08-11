program main
  use, intrinsic :: iso_fortran_env, only: int32, real32
  implicit none

  ! Type definitions
  type :: t
    integer(int32) :: i
    real(real32) :: r
  end type t

  type, extends(t) :: t2
    integer(int32) :: j
  end type t2

  ! Variable declarations
  type(t) :: a
  type(t), dimension(1:3) :: b
  class(t), allocatable :: cp

  ! Main program execution starts here
  print *, "Running tests..."

  ! Allocate cp as t2 type
  allocate(t2 :: cp)

  ! Run tests
  call test_sizes

  ! Clean up
  if (allocated(cp)) deallocate(cp)

contains
  subroutine test_sizes
    ! Test the sizes of the defined types
    if (.not. test_sizeof(a, 8)) call abort()

    ! Directly calculate and check the size of array b
    if (sizeof(b) /= 24) then
      print *, "Size test failed for array b: Expected 24, Got:", sizeof(b)
      call abort()
    else
      print *, "Size test passed for array b."
    endif

    if (.not. test_sizeof(cp, 12)) call abort()

    print *, "All tests passed."
  end subroutine test_sizes

  function test_sizeof(var, expected_size) result(res)
    class(*), intent(in) :: var
    integer, intent(in) :: expected_size
    logical :: res

    res = (sizeof(var) == expected_size)
    if (.not. res) then
      print *, "Size test failed. Expected:", expected_size, "Got:", sizeof(var)
    else
      print *, "Size test passed."
    endif
  end function test_sizeof

end program main