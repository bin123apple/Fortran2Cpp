program test
  implicit none
  real, dimension(3) :: vector3d
  real, dimension(3,3) :: matrix3d
  integer :: i, j
  logical :: test_passed

  ! Initialize data
  vector3d(1) = 1.0
  vector3d(2) = 2.0
  vector3d(3) = 3.0
  matrix3d = 1.0

  ! Test vector3d
  test_passed = .TRUE.
  do i = 1, 3
     if (vector3d(i) /= real(i)) then
        test_passed = .FALSE.
        exit
     endif
  end do

  if (test_passed) then
     print *, "Vector test passed."
  else
     print *, "Vector test failed."
  endif

  ! Test matrix3d
  test_passed = .TRUE.
  do i = 1, 3
     do j = 1, 3
        if (matrix3d(i, j) /= 1.0) then
           test_passed = .FALSE.
           exit
        endif
     end do
     if (.NOT. test_passed) exit
  end do

  if (test_passed) then
     print *, "Matrix test passed."
  else
     print *, "Matrix test failed."
  endif
end program test