module class_t
  implicit none
  type :: tx
    integer :: i
  end type tx
  
  type :: t
    type(tx) :: x
    procedure(find_x), pointer :: ppc
  contains
    procedure :: find_x
  end type t
  
  type(tx), target :: zero = tx(0)
  
contains
  function find_x(this) result(res)
    class(t), intent(in) :: this
    type(tx), pointer :: res
    res => zero
  end function find_x
end module class_t

program test
  use class_t
  implicit none
  class(t), allocatable :: this
  procedure(find_x), pointer :: pp
  
  ! Test setup
  allocate(this)
  zero = tx(1)
  this%x = find_x(this)
  if (this%x%i /= 1) call abort()
  
  zero = tx(2)
  pp => find_x
  this%x = pp(this)
  if (this%x%i /= 2) call abort()
  
  zero = tx(3)
  this%ppc => find_x
  this%x = this%ppc()
  if (this%x%i /= 3) call abort()
  
  zero = tx(4)
  this%x = this%find_x()
  if (this%x%i /= 4) call abort()
  
  print *, "All tests passed successfully."
  
end program test