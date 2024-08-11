module esp_C_mod
  use, intrinsic :: iso_fortran_env, only: real64
  implicit none
  real(real64), parameter :: tf(0:2) = [33.0_real64, 37.0_real64, 41.0_real64]
end module esp_C_mod

program test_esp_C
  use esp_C_mod
  implicit none
  
  write(*,*) "Fortran Stdout:"
  if (tf(0) == 33.0_real64 .and. tf(1) == 37.0_real64 .and. tf(2) == 41.0_real64) then
    write(*,*) "Static array tf initialized correctly."
  else
    write(*,*) "Static array tf initialization failed."
  endif
end program test_esp_C