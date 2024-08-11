module angleModelClass
  implicit none

  ! Define the kind for real numbers
  integer, parameter :: rb = selected_real_kind(p=15)

  ! Parameter for zero value
  real(rb), parameter :: zero = 0.0_rb

  type, abstract :: cModel
    character(len=20) :: name
  end type cModel

  type, abstract, extends(cModel) :: cAngleModel
    contains
      procedure(cAngleModel_compute), deferred, pass :: compute
  end type cAngleModel

  abstract interface
    subroutine cAngleModel_compute(self, Ea, Fa, theta)
      import :: cAngleModel, rb
      class(cAngleModel), intent(in) :: self
      real(rb), intent(out) :: Ea, Fa
      real(rb), intent(in) :: theta
    end subroutine cAngleModel_compute
  end interface

  type, extends(cAngleModel) :: angle_none
    contains
      procedure, pass :: setup => angle_none_setup
      procedure, pass :: compute => angle_none_compute
  end type angle_none

contains

  subroutine angle_none_setup(self)
    class(angle_none), intent(inout) :: self
    self%name = "none"
  end subroutine angle_none_setup

  subroutine angle_none_compute(self, Ea, Fa, theta)
    class(angle_none), intent(in) :: self
    real(rb), intent(out) :: Ea, Fa
    real(rb), intent(in) :: theta
    Ea = zero
    Fa = zero
  end subroutine angle_none_compute

end module angleModelClass

program testAngleModel
  use angleModelClass
  implicit none

  type(angle_none) :: model
  real(rb) :: Ea, Fa
  real(rb) :: theta = 1.0_rb

  ! Test setup method
  call model%setup()
  if (trim(model%name) /= 'none') then
    print *, 'Test setup FAILED'
    stop
  end if
  print *, 'Test setup PASSED'

  ! Test compute method
  call model%compute(Ea, Fa, theta)
  if (Ea /= zero .or. Fa /= zero) then
    print *, 'Test compute FAILED'
    stop
  end if
  print *, 'Test compute PASSED'

end program testAngleModel