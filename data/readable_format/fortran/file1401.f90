program collapse7
  implicit none
  integer :: i, j, k, a(1:7, -3:5, 12:19), b(1:7, -3:5, 12:19)
  logical :: l, r
  l = .false.
  r = .false.
  a(:, :, :) = 0
  b(:, :, :) = 0
  !$acc parallel
  !$acc loop collapse (3) reduction(.or.:l)
    do i = 2, 6
      do j = -2, 4
        do k = 13, 18
          l = l .or. i < 2 .or. i > 6 .or. j < -2 .or. j > 4
          l = l .or. k < 13 .or. k > 18
          if (.not.l) a(i, j, k) = a(i, j, k) + 1
        end do
      end do
    end do
  !$acc end parallel
  do i = 2, 6
    do j = -2, 4
      do k = 13, 18
        r = r .or. i < 2 .or. i > 6 .or. j < -2 .or. j > 4
        r = r .or. k < 13 .or. k > 18
        if (.not.r) b(i, j, k) = b(i, j, k) + 1
      end do
    end do
  end do
  if (l .neqv. r) STOP 1
  do i = 1, 7
    do j = -3, 5
      do k = 12, 19
         if (a(i, j, k) .ne. b(i, j, k)) STOP 2
      end do
    end do
  end do

  ! Unit Test Code
  print *, "Verifying arrays and conditions..."
  do i = 1, 7
    do j = -3, 5
      do k = 12, 19
        if (a(i, j, k) .ne. b(i, j, k)) then
          print *, "Arrays do not match at: ", i, j, k
          stop 3
        endif
      end do
    end do
  end do
  print *, "Arrays match successfully."
  if (l .eqv. r) then
    print *, "Logical conditions match."
  else
    print *, "Logical conditions do not match."
    stop 4
  endif
end program collapse7