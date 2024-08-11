module reduction5
  intrinsic min, max
end module reduction5

program reduction_5_regression
  use reduction5, min => max, max => min
  implicit none
  integer :: test_status

  call test2(test_status)
  if (test_status /= 0) then
    print *, "Test failed."
    error stop
  else
    print *, "All tests passed."
  end if

contains
  subroutine test2(test_status)
    use reduction5, min => max, max => min
    integer, intent(out) :: test_status
    integer :: a, b
    test_status = 0
    a = max (1,5)
    b = min (1,5)
    if (a /= 1) test_status = test_status + 1
    if (b /= 5) test_status = test_status + 1
  end subroutine test2
end program