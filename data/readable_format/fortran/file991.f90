program test_r2w
  implicit none

  integer, parameter :: ldr=5, ldw=5, l=3, m=4
  real(kind=8), allocatable :: r(:,:), w(:,:)
  integer :: i, j
  logical :: test_passed

  ! Allocate arrays
  allocate(r(ldr,m), w(ldw,m))

  ! Initialize r with some values
  do i = 1, ldr
     do j = 1, m
        r(i, j) = real(i * 10 + j, kind=8)  ! Example values
     end do
  end do

  ! Call the subroutine
  call r2w(ldr, ldw, l, m, r, w)

  ! Check if w was correctly copied from r
  test_passed = .true.
  do i = 1, l
     do j = 1, m
        if (w(i, j) /= r(i, j)) then
           test_passed = .false.
           exit
        end if
     end do
     if (.not. test_passed) exit
  end do

  if (test_passed) then
     print *, "Test PASSED."
  else
     print *, "Test FAILED."
  end if

  ! Deallocate arrays
  deallocate(r, w)

contains

  subroutine r2w(ldr, ldw, l, m, r, w)
    implicit none
    integer, intent(in) :: ldr, ldw, l, m
    real(kind=8), intent(in) :: r(ldr,m)
    real(kind=8), intent(out) :: w(ldw,m)

    ! Copy the specified section from r to w
    w(1:l,1:m) = r(1:l,1:m)

  end subroutine r2w

end program test_r2w