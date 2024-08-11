module m
  public :: a, set_values, print_values
  private :: b
  protected :: i
  integer :: a
  integer, allocatable :: j(:)

contains
  subroutine set_values()
    a = 5
    allocate(j(1))
    j(1) = 10
  end subroutine set_values
  
  subroutine print_values()
    print *, 'a = ', a
    if (allocated(j)) then
      print *, 'j(1) = ', j(1)
    endif
  end subroutine print_values
end module m

program test_m
  use m
  implicit none

  call set_values()
  call print_values()
end program test_m