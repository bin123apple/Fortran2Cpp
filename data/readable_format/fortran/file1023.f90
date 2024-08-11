program testReturnAndStop
  implicit none

  call return_and_stop(0) ! This should just return
  print *, "Test with 0 passed."

  ! Uncommenting the line below would stop the program; thus, it's commented out for safety.
  ! call return_and_stop(1) ! This should stop the program.
  ! print *, "If this is printed, the test with 1 failed."

end program testReturnAndStop

subroutine return_and_stop(n)
  integer, intent(in) :: n
  if (n==0) then
     return
  end if
  stop
end subroutine return_and_stop