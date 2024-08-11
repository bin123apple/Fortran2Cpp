module mod_a
  implicit none

  type :: t_1
    real :: coeff = 99.0
  end type t_1

  type :: t_2
    type(t_1), allocatable :: mons(:)
  end type t_2

contains

  function a_fun(r) result(p)
    integer, intent(in) :: r
    type(t_2), allocatable :: p(:)
    integer :: i

    allocate(p(r+1)) ! Allocate p with size r+1
    do i = 1, size(p)
      allocate(p(i)%mons(1)) ! Allocate mons with size 1 for each t_2
      p(i)%mons(1) = t_1(99.0) ! Assign t_1(99) to mons
    end do
  end function a_fun

end module mod_a

program test_mod_a
  use mod_a
  implicit none

  integer :: i, r
  type(t_2), allocatable :: x(:)

  ! Test for a_fun with input 0
  x = a_fun(0)
  if (size(x(1)%mons) /= 1 .or. x(1)%mons(1)%coeff /= 99) then
    print *, "Test failed for a_fun with input 0."
  else
    print *, "Test passed for a_fun with input 0."
  end if

  ! Test for a_fun with input 1
  r = 1
  x = a_fun(r)
  do i = 1, size(x)
    if (size(x(i)%mons) /= 1 .or. x(i)%mons(1)%coeff /= 99) then
      print *, "Test failed for a_fun with input 1."
      exit
    end if
  end do
  print *, "Test passed for a_fun with input 1."

end program test_mod_a