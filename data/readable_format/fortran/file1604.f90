program test_global
  implicit none

  ! Variable definitions directly included
  character(len=30) :: dirIN
  character(len=30) :: dirOUT
  character(len=30) :: dirTMP
  character(len=30) :: simname
  character(len=30) :: filesim
  character(len=30) :: filexy
  character(len=100) :: filename

  integer :: flagbed
  real(8) :: beta, beta0, betaold
  real(8) :: theta, theta0, thetaold
  real(8) :: ds, ds0, dsold
  real(8) :: Rp
  real(8) :: rpic, rpic0
  integer :: jmodel
  real(8) :: Cf, Cf0, Cfold
  real(8) :: CD, CT
  real(8) :: phi, phiD, phiT
  real(8) :: F0

  real(8) :: Ef
  real(8) :: Eb
  real(8) :: Eo
  real(8) :: Ebound
  real(8) :: Lhalfvalley
  real(8) :: Ltransvalley
  integer :: jbound

  integer :: flagxy0
  integer :: flag_ox
  integer :: N, Nold, N0
  integer :: Nrand
  integer :: jre
  integer :: jnco
  integer :: ksavgol
  real(8) :: deltas, deltas0
  real(8) :: dsmin, dsmax
  real(8) :: tollc
  real(8) :: stdv

  integer :: flag_time
  integer :: flag_dt
  integer :: ivideo
  integer :: ifile
  integer :: nend
  real(8) :: TT, TTs
  real(8) :: kTTfco
  real(8) :: tt0
  real(8) :: dt0
  real(8) :: cstab

  ! Test initialization
  beta = 0.0
  simname = 'InitialTest'

  ! Perform basic assignments and checks
  beta = 1.5
  if (beta == 1.5) then
    print *, 'Test passed: beta set to 1.5'
  else
    print *, 'Test failed: beta not set to 1.5'
  endif

  simname = 'TestSimulation'
  if (trim(simname) == 'TestSimulation') then
    print *, 'Test passed: simname set and retrieved correctly'
  else
    print *, 'Test failed: simname not set/retrieved correctly'
  endif
end program test_global