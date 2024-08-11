! Define the module and test program in the same file
module thermo_vars
  implicit none
  save

  ! Constants
  integer, parameter :: MAX_NSP = 20, MAX_PROF = 100, MAX_NCP = 7, MAX_SAT = 10

  ! Variables
  integer :: imixture
  real :: thermo_param(MAX_PROF)
  
  real :: gama0, GRATIO
  real :: MRATIO
  
  integer :: NSP, NCP_CHEMKIN
  character(len=16), dimension(MAX_NSP) :: THERMO_SPNAME
  real, dimension(MAX_NSP) :: WGHT, WGHT_INV
  real :: WREF, TREF, RGAS
  real, dimension(MAX_NSP, MAX_NCP, 2) :: THERMO_AI
  real, dimension(MAX_NSP, 3) :: THERMO_TLIM
  
  integer :: iuse_chemkin
  character(len=128) :: chemkin_file
  
  real :: WMEAN, dsmooth
  real, dimension(MAX_NSP) :: YMASS
  
  integer :: NPSAT
  real, dimension(MAX_SAT) :: THERMO_PSAT
  real :: NEWTONRAPHSON_ERROR
end module thermo_vars

! Test program
program test_thermo_vars
  use thermo_vars
  implicit none

  ! Example initialization
  imixture = 1
  thermo_param(1) = 5.0
  NSP = 10
  THERMO_SPNAME(1) = 'H2O'
  WGHT(1) = 18.015

  ! Display some values to verify correctness
  print *, 'imixture = ', imixture
  print *, 'thermo_param(1) = ', thermo_param(1)
  print *, 'NSP = ', NSP
  print *, 'THERMO_SPNAME(1) = ', THERMO_SPNAME(1)
  print *, 'WGHT(1) = ', WGHT(1)

end program test_thermo_vars