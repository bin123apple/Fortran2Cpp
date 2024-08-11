program testSameTypeAs
  implicit none

  type :: t1
    integer :: i
  end type t1

  type, extends(t1) :: t2
    integer :: j
  end type t2

  class(t1), pointer :: c1, c2
  type(t1), target :: x1
  type(t2), target :: x2

  logical :: l

  ! Initialize pointers to NULL
  c1 => null()
  
  ! Test SAME_TYPE_AS intrinsic
  l = same_type_as(x1, x1)
  call my_assert(l)
  
  l = same_type_as(x1, x2)
  call my_assert(.not. l)
  
  c1 => x1
  l = same_type_as(c1, x1)
  call my_assert(l)
  
  l = same_type_as(c1, x2)
  call my_assert(.not. l)
  
  c1 => x2
  c2 => x2
  l = same_type_as(c1, c2)
  call my_assert(l)
  
  c1 => x1
  c2 => x2
  l = same_type_as(c1, c2)
  call my_assert(.not. l)
  
contains

  subroutine my_assert(condition)
    logical, intent(in) :: condition
    if (.not. condition) then
      print *, "Assertion failed!"
      stop
    end if
  end subroutine my_assert

end program testSameTypeAs