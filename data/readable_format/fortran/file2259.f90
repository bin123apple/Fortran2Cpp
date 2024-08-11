module weno_module
  implicit none
  private
  public :: weno_factory, weno_constructor, weno_interpolator, weno_constructor_upwind, weno_interpolator_upwind

  type, abstract :: weno_constructor
  end type weno_constructor

  type, extends(weno_constructor) :: weno_constructor_upwind
  end type weno_constructor_upwind

  type, abstract :: weno_interpolator
    contains
      procedure(interpolate_interface), deferred, pass :: interpolate
  end type weno_interpolator

  abstract interface
    subroutine interpolate_interface(this, constructor)
      import :: weno_interpolator, weno_constructor
      class(weno_interpolator), intent(in) :: this
      class(weno_constructor), intent(in) :: constructor
    end subroutine interpolate_interface
  end interface

  type, extends(weno_interpolator) :: weno_interpolator_upwind
    contains
      procedure, pass :: interpolate => interpolate_upwind
  end type weno_interpolator_upwind

  type :: weno_factory
    contains
      procedure :: create => create_interpolator
  end type weno_factory

contains

  subroutine create_interpolator(this, constructor, interpolator)
    class(weno_factory), intent(in) :: this
    class(weno_constructor), intent(in) :: constructor
    class(weno_interpolator), allocatable, intent(out) :: interpolator

    select type(constructor)
    type is (weno_constructor_upwind)
      allocate(weno_interpolator_upwind :: interpolator)
    end select
  end subroutine create_interpolator

  subroutine interpolate_upwind(this, constructor)
    class(weno_interpolator_upwind), intent(in) :: this
    class(weno_constructor), intent(in) :: constructor
    print *, "Interpolating using upwind method."
  end subroutine interpolate_upwind

end module weno_module

program weno_test
  use weno_module
  implicit none

  type(weno_factory) :: factory
  class(weno_constructor), allocatable :: constructor
  class(weno_interpolator), allocatable :: interpolator

  ! Test creating a WENO interpolator
  allocate(weno_constructor_upwind :: constructor)
  call factory%create(constructor, interpolator)

  if (allocated(interpolator)) then
     call interpolator%interpolate(constructor)
  else
     print *, "Interpolator allocation failed."
  end if

end program weno_test