program test_main
  implicit none
  integer, parameter :: n = 10
  complex, dimension(n,n) :: a, b, c
  real, dimension(n,n) :: r
  integer :: i, j

  ! Generate random numbers for the real and imaginary parts of c
  call random_number(r)
  do i = 1, n
    do j = 1, n
      c(i,j) = cmplx(r(i,j), 0.0)
    end do
  end do
  
  call random_number(r)
  do i = 1, n
    do j = 1, n
      c(i,j) = cmplx(real(c(i,j)), r(i,j))
    end do
  end do

  a = c
  b = c

  ! Subtract 0.5 from real and imaginary parts of a and b
  do i = 1, n
    do j = 1, n
      a(i,j) = cmplx(real(a(i,j)) - 0.5, aimag(a(i,j)) - 0.5)
      b(i,j) = cmplx(real(b(i,j)) - 0.5, aimag(b(i,j)) - 0.5)
    end do
  end do

  ! Compare a and b
  if (any(a /= b)) then
    print *, "Test failed at step 1"
    stop
  end if

  ! Assign real parts of a to imaginary parts of b and a
  do i = 1, n
    do j = 1, n
      b(i,j) = cmplx(real(b(i,j)), real(a(i,j)))
      a(i,j) = cmplx(real(a(i,j)), real(a(i,j)))
    end do
  end do

  ! Compare a and b
  if (any(a /= b)) then
    print *, "Test failed at step 2"
    stop
  end if

  ! Reset matrices a and b to c
  a = c
  b = c

  ! Iterate over the matrices with adjusted indices to avoid slicing
  do i = 2, n
    do j = 1, n
      b(i,j) = cmplx(real(a(i-1,j)), aimag(b(i,j)))
      a(i,j) = cmplx(real(a(i-1,j)), aimag(a(i,j)))
    end do
  end do

  ! Compare a and b
  if (any(a /= b)) then
    print *, "Test failed at step 3"
    stop
  end if

  ! Reset matrices a and b to c
  a = c
  b = c

  ! Adjust the imaginary parts similar to the previous step to avoid slicing
  do i = 1, n-1
    do j = 1, n
      b(i,j) = cmplx(real(b(i,j)), aimag(a(i+1,j)))
      a(i,j) = cmplx(real(a(i,j)), aimag(a(i+1,j)))
    end do
  end do

  ! Compare a and b
  if (any(a /= b)) then
    print *, "Test failed at step 4"
    stop
  end if

  print *, "All tests passed!"
  
end program test_main