! test.f90
subroutine test
  implicit none
  real, pointer :: p(:), q
  common /block/ p, q

  if (any(p .ne. (/1.0, 2.0/)) .or. (q .ne. 42.0)) call abort()
end subroutine

program common_pointer_1_test
  implicit none
  real, target :: a(2), b
  real, pointer :: x(:), y
  common /block/ x, y
  
  ! Test case 1: Expected to pass
  a = (/1.0, 2.0/)
  b = 42.0
  x => a
  y => b
  call test
  print *, 'Test case 1 passed.'

  ! Test case 2: Expected to fail and call abort
  ! Uncomment the following lines to test the failure scenario
  !a = (/3.0, 4.0/)
  !b = 24.0
  !x => a
  !y => b
  !call test
  !print *, 'Test case 2 passed.'
end program