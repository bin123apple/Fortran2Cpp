program main
  implicit none
  integer, parameter :: n = 2
  integer, target, dimension(0:n-1) :: a
  integer, pointer :: ptr(:)
  ptr => a

  a(0) = 0
  ptr(0) = 1

  ! Test
  if (a(0) == 1) then
    print *, "Test Passed."
  else
    print *, "Test Failed."
  end if
end program main