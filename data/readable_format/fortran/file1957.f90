program omp_simd_test
  implicit none
  integer :: i
  integer, allocatable :: a(:)
  logical :: test_passed

  allocate(a(10))

  !$omp simd
  do i = 1, 10
    a(i) = i
  end do
  !$omp end simd

  test_passed = .true.
  do i = 1, 10
    if (a(i) /= i) then
      print *, "Test failed for element: ", i
      test_passed = .false.
    end if
  end do

  if (test_passed) then
    print *, "All tests passed."
  else
    print *, "Some tests failed."
  end if

end program omp_simd_test