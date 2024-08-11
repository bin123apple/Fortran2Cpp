module mparameters
  implicit none
  integer, parameter :: DISTRIBUTION_TYPE_ELEMENTAL = 1
  integer, parameter :: DISTRIBUTION_TYPE_ASSEMBLED = 2
  integer, parameter :: DISTRIBUTION_TYPE_STRUCTURED = 3
end module mparameters

program test_mparameters
  use mparameters
  implicit none

  write(*,*) 'Testing mparameters...'
  if (DISTRIBUTION_TYPE_ELEMENTAL == 1) then
    write(*,*) 'DISTRIBUTION_TYPE_ELEMENTAL test passed.'
  else
    write(*,*) 'DISTRIBUTION_TYPE_ELEMENTAL test failed.'
  endif

  if (DISTRIBUTION_TYPE_ASSEMBLED == 2) then
    write(*,*) 'DISTRIBUTION_TYPE_ASSEMBLED test passed.'
  else
    write(*,*) 'DISTRIBUTION_TYPE_ASSEMBLED test failed.'
  endif

  if (DISTRIBUTION_TYPE_STRUCTURED == 3) then
    write(*,*) 'DISTRIBUTION_TYPE_STRUCTURED test passed.'
  else
    write(*,*) 'DISTRIBUTION_TYPE_STRUCTURED test failed.'
  endif
end program test_mparameters