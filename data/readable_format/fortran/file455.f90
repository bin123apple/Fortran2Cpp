program test_pack
  implicit none

  type :: container_t
    integer :: entry = -1
  end type container_t

  type(container_t), dimension(1) :: a1, a2
  logical, dimension(1) :: mask = [.true.]

  ! Test setup
  a2(1)%entry = 1
  a1 = pack (a2, mask = mask)

  ! Test
  if (a1(1)%entry == 1) then
    print *, "Test Passed"
  else
    print *, "Test Failed"
    stop 1
  end if

end program test_pack