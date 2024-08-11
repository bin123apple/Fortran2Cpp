module whatever_mod
  implicit none
contains
  subroutine whatever(l1, l2, l3)
    logical, intent(inout) :: l1
    logical, intent(in) :: l2
    logical, intent(in) :: l3

    if ((l1 .and. l2) .neqv. l3) then
       l1 = .true.
    else
       l1 = .false.  ! Ensure l1 is explicitly set to false when condition is not met
    endif
  end subroutine whatever
end module whatever_mod

program test_whatever
  use whatever_mod
  implicit none
  logical :: l1, l2, l3

  ! Test 1
  l1 = .false.
  l2 = .false.
  l3 = .false.
  call whatever(l1, l2, l3)
  print *, "Test 1 (expected FALSE): ", l1

  ! Test 2
  l1 = .false.
  l2 = .true.
  l3 = .true.
  call whatever(l1, l2, l3)
  print *, "Test 2 (expected TRUE): ", l1
  
end program test_whatever