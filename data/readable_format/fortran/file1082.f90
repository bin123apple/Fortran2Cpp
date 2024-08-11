program loop_hoist6_test
  implicit none

  ! Call the main subroutine that we're testing
  call clawloop

  ! Here you might include calls to other test subroutines as needed
  ! For a real "unit test", you would check outputs or states against expected values
  ! This example simply demonstrates structure and execution

end program loop_hoist6_test

subroutine clawloop
  implicit none
  integer :: i, j, k
  integer, parameter :: iend = 2, jend = 4, kend = 2

  do i = 0, iend
    if (i == 0) then
      print *, 'First iteration of i', i, '/', j, '/', k
    endif
    do j = 0, jend
      do k = 0, kend
        print *, 'First loop body:', i, '/', j, '/', k
      end do
    end do

    do j = 2, jend
      do k = 0, kend
        print *, 'Second loop body:', i, '/', j, '/', k
      end do
    end do

    do j = 0, jend
      print *, 'ALONE J LOOP'
    end do
  end do
end subroutine clawloop