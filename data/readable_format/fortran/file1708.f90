module nonF03ComBlock
  implicit none
  real :: r
  real :: s

contains

  subroutine hello(myArray)
    implicit none
    integer, dimension(:), intent(in) :: myArray
    r = 1.0
    s = 2.0
  end subroutine hello

end module nonF03ComBlock

program testComBlock
  use nonF03ComBlock
  implicit none
  integer, dimension(1:10) :: myArray
  integer :: i

  ! Initialize the array to some values
  do i = 1, 10
     myArray(i) = i
  end do

  call hello(myArray)

  ! Test if r and s are set correctly
  if (r == 1.0 .and. s == 2.0) then
     print *, 'Test passed: r and s are correctly set.'
  else
     print *, 'Test failed: r and s are not correctly set.'
     call abort()
  endif
end program testComBlock