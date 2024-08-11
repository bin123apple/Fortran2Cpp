program test_init
  implicit none
  integer, target :: tgt
  type A
    integer, pointer :: p => null()
    integer :: i = 3
  end type A
  type(A) :: x, y(3)

  x = f()
  if (.not. associated(x%p) .and. x%i == 3) then
     print *, "Main test for f passed."
  else
     print *, "Main test for f failed."
  end if

  call test_f()
  call test_sub1()
  call test_sub2()

contains

  function f() result(fr)
    type(A) :: fr
  end function f

  subroutine sub1(n, x)
    integer, intent(in) :: n
    type(A), intent(inout) :: x(n)
    integer :: j
    do j = 1, n
       nullify(x(j)%p)
       x(j)%i = 3
    end do
  end subroutine sub1

  subroutine sub2(x)
    type(A), intent(inout) :: x(:)
    integer :: j
    do j = 1, size(x)
       nullify(x(j)%p)
       x(j)%i = 3
    end do
  end subroutine sub2

  subroutine test_f()
    type(A) :: result
    result = f()
    if (.not. associated(result%p) .and. result%i == 3) then
      print *, "test_f passed."
    else
      print *, "test_f failed."
    endif
  end subroutine test_f

  subroutine test_sub1()
    type(A), target :: arr(3)
    integer, target :: tgt
    arr(1)%p => tgt
    call sub1(3, arr)
    if (.not. associated(arr(1)%p) .and. all(arr(:)%i == 3)) then
      print *, "test_sub1 passed."
    else
      print *, "test_sub1 failed."
    endif
  end subroutine test_sub1

  subroutine test_sub2()
    type(A), target :: arr(3)
    integer, target :: tgt
    arr(1)%p => tgt
    call sub2(arr)
    if (.not. associated(arr(1)%p) .and. all(arr(:)%i == 3)) then
      print *, "test_sub2 passed."
    else
      print *, "test_sub2 failed."
    endif
  end subroutine test_sub2

end program test_init