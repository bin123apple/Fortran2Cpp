module rrsw_kg18
  implicit none
  real, parameter :: pi = 3.14159
  real, dimension(1:5) :: array1
  real, dimension(3) :: array2
contains
  subroutine computeSomething()
    array1(1) = pi
    array2(3) = 2.0 * pi
    ! More code here
  end subroutine computeSomething
end module rrsw_kg18

program test_rrsw_kg18
  use rrsw_kg18
  implicit none

  call computeSomething()

  if (array1(1) /= pi) then
    print *, 'Test failed: array1(1) is not pi'
  elseif (array2(3) /= 2*pi) then
    print *, 'Test failed: array2(3) is not 2*pi'
  else
    print *, 'Test successful: array1(1) and array2(3) check passed.'
  end if
end program test_rrsw_kg18