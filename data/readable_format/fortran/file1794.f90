module m
  implicit none
  private
  public :: u, test_u

  type s
    integer, dimension(3) :: n
  end type s

  type t
    type(s), pointer :: m
  end type t

  integer, dimension(3) :: a

contains

  subroutine u()
    type(t) :: b
    allocate(b%m) ! Allocate the pointer before use
    b%m%n = 1
    a = 2
    a = a + b%m%n + (/1,2,3/)
  end subroutine u

  subroutine test_u()
    call u()
    print *, "Testing Fortran implementation:"
    print *, "Array a:", a
  end subroutine test_u

end module m

program test
  use m
  call test_u()
end program test