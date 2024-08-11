module juslin_scr
  implicit none
contains
  subroutine init_juslin(success)
    logical, intent(out) :: success
    print *, "Juslin module initialized."
    success = .true.
  end subroutine init_juslin
end module juslin_scr

program test_juslin
  use juslin_scr
  implicit none
  logical :: success
  
  call init_juslin(success)
  
  if (success) then
    print *, "Initialization successful."
  else
    print *, "Initialization failed."
  endif
end program test_juslin