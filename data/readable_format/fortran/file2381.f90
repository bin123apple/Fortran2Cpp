program test_mvbits
  implicit none
  integer :: a(2), b(2)
  integer :: x, y

  ! Test case 1
  a = 1
  b = 0
  x = 1
  y = 0

  call mvbits(a, 0, 1, b, 1)
  call mvbits(x, 0, 1, y, 1)

  if (any(b /= y)) then
    print *, "Test case 1 failed."
  else
    print *, "Test case 1 passed."
  end if

  ! Add more test cases as needed
end program test_mvbits