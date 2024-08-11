program testColl_gammaN_exclPi
  implicit none
  ! Define types here since we're not using external modules
  type particle
    integer :: ID
    ! Add other particle properties here
  end type particle

  type nucleonType
    integer :: charge
    ! Add other nucleon properties here
  end type nucleonType

  type electronNucleon_event
    type(nucleonType) :: nucleon
    ! Add other electronNucleon_event properties here
  end type electronNucleon_event

  type(electronNucleon_event) :: eNev
  integer :: ExclPiCharge
  type(particle), allocatable :: OutPart(:)
  real :: XS_Tot
  logical :: FlagOK
  integer :: i

  ! Initialize test conditions here
  eNev%nucleon%charge = 1  ! Example value
  ExclPiCharge = 0
  allocate(OutPart(3))  ! Example size
  OutPart(:)%ID = 0  ! Initialize IDs or other necessary properties if needed

  call DoColl_gammaN_exclPi(eNev, ExclPiCharge, FlagOK, OutPart, XS_Tot)

  ! Example test assertions
  print *, "FlagOK: ", FlagOK
  print *, "XS_Tot: ", XS_Tot
  do i = 1, size(OutPart)
    print *, "OutPart(", i, ")%ID: ", OutPart(i)%ID
  end do

contains

  subroutine DoColl_gammaN_exclPi(eNev, ExclPiCharge, flagOK, OutPart, XS_tot)
    type(electronNucleon_event), intent(in) :: eNev
    integer, intent(in) :: ExclPiCharge
    type(particle), dimension(:), intent(out) :: OutPart
    real, intent(out) :: XS_Tot
    logical, intent(out) :: FlagOK

    integer :: NucCharge

    OutPart%ID = 0
    XS_Tot = 0.0
    FlagOK = .false.

    NucCharge = eNev%nucleon%charge - ExclPiCharge
    if (NucCharge < 0 .or. NucCharge > 1) then
      return
    else
      FlagOK = .true.
    endif
  end subroutine DoColl_gammaN_exclPi

end program testColl_gammaN_exclPi