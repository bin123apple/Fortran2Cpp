program test_unit
  implicit none

  logical :: l
  logical :: l1
  logical :: l2
  logical :: l4
  logical :: l8

  type :: a_struct
     logical :: a1
     logical :: a2
  end type a_struct

  type(a_struct) :: s1

  s1%a1 = .TRUE.
  s1%a2 = .FALSE.

  l1 = .TRUE.
  l2 = .TRUE.
  l4 = .TRUE.
  l8 = .TRUE.

  l = .FALSE.

  ! Unit tests
  call assert(s1%a1 .eqv. .TRUE., "s1%a1 should be .TRUE.")
  call assert(s1%a2 .eqv. .FALSE., "s1%a2 should be .FALSE.")
  call assert(l1 .eqv. .TRUE., "l1 should be .TRUE.")
  call assert(l2 .eqv. .TRUE., "l2 should be .TRUE.")
  call assert(l4 .eqv. .TRUE., "l4 should be .TRUE.")
  call assert(l8 .eqv. .TRUE., "l8 should be .TRUE.")
  call assert(l .eqv. .FALSE., "l should be .FALSE.")

contains
  subroutine assert(cond, message)
    logical, intent(in) :: cond
    character(len=*), intent(in) :: message
    if (.not. cond) then
      print *, "Assertion failed: ", message
      stop 1
    else
      print *, "Assertion passed: ", message
    endif
  end subroutine assert
end program test_unit