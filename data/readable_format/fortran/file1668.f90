module dec_structure_5m
  implicit none
  type s6
    integer :: i
  end type s6

  type s7
    real :: r
  end type s7
end module dec_structure_5m

subroutine test_logic()
  use dec_structure_5m
  type(s6) :: s6_instance
  type(s7), dimension(3) :: s7_instances

  s6_instance%i = 0
  s7_instances(1)%r = 1.0
  s7_instances(2)%r = 2.0
  s7_instances(3)%r = 3.0

  if (s6_instance%i /= 0) then
    print *, "Test failed: s6.i"
  endif

  if (s7_instances(1)%r /= 1.0) then
    print *, "Test failed: s7(1).r"
  endif

  if (s7_instances(2)%r /= 2.0) then
    print *, "Test failed: s7(2).r"
  endif

  print *, "All tests passed."
end subroutine test_logic

program dec_structure_5
  call test_logic()
end program dec_structure_5