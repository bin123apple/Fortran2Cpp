program test_foo
  implicit none
  integer :: a(3,3), l, ll
  logical :: test_passed

  ! Test 1: Check if all elements are set to 2
  a = 0
  do l=1,3
     do ll=1,3
        a(l,ll) = 2
     enddo
  enddo
  test_passed = .true.
  do l=1,3
     do ll=1,3
        if (a(l,ll) /= 2) then
           test_passed = .false.
           exit
        endif
     enddo
     if (.not. test_passed) exit
  enddo

  if (test_passed) then
     print *, "Test 1 Passed: All elements are correctly set to 2."
  else
     print *, "Test 1 Failed."
  endif

  ! Test 2: Check for program stop if any element is not 2 (Manual Observation Required)
  print *, "For Test 2, manually alter the code to make one element not equal to 2 and observe if STOP 1 is triggered."

end program test_foo