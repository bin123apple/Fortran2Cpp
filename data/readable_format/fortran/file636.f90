module minimax_module
contains
  subroutine minimax(x, xmin, xmax, numpts)
    double precision, dimension(:), intent(in) :: x
    double precision, intent(out) :: xmin, xmax
    integer, intent(in) :: numpts
    integer :: i

    xmax = x(1)
    xmin = xmax
    do i = 1, numpts
      if (x(i) < xmin) xmin = x(i)
      if (x(i) > xmax) xmax = x(i)
    end do
  end subroutine minimax
end module minimax_module

program testMinimax
  use minimax_module
  implicit none

  double precision :: xmin, xmax
  double precision, dimension(5) :: testArray1 = (/1.0, 2.5, 3.0, 4.5, 5.0/)
  double precision, dimension(5) :: testArray2 = (/-3.0, -1.5, -4.5, -2.0, -5.5/)
  double precision, dimension(5) :: testArray3 = (/2.5, -1.0, 3.0, -4.5, 0.0/)
  double precision, dimension(1) :: testArray4 = (/2.0/)

  call minimax(testArray1, xmin, xmax, 5)
  print *, 'Test 1: Positive numbers. Min:', xmin, ' Max:', xmax

  call minimax(testArray2, xmin, xmax, 5)
  print *, 'Test 2: Negative numbers. Min:', xmin, ' Max:', xmax

  call minimax(testArray3, xmin, xmax, 5)
  print *, 'Test 3: Mixed numbers. Min:', xmin, ' Max:', xmax

  call minimax(testArray4, xmin, xmax, 1)
  print *, 'Test 4: Single element. Min:', xmin, ' Max:', xmax

end program testMinimax