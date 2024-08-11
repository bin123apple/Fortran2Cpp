program test_current_kind
  ! Define the kind parameter for precision
  use iso_fortran_env, only: real64
  implicit none

  ! Define constants with the specified precision
  real(real64), parameter :: Zero = 0.0_real64, One = 1.0_real64, &
                            Quarter = 0.25_real64, Four = 4.0_real64, &
                            Half = 0.5_real64, Eighth = 0.125_real64, &
                            Two = 2.0_real64, Third = 1.0_real64 / 3.0_real64
                            
  ! Testing the constants
  write(*,*) "Testing constants"
  if (Zero /= 0.0_real64) then
    write(*,*) "Test failed for Zero"
  endif
  if (One /= 1.0_real64) then
    write(*,*) "Test failed for One"
  endif
  if (Quarter /= 0.25_real64) then
    write(*,*) "Test failed for Quarter"
  endif
  if (Four /= 4.0_real64) then
    write(*,*) "Test failed for Four"
  endif
  if (Half /= 0.5_real64) then
    write(*,*) "Test failed for Half"
  endif
  if (Eighth /= 0.125_real64) then
    write(*,*) "Test failed for Eighth"
  endif
  if (Two /= 2.0_real64) then
    write(*,*) "Test failed for Two"
  endif
  if (Third /= 1.0_real64 / 3.0_real64) then
    write(*,*) "Test failed for Third"
  endif
  
  write(*,*) "All tests passed."

end program test_current_kind