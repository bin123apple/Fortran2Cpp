module array
  implicit none

  type :: t_array
    real, dimension(10) :: coeff
  contains
    procedure :: get_coeff => get_array_coeff
  end type t_array

contains

  function get_array_coeff(self) result(coeff)
    class(t_array), intent(in) :: self
    real, dimension(size(self%coeff)) :: coeff

    coeff = self%coeff
  end function get_array_coeff

end module array

program test_array
  use array
  implicit none

  type(t_array) :: arr
  real :: testCoeffs(10)
  integer :: i

  ! Initialize test coefficients
  do i = 1, 10
     arr%coeff(i) = i * 1.0
  end do

  ! Test getting coefficients
  testCoeffs = arr%coeff
  do i = 1, 10
     if (testCoeffs(i) /= i * 1.0) then
        print *, "Test failed for coefficient at index", i
     else
        print *, "Test passed for coefficient at index", i, "Value:", testCoeffs(i)
     end if
  end do

end program test_array