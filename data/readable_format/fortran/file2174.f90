! Define a module for the common blocks and subroutine
module common_blocks
  implicit none
  character(len=15) :: c
  integer :: d, e
  real :: f
end module common_blocks

! Define the subroutine that uses the common blocks
subroutine test()
  use common_blocks
  if ((d .ne. 42) .or. (e .ne. 43) .or. (f .ne. 2.0)) then
    print *, "Test failed due to incorrect values in /block/"
    stop
  endif
  if (c .ne. "Hello World    ") then
    print *, "Test failed due to incorrect value in /block2/"
    stop
  endif
  print *, "All tests passed."
end subroutine test

! Main program to initialize common blocks and call the test
program main
  use common_blocks
  integer :: a(2)
  real :: b
  character(len=15) :: s

  ! Initialize the variables
  a = (/42, 43/)
  b = 2.0
  s = "Hello World    " ! Ensure the string is padded to match the expected length

  ! Assign values from local variables to common block variables
  d = a(1)
  e = a(2)
  f = b
  c = s

  ! Call the test subroutine
  call test()
end program main