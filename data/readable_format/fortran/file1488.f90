module mymod
  implicit none
  type :: a
    real, allocatable :: x(:)
  end type a

  type, extends(a) :: f
    integer :: if
  end type f

  type :: b
    real, allocatable :: x(:)
    integer :: i
  end type b

  type, extends(b) :: d
    integer :: id
  end type d

contains
  function set_b() result(res)
    type(b) :: res
    allocate(res%x(2))
    res%x = [10.0, 20.0]
    res%i = 1
  end function set_b

  subroutine check_b(arg)
    type(b), intent(in) :: arg
    if (any(arg%x /= [10.0, 20.0])) stop "check_b failed on x"
    if (arg%i /= 1) stop "check_b failed on i"
  end subroutine check_b

  subroutine test_my_module()
    type(f) :: p
    type(d) :: q

    ! Test for type f
    allocate(p%x(2))
    p%x = [1.0, 2.0]
    p%if = 3
    if (any(p%x /= [1.0, 2.0])) stop "Test for type f failed on x"
    if (p%if /= 3) stop "Test for type f failed on if"

    ! Test for type d using set_b and check_b
    q%b = set_b()
    call check_b(q%b)
    q = d(set_b(), id = 99)
    call check_b(q%b)
    if (q%id /= 99) stop "Test for type d failed on id"

    print *, "All Fortran tests passed successfully."
  end subroutine test_my_module
end module mymod

program test
  use mymod
  call test_my_module()
end program test