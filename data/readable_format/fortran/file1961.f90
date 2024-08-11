program testFoo
  implicit none
  integer, parameter :: nnd1 = 5, nnd2 = 10
  double precision, allocatable :: x(:)
  integer :: i

  ! Test Case 1
  allocate(x(nnd1))
  call foo(x, nnd1)
  print *, "Test Case 1 for nnd =", nnd1
  do i=1, nnd1
    print *, "x(", i, ") =", x(i)
  end do
  deallocate(x)

  ! Test Case 2
  allocate(x(nnd2))
  call foo(x, nnd2)
  print *, "Test Case 2 for nnd =", nnd2
  do i=1, nnd2
    print *, "x(", i, ") =", x(i)
  end do
  deallocate(x)

end program testFoo

subroutine foo(x, nnd)
  double precision, dimension(nnd) :: x
  integer :: i
  
  do i=1, nnd
    x(i) = 1.d0 + (1.d0*i)/nnd
  end do
end subroutine foo