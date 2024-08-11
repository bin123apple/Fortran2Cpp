program intrinsic_mmloc_4_test
  integer, allocatable, dimension(:) :: d
  integer, allocatable, dimension(:,:) :: a
  integer, dimension(2) :: b

  ! Test 1: Empty 1D array
  allocate (d(0))
  if (maxloc(d, 1) .ne. 0) then
    print *, "Test 1 Failed"
  else
    print *, "Test 1 Passed"
  endif

  ! Test 2: Empty 2D array
  allocate (a(1, 0))
  b = minloc(a)
  if (any(b .ne. 0)) then
    print *, "Test 2 Failed"
  else
    print *, "Test 2 Passed"
  endif

  ! Test 3: Non-empty 1D array
  allocate (d(3))
  d = [3, 1, 2]
  if (maxloc(d, 1) .ne. 1) then
    print *, "Test 3 Failed"
  else
    print *, "Test 3 Passed"
  endif

  ! Test 4: Non-empty 2D array
  deallocate(a)
  allocate (a(2,2))
  a = reshape([4, 1, 3, 2], shape(a))
  b = minloc(a)
  if (b(1) .ne. 1 .or. b(2) .ne. 2) then
    print *, "Test 4 Failed"
  else
    print *, "Test 4 Passed"
  endif
end program