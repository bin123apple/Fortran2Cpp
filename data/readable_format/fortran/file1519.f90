program pr71014_test
  implicit none
  integer :: i, j
  integer, parameter :: t = 100*101/2
  integer :: s(16)
  s(:) = 0
!$omp parallel do
  do j = 1, 16
    do i = 1, 100
      s(j) = s(j) + i
    end do
  end do
  if (all(s == t)) then
    print *, "All tests passed successfully."
  else
    print *, "Test failed."
    stop 1
  endif
end program pr71014_test