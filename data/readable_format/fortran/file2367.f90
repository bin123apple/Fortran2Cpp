module tao_random_numbers
  integer, dimension(10) :: s_buffer
  integer :: s_last = size(s_buffer)
end module tao_random_numbers

module linalg
  contains
  function diag(a) result(d)
    real, dimension(:,:), intent(in) :: a
    real, dimension(min(size(a,dim=1),size(a,dim=2))) :: d
    integer :: i
    do i = 1, min(size(a, dim = 1), size(a, dim = 2))
       d(i) = a(i,i)
    end do
  end function diag
end module linalg

! This module was originally intended for further use, but since we're consolidating,
! it's commented out. You can still define procedures or variables here if needed.
!module vamp_rest
!  use tao_random_numbers
!  use linalg
!end module vamp_rest

program test_program
  use tao_random_numbers
  use linalg
  implicit none
  
  real :: x(2, 2) = reshape([1.,2.,3.,4.], [2,2])
  real, dimension(2) :: diag_x

  print *, 's_last:', s_last
  diag_x = diag(x)
  print *, 'Diagonal elements of x:', diag_x
end program test_program