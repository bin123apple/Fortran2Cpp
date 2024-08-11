! test_ConverterCommonModule.f90
module ConverterCommonModule
  private
  public :: SupportPreproc
  
  logical :: SupportPreproc = .false. 
  
end module ConverterCommonModule

program test_converter
  use ConverterCommonModule
  implicit none
  
  ! Test initial value
  if (SupportPreproc .eqv. .false.) then
    print *, "Test 1 Passed: SupportPreproc is initially .false."
  else
    print *, "Test 1 Failed: SupportPreproc is not .false. as expected."
  endif
  
  ! Test changing value
  SupportPreproc = .true.
  if (SupportPreproc .eqv. .true.) then
    print *, "Test 2 Passed: SupportPreproc changed to .true."
  else
    print *, "Test 2 Failed: SupportPreproc did not change as expected."
  endif
end program test_converter