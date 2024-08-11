program large_recl_test
  implicit none
  integer(kind=8) :: r
  logical :: test_passed

  ! Original functionality wrapped in a test
  call test_large_record_handling(test_passed)
  
  if (test_passed) then
     print *, "Test PASSED: Large record handling works as expected."
  else
     print *, "Test FAILED: Large record handling did not work as expected."
  end if

contains

  subroutine test_large_record_handling(test_passed)
    implicit none
    logical, intent(out) :: test_passed
    integer(kind=8) :: r
    
    ! Initialize the test outcome to false
    test_passed = .false.
    
    ! Attempt to open, inquire, and close as in the original program.
    open(unit=10, status="scratch", recl=12345678901_8, form="unformatted", access="direct")
    inquire(unit=10, recl=r)
    close(unit=10, status="delete")
    
    ! Check if the operation succeeded as expected.
    if (r == 12345678901_8) then
       test_passed = .true.
    else
       test_passed = .false.
    end if
  end subroutine test_large_record_handling

end program large_recl_test