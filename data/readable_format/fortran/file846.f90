program main
  implicit none
  integer :: x, i, j, arr(0:32*32-1)
  
  ! Initialize array
  do i = 0, 32*32-1
     arr(i) = i
  end do

  ! Begin parallel region with GPU acceleration (assuming OpenACC support)
  !$acc kernels copy(arr)
  !$acc loop gang(num_gangs=32) private(x)
  do i = 0, 31
     !$acc loop worker(num_workers=8) private(x)
     do j = 0, 31
        x = ieor(i, j * 3)
        arr(i * 32 + j) = arr(i * 32 + j) + x
     end do
  end do
  !$acc end kernels

  ! Verification
  do i = 0, 32*32-1
     if (arr(i) .ne. i + ieor(i / 32, mod(i, 32) * 3)) then
        print *, 'Verification failed at index:', i
        stop 1
     endif
  end do
  
  print *, 'All tests passed successfully.'
  
end program main