! Define the module performance
module performance

  implicit none
  save

  private
  public :: perf_header, perf_footer, perf_numbers

contains

  subroutine perf_header()
    implicit none
    write(*,*)
    write(*,'("        # Photons    CPU time (sec)    Photons/sec  ")')
    write(*,'("      ----------------------------------------------")')
  end subroutine perf_header

  subroutine perf_footer()
    implicit none
    write(*,'("      ----------------------------------------------")')
    write(*,*)
  end subroutine perf_footer

  subroutine perf_numbers(count, time)
    implicit none
    integer, intent(in) :: count
    real, intent(in) :: time
    if(time < tiny(1.0)) then
      write(*,'(1X,3X,I12,3X,4X,F10.1,4X,4X,"   ...   ")') count, time
    else
      write(*,'(1X,3X,I12,3X,4X,F10.1,4X,4X,F9.2,4X)') count, time, real(count)/time
    end if
  end subroutine perf_numbers

end module performance

! Main program starts here
program test_performance
  use performance
  implicit none

  integer :: count
  real :: time

  ! Call the performance reporting subroutines
  call perf_header()
  count = 1000000
  time = 123.4
  call perf_numbers(count, time)
  count = 500000
  time = 0.0
  call perf_numbers(count, time)
  call perf_footer()

end program test_performance