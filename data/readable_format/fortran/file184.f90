module foo
  implicit none
contains
  subroutine bar(a,x)
    real, dimension(:,:), intent(in) :: a
    real, intent(out) :: x
    integer :: i,j

    x = 0
    do j=1,ubound(a,2)
       do i=1,ubound(a,1)
          x = x + a(i,j)**2
       end do
    end do
  end subroutine bar
end module foo

! Adding a test subroutine
subroutine test_bar()
  use foo
  implicit none
  real, dimension(2,3) :: a = reshape((/1.0, 2.0, 3.0, -1.0, -2.0, -3.0/), shape(a))
  real :: x
  real :: expected = 28.0

  call bar(a,x)
  if (abs(x - expected) < 0.0001) then
    print *, "Test passed."
  else
    print *, "Test failed. Expected:", expected, "Got:", x
  endif
end subroutine test_bar

program main
  call test_bar()
end program main