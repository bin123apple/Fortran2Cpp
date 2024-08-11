module types
  implicit none
  type :: t_type
    integer, dimension(:), allocatable :: chars
  end type t_type

  integer, save :: callnb = 0

contains
  recursive function recursivefunc(this) result(match)
    type(t_type), intent(in) :: this
    type(t_type) :: subpattern
    logical :: match

    callnb = callnb + 1
    match = (callnb == 10)
    if ((.NOT. allocated(this%chars)) .OR. match) return
    allocate(subpattern%chars(4))
    match = recursivefunc(subpattern)
  end function recursivefunc
end module types

program testprog
  use types
  implicit none
  type(t_type) :: this
  logical :: result

  allocate(this%chars(4))  ! Allocate memory for the chars array
  result = recursivefunc(this)  ! Call the recursive function to test its behavior

  ! Check if the recursive function behaves as expected
  if (.not. result .or. callnb /= 10) then
    print *, "Test failed: Incorrect result or callnb /= 10"
  else
    print *, "Test passed"
  end if
end program testprog