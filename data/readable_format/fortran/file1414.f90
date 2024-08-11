program test_main
  implicit none
  integer :: a(2,3)
  integer :: ires

  ! Test 1: Without optional parameter
  call checkv(ires, a)
  if (ires == 6) then
    print *, "Test 1 passed."
  else
    print *, "Test 1 failed."
  end if

  ! Test 2: With optional parameter
  call checkv(ires, a, 1)
  if (ires == 2) then
    print *, "Test 2 passed."
  else
    print *, "Test 2 failed."
  end if

contains

  subroutine checkv(ires, a1, opt1)
    integer, intent(out) :: ires
    integer :: a1(:,:)
    integer, optional :: opt1

    if (present(opt1)) then
      ires = size(a1, dim=opt1)
    else
      ires = size(a1)
    end if
  end subroutine checkv

end program test_main