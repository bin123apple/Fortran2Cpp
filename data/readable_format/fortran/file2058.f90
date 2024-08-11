program p_016_test
  use, intrinsic :: iso_fortran_env
  implicit none
  integer :: d(400), c, a, i, j, n
  integer :: expected_sum
  expected_sum = 1366  ! Known result for the sum of digits of 2**1000
  d(:) = 0
  d(1) = 1
  c = 0
  n = 2
  do j = 1, 1000
     do i = 1, n
        d(i) = d(i) * 2 + c
        c = 0
        if (d(i) >= 10) then
           d(i) = d(i) - 10
           c = 1
        end if
     end do
     if (d(n) /= 0) n = n + 1
  end do
  a = 0
  do i = 1, n - 1
     a = a + d(i)
  end do
  if (a == expected_sum) then
     write(output_unit, '("Test Passed: Solution equals ",g0)') a
  else
     write(output_unit, '("Test Failed: Solution ",g0," does not equal expected ",g0)') a, expected_sum
  end if
end program p_016_test