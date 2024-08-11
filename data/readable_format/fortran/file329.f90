module utiltime
  implicit none
contains
  real function dtime(val)
    integer, intent(in) :: val(8)
    integer :: itime
    itime = val(2) + val(3)*60*60*24 + val(5)*3600 + val(6)*60 + val(7)
    dtime = real(itime) + real(val(8)) * 0.001
  end function dtime
end module utiltime

program mat2
  use utiltime
  implicit none

  integer, parameter :: n = 100 ! Reduced size for testing
  real, allocatable :: a(:,:), b(:,:), c(:,:)
  integer :: i, j, k
  integer :: val0(8), val1(8)
  real :: t_0, t_1, gflops
  logical :: test_passed
  
  allocate(a(n,n), b(n,n), c(n,n))
  a = 1.0
  b = 2.0
  c = 0.0
  
  ! Timing start
  val0 = 0
  call date_and_time(values=val0)
  t_0 = dtime(val0)
  
  ! Matrix multiplication
  do j = 1, n
    do i = 1, n
      do k = 1, n
         c(i,j) = c(i,j) + a(i,k) * b(k,j)
      end do
    end do
  end do
  
  ! Timing end
  val1 = 0
  call date_and_time(values=val1)
  t_1 = dtime(val1)
  
  gflops = real(n)**3 * 2.0 / (t_1 - t_0) / 1000000000.0
  print *, "Total Time: ", t_1 - t_0
  print *, "Total MM GFLOPS: ", gflops
  
  ! Simplified "unit test" for matrix multiplication
  test_passed = .true.
  do j = 1, n
    do i = 1, n
      if (c(i,j) /= real(n) * 2.0) then
        test_passed = .false.
        exit
      end if
    end do
    if (.not. test_passed) exit
  end do
  
  if (test_passed) then
    print *, "Matrix multiplication test passed."
  else
    print *, "Matrix multiplication test failed."
  end if
  
  ! Clean up
  deallocate(a,b,c)
end program mat2