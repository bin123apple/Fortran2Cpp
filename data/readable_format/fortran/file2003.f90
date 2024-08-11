program foo
  implicit none
  integer, parameter :: n = 100
  integer, dimension(n,n) :: a
  integer :: i, j, sum = 0
  integer, parameter :: expected_sum = 10000

  a = 1

  do i=1, n
     do j=1, n
        sum = sum + a(i, j)
     end do
  end do

  if (sum == expected_sum) then
     print *, "Test Passed: Sum is correct."
  else
     print *, "Test Failed: Sum is incorrect."
  end if

end program foo