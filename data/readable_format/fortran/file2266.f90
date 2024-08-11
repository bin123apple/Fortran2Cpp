module typemodule
  implicit none
  private
  public :: alltype, assignment(=), operator(-)

  type :: alltype
     double precision :: a
     double precision, allocatable :: b(:)
  end type alltype

  interface assignment(=)
    module procedure at_from_at
  end interface

  interface operator(-)
    module procedure neg_at
  end interface

contains

  subroutine at_from_at(b, a)
    type(alltype), intent(in) :: a
    type(alltype), intent(out) :: b
    b%a = a%a
    if (allocated(a%b)) then
      allocate(b%b(size(a%b)))
      b%b = a%b
    endif
  end subroutine at_from_at

  function neg_at(a) result(b)
    type(alltype), intent(in) :: a
    type(alltype) :: b
    b%a = -a%a
    if (allocated(a%b)) then
      allocate(b%b(size(a%b)))
      b%b = -a%b
    endif
  end function neg_at

end module typemodule

program main
  use typemodule
  implicit none
  type(alltype) :: t1, t2, t3

  ! Initialize t1
  allocate(t1%b(2))
  t1%a = 0.5d0
  t1%b(1) = 1d0
  t1%b(2) = 2d0

  ! Apply unary minus operator
  t2 = -t1

  ! Check results
  if (t2%a /= -0.5d0) stop 'Error in t2%a'
  if (any(t2%b /= [-1d0, -2d0])) stop 'Error in t2%b'

  ! Apply unary minus operator again and check
  t1 = -t1
  if (t1%a /= -0.5d0) stop 'Error in t1%a'
  if (any(t1%b /= [-1d0, -2d0])) stop 'Error in t1%b'

  print *, 'All tests passed successfully!'

end program main