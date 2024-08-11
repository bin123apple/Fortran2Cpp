program test
  implicit none
  integer :: a(10), b(0), c(1)
  integer :: i

  call test_sub(a, 10)
  call test_sub(b, 0)  ! Edge case: Testing with an empty array
  call test_sub(c, 1)  ! Testing with a single-element array

  stop
end program test

subroutine test_sub(a, n)
  implicit none
  integer, intent(in) :: n
  integer, dimension(n) :: a
  integer :: i
  
  call sub(a, n)
  if (n > 0) then
     write(*,*) 'Array after sub call:'
     do i = 1, n
        write(*,*) a(i)
     end do
  else
     write(*,*) 'Empty array test case.'
  endif
end subroutine test_sub

subroutine sub(a, n)
  implicit none
  integer, intent(in) :: n
  integer, dimension(n) :: a
  integer :: i

  do i = 1, n
    a(i) = i
  end do
end subroutine sub