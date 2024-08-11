program test_foo
  integer, parameter :: n = 1000
  integer, dimension (0:n-1) :: a, b, c
  common a, b, c
  integer :: nr, ii

  ! Initialize arrays a and b with some test data
  do ii = 0, n-1
     a(ii) = ii
     b(ii) = 2 * ii
  end do

  ! Set the number of elements to process
  nr = 10

  ! Call the subroutine
  call foo(nr)

  ! Print the results
  print *, "Array c:"
  do ii = 0, nr-1
     print *, "c(", ii, ") = ", c(ii)
  end do
end program test_foo

subroutine foo(nr)
  integer, intent(in) :: nr
  integer, parameter :: n = 1000
  integer, dimension (0:n-1) :: a, b, c
  common a, b, c
  integer :: ii

  do ii = 0, nr - 1
     c(ii) = a(ii) + b(ii) + 25
  end do
end subroutine foo