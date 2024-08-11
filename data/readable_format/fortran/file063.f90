module pr94329_mod
  implicit none
contains
  subroutine pr94329 (s, t)
    real :: s
    real, dimension(:,:) :: t
    integer :: i, j
    do i = 1,3
      do j = 1,3
        s = t(i,j)
      end do
    end do
  end subroutine pr94329
end module pr94329_mod

program test_pr94329
  use pr94329_mod
  implicit none
  real :: s
  real, dimension(3,3) :: t = reshape([1.0, 2.0, 3.0, &
                                       4.0, 5.0, 6.0, &
                                       7.0, 8.0, 9.0], &
                                       [3, 3])
  call pr94329(s, t)
  if (s == 9.0) then
    print *, "Test passed: s is 9.0"
  else
    print *, "Test failed: s is not 9.0"
  end if
end program test_pr94329