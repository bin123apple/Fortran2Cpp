program test_omp_do
  integer :: a(10), b(10), expected_b(10)
  integer :: i, j, test_passed

  a = 10
  expected_b = 20 ! Since we're doubling the value of each element in a
  j = 0

  !$omp parallel
    !$omp do linear(j:1)
    do i = 1, 10
      j = j + 1
      b(i) = a(i) * 2.0
    end do
    !$omp end do
  !$omp end parallel

  test_passed = 1
  do i = 1, 10
    if (b(i) /= expected_b(i)) then
      test_passed = 0
      exit
    endif
  end do

  if (test_passed == 1) then
    print *, "Test passed."
  else
    print *, "Test failed."
  endif
end program test_omp_do