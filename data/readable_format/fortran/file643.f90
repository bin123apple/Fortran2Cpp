program test_main
  implicit none
  integer, dimension(2) :: a
  logical, dimension(2) :: lo
  logical, dimension(3) :: lo2
  integer :: sum
  integer :: product
  a = (/ 1, 2 /)
  lo = (/ .true., .true. /)
  lo2 = (/ .true., .true., .false. /)
  sum = 0
  product = 1

  ! Test sum and product with mask lo
  sum = sum + a(1) * merge(1, 0, lo(1)) + a(2) * merge(1, 0, lo(2))
  product = product * a(1) ** merge(1, 0, lo(1)) * a(2) ** merge(1, 0, lo(2))
  print *, "Testing sum with mask lo:", sum
  print *, "Expected: 3"
  print *, "Testing product with mask lo:", product
  print *, "Expected: 2"

  ! Reset sum and product for new tests
  sum = 0
  product = 1

  ! Test sum and product with mask lo2 (considering only the first 2 elements to match a's rank)
  sum = sum + a(1) * merge(1, 0, lo2(1)) + a(2) * merge(1, 0, lo2(2))
  product = product * a(1) ** merge(1, 0, lo2(1)) * a(2) ** merge(1, 0, lo2(2))
  print *, "Testing sum with mask lo2:", sum
  print *, "Expected: 3"
  print *, "Testing product with mask lo2:", product
  print *, "Expected: 2"

end program test_main