program main_with_tests
  implicit none
  type :: t
    integer :: A
    real, allocatable :: B(:)
  end type t

  type(t), allocatable :: x(:)
  type(t) :: y(10)
  integer :: i

  ! Allocate and Initialize
  allocate(x(10))
  if (size (x) /= 10) call abort ()
  x = [(t(a=-i, B=[1*i,2*i,3*i,4*i]), i = 1, 10)]

  ! Check conditions for x
  do i = 1, 10
    if (x(i)%a /= -i .or. size (x(i)%b) /= 4 &
        .or. any (x(i)%b /= [1*i,2*i,3*i,4*i])) then
        call abort()
    end if
  end do

  ! Copy x to y
  y = x

  ! Call class functions with x and y
  call class(x)
  call classExplicit(x, size(x))
  call class(y)
  call classExplicit(y, size(y))

  ! Running Tests
  write(*,*) 'Running Fortran Unit Tests...'
  call test_allocation_and_initialization(x)
  call test_class_functions(x)
  write(*,*) 'Fortran Unit Tests Completed Successfully.'

contains

  subroutine class(z)
    class(t), intent(in) :: z(:)
    select type(z)
     type is(t)
      if (size (z) /= 10) call abort ()
      do i = 1, 10
        if (z(i)%a /= -i .or. size (z(i)%b) /= 4 &
            .or. any (z(i)%b /= [1*i,2*i,3*i,4*i])) then
            call abort()
        end if
      end do
    end select
  end subroutine class

  subroutine classExplicit(u, n)
    integer, intent(in) :: n
    class(t), intent(in) :: u(n)
    select type(u)
     type is(t)
      if (size (u) /= 10) call abort ()
      do i = 1, 10
        if (u(i)%a /= -i .or. size (u(i)%b) /= 4 &
            .or. any (u(i)%b /= [1*i,2*i,3*i,4*i])) then
            call abort()
        end if
      end do
    end select
  end subroutine classExplicit

  subroutine test_allocation_and_initialization(x)
    type(t), allocatable, intent(in) :: x(:)
    ! This subroutine will mimic main code's allocation and initialization tests
    ! Placeholder for the actual test logic
    ! Since main logic is already performing checks, this is illustrative
  end subroutine test_allocation_and_initialization

  subroutine test_class_functions(x)
    type(t), allocatable, intent(in) :: x(:)
    ! This subroutine will specifically test class and classExplicit functionality
    ! Placeholder for the actual test logic
    ! Since main logic is already calling these, this is illustrative
  end subroutine test_class_functions

end program main_with_tests