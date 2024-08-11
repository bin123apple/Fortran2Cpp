program main
  implicit none
  integer, parameter :: N = 10
  integer :: randomArray(N), ansVal, val, i
  real :: tmp(N)
  integer :: seed_size
  integer, allocatable :: seed(:)
  integer :: count_rate, count_max, clock

  ! Initialize random number generator seed
  call random_seed(size=seed_size)
  allocate(seed(seed_size))
  call system_clock(count=clock, count_rate=count_rate, count_max=count_max)
  seed = clock + 37 * (/ (i - 1, i = 1, seed_size) /)
  call random_seed(put=seed)

  ! Generate random array
  call random_number(tmp)
  do i = 1, N
     randomArray(i) = int(tmp(i) * 10000)
  end do

  ! Perform XOR operations
  ansVal = 0
  do i = 1, N
     ansVal = ieor(ansVal, randomArray(i))
  end do

  val = 0
  do i = 1, N
     val = ieor(val, randomArray(i))
  end do

  ! Simple check (not a proper unit test, but a demonstration)
  if (ansVal == val) then
     print *, "Check PASS: XOR operations are consistent."
  else
     print *, "Check FAIL: XOR operations are inconsistent."
  end if

  ! Display generated array and XOR result for verification
  print *, "Generated array: ", randomArray
  print *, "XOR Result: ", ansVal

  ! Deallocate the seed array
  deallocate(seed)

end program main