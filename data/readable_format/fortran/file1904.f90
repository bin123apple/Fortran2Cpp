program test
  implicit none
  integer :: a(3,3)
  integer :: i, j

  ! Initialize array 'a'
  do i = 1, 3
     do j = 1, 3
        a(i,j) = i + j
     end do
  end do

  ! Pass the first row of 'a' to 'foo'
  call foo(a(1,:))

contains

  subroutine foo(x)
    integer, intent(in) :: x(3)
    integer :: sum, i
    sum = 0
    do i = 1, 3
       sum = sum + x(i)
    end do
    print *, "Sum of array slice in Fortran: ", sum
  end subroutine foo
end program test