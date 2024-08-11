module ModExtras

  integer, parameter :: GSM_ = 1
  integer, parameter :: GSE_ = 2
  logical :: north = .true.
  integer, parameter :: MaxInputLines = 1000

end module ModExtras

program TestModExtras
  use ModExtras
  implicit none
  
  ! Test constants
  if (GSM_ == 1) then
      print *, "Test GSM_: Passed"
  else
      print *, "Test GSM_: Failed"
  end if
  
  if (GSE_ == 2) then
      print *, "Test GSE_: Passed"
  else
      print *, "Test GSE_: Failed"
  end if
  
  ! Test variable
  if (north) then
      print *, "Test north (true): Passed"
  else
      print *, "Test north (true): Failed"
  end if
  
  ! Test MaxInputLines
  if (MaxInputLines == 1000) then
      print *, "Test MaxInputLines: Passed"
  else
      print *, "Test MaxInputLines: Failed"
  end if
  
end program TestModExtras