module foo_mod
  type foo_inner
    integer, allocatable :: v(:)
  end type foo_inner
  type foo_outer
    class(foo_inner), allocatable :: int
  end type foo_outer
contains
  subroutine foo_checkit()
    implicit none
    type(foo_outer) :: try
    type(foo_outer), allocatable :: try2
    class(foo_outer), allocatable :: try3
    
    if (allocated(try%int)) call abort()
    allocate(foo_outer :: try3)
    if (allocated(try3%int)) call abort()
    allocate(try2)
    if (allocated(try2%int)) call abort()
  end subroutine foo_checkit
end module foo_mod

program main
  use foo_mod
  implicit none
  
  call foo_checkit()
  print *, "Test passed: foo_checkit did not abort the program."
end program main