program collapse8
  implicit none
  integer :: i, j, k
  integer, dimension(1:7, -3:5, 12:19) :: a, b
  integer :: v1, v2, v3, v4, v5, v6
  logical :: l, r
  logical :: test_passed

  ! Initialize variables
  l = .false.
  r = .false.
  a = 0
  b = 0
  v1 = 3
  v2 = 6
  v3 = -2
  v4 = 4
  v5 = 13
  v6 = 18

  ! Parallel region (simulated, actual parallelism requires OpenACC directives)
  l = .false.
  do i = v1, v2
    do j = v3, v4
      do k = v5, v6
        l = l.or.i.lt.2.or.i.gt.6.or.j.lt.-2.or.j.gt.4
        l = l.or.k.lt.13.or.k.gt.18
        if (.not.l) a(i, j, k) = a(i, j, k) + 1
      end do
    end do
  end do

  ! Sequential region
  r = .false.
  do i = v1, v2
    do j = v3, v4
      do k = v5, v6
        r = r.or.i.lt.2.or.i.gt.6.or.j.lt.-2.or.j.gt.4
        r = r.or.k.lt.13.or.k.gt.18
        if (.not.r) b(i, j, k) = b(i, j, k) + 1
      end do
    end do
  end do

  ! Check correctness
  test_passed = .true.
  do i = v1, v2
    do j = v3, v4
      do k = v5, v6
        if (a(i, j, k) .ne. b(i, j, k)) then
          test_passed = .false.
          exit
        endif
      end do
      if (.not.test_passed) exit
    end do
    if (.not.test_passed) exit
  end do

  if (.not.test_passed) then
    print *, "Test failed."
  else
    print *, "All tests passed."
  endif

  if (l .neqv. r) then
    print *, "Logic error: l and r do not match."
    call abort
  endif

end program collapse8