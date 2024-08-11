program test_great_rsd
  implicit none

  ! Declare variables for testing
  integer :: a, b

  ! Test 1
  a = 1; b = 2
  call great_rsd(a, b)

  ! Test 2
  a = -1; b = -2
  call great_rsd(a, b)

  ! Test 3
  a = 100; b = 200
  call great_rsd(a, b)

contains

  subroutine great_rsd(x, y)
    implicit none
    integer, intent(in) :: x, y
    print *, 'Sum of ', x, ' and ', y, ' is ', x + y
  end subroutine great_rsd

end program test_great_rsd