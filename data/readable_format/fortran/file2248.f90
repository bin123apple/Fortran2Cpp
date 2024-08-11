module dlanst_mod
  implicit none
contains
  function dlanst(norm, n, d, e) result(norm_value)
    character(len=1), intent(in) :: norm
    integer(kind=4), intent(in) :: n
    real(kind=8), intent(in) :: d(*)
    real(kind=8), intent(in) :: e(*)
    real(kind=8) :: norm_value
    real(kind=8) :: sum_squares
    integer :: i

    sum_squares = 0.0
    do i = 1, n
      sum_squares = sum_squares + d(i)**2
    end do
    do i = 1, n-1
      sum_squares = sum_squares + e(i)**2
    end do
    norm_value = sqrt(sum_squares)
  end function dlanst
end module dlanst_mod

program test_dlanst
  use dlanst_mod
  implicit none
  real(kind=8), dimension(3) :: d = [1.0, 2.0, 3.0]
  real(kind=8), dimension(2) :: e = [0.5, 1.5]
  real(kind=8) :: result
  character(len=1) :: norm
  integer(kind=4) :: n

  norm = 'F'  ! Frobenius norm
  n = 3
  result = dlanst(norm, n, d, e)
  print *, "Fortran Result: ", result
end program test_dlanst