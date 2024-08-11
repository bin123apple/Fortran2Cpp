module userinterface
  implicit none
contains
  subroutine evalf(n, x, f, flag)
    integer, intent(in) :: n
    real(8), intent(in) :: x(n)
    real(8), intent(out) :: f
    integer, intent(out) :: flag
    f = sum(x)  ! Test implementation: sum of elements.
    flag = 0
  end subroutine evalf

  subroutine evalc(n, x, ind, c, flag)
    integer, intent(in) :: n, ind
    real(8), intent(in) :: x(n)
    real(8), intent(out) :: c
    integer, intent(out) :: flag
    c = x(ind)  ! Test implementation: return the value at index ind.
    flag = 0
  end subroutine evalc

  subroutine evaljac(n, x, ind, jcvar, jcval, jcnnz, flag)
    integer, intent(in) :: n, ind
    real(8), intent(in) :: x(n)
    integer, intent(out) :: jcvar(n), flag
    real(8), intent(out) :: jcval(n)
    integer, intent(out) :: jcnnz
    integer :: i
    jcnnz = n
    do i = 1, n
      jcvar(i) = i
      jcval(i) = x(i)
    end do
    flag = 0
  end subroutine evaljac
end module userinterface

program test_program
  use userinterface
  implicit none
  integer :: n, flag, ind, jcnnz
  real(8) :: f, c
  real(8), allocatable :: x(:)
  integer, allocatable :: jcvar(:)
  real(8), allocatable :: jcval(:)

  n = 5
  allocate(x(n))
  x = [1.0d0, 2.0d0, 3.0d0, 4.0d0, 5.0d0]

  ! Test evalf
  call evalf(n, x, f, flag)
  print *, "Test evalf - Sum:", f  ! Expected output: 15.0

  ! Test evalc
  ind = 3
  call evalc(n, x, ind, c, flag)
  print *, "Test evalc - Value at index 3:", c  ! Expected output: 3.0

  ! Test evaljac
  allocate(jcvar(n), jcval(n))
  call evaljac(n, x, ind, jcvar, jcval, jcnnz, flag)
  print *, "Test evaljac - jcval:", jcval  ! Expected output: 1.0, 2.0, 3.0, 4.0, 5.0

  deallocate(x, jcvar, jcval)
end program test_program