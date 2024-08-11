module bar
  implicit none
  public :: ESMF_Time, operator(+)

  type, public :: ESMF_Time
     integer :: MM
  end type ESMF_Time

  interface operator(+)
     module procedure add
  end interface

contains

  function add(x, y) result(z)
    type(ESMF_Time), intent(in) :: x, y
    type(ESMF_Time) :: z

    z%MM = x%MM ! For simplicity, just copying x's MM to z's MM.
  end function add

end module bar

module foo
  use bar
  implicit none
  public :: ESMF_Clock

  type, public :: ESMF_Clock
     type(ESMF_Time) :: CurrTime
  end type ESMF_Clock

contains

  subroutine ESMF_ClockAdvance(clock)
    type(ESMF_Clock), intent(inout) :: clock

    clock%CurrTime = clock%CurrTime + clock%CurrTime
  end subroutine ESMF_ClockAdvance

end module foo

program testESMF
  use foo
  implicit none

  type(ESMF_Clock) :: myClock
  myClock%CurrTime%MM = 5

  print *, "Current Time MM before: ", myClock%CurrTime%MM
  call ESMF_ClockAdvance(myClock)
  print *, "Current Time MM after: ", myClock%CurrTime%MM

end program testESMF