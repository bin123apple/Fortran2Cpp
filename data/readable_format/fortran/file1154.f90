module globalvars
  implicit none
  integer a
  !$acc declare create(a)
end module globalvars

program test
  use globalvars
  use openacc
  implicit none

  if (acc_is_present(a) .neqv. .true.) then
    print *, "Test failed: variable 'a' is not on the accelerator."
    call abort
  else
    print *, "Test passed: variable 'a' is on the accelerator."
  endif

end program test