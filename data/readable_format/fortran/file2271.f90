module foo_mod
contains
  subroutine foo(a, i)
    integer, intent(inout), dimension(4,4) :: a
    integer, intent(in) :: i

    where (a(i+1,1:3) .ne. 0)
      a(i+2,2:4) = 1
    end where
  end subroutine foo
end module foo_mod

program test_foo
  use foo_mod
  implicit none
  integer, dimension(4,4) :: a
  integer :: i

  a = 0
  i = 0
  a(2,1) = 1  ! Set condition for where

  call foo(a, i)

  ! Print the modified array to verify the result
  print *, "Modified array a:"
  do i = 1, 4
    print '(*(i0,1x))', a(i, :)
  end do
end program test_foo