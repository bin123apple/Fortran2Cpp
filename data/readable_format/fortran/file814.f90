! Define the subroutine get_loop_index
subroutine get_loop_index(instr_index, index, subrange_flag)
  implicit none
  integer :: instr_index, index
  logical :: subrange_flag
  integer, parameter :: in_index_mask = 65536
  integer :: mask_val
  
  mask_val = iand(instr_index, in_index_mask)
  
  if (mask_val == 0) then
     subrange_flag = .false.
     index = instr_index
  else
     subrange_flag = .true.
     index = ieor(instr_index, in_index_mask)
  endif
end subroutine get_loop_index

! Program to test the get_loop_index subroutine
program test_get_loop_index
  implicit none

  integer :: test_index
  logical :: test_subrange_flag
  
  ! Test case 1
  call get_loop_index(0, test_index, test_subrange_flag)
  if (test_subrange_flag .eqv. .false. .and. test_index == 0) then
     print *, "Test 1 passed."
  else
     print *, "Test 1 failed."
  endif
  
  ! Test case 2
  call get_loop_index(65536, test_index, test_subrange_flag)
  if (test_subrange_flag .eqv. .true. .and. test_index == 0) then
     print *, "Test 2 passed."
  else
     print *, "Test 2 failed."
  endif
  
  ! You can add more test cases as needed
end program test_get_loop_index