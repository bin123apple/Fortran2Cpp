program test
  implicit none
  integer, save :: itmp(3)
  logical :: test_passed

  itmp(1) = 3
  call test_itmp(itmp, test_passed)
  if (test_passed) then
     write(*,*) "Test PASSED."
  else
     write(*,*) "Test FAILED."
  endif

contains

  subroutine test_itmp(itmp, result)
    integer, intent(in) :: itmp(:)
    logical, intent(out) :: result

    if (size(itmp) == 3 .and. itmp(1) == 3) then
       result = .true.
    else
       result = .false.
    endif
  end subroutine test_itmp

end program test