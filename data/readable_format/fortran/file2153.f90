module x
  implicit none
contains
  subroutine bar(a, n)
    integer, intent(in) :: n
    integer, intent(in), dimension(n) :: a
    print *,a
  end subroutine bar
end module x

program main
  use x
  implicit none
  integer, parameter :: n = 10
  integer, dimension(n) :: a
  integer :: i
  a = [(i,i=1,n)]
  call bar(a(n:1:-1),n)
end program main