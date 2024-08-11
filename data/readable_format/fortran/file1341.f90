program test_timout
  implicit none

  ! Test cases
  call timout(1, 90061.5d0)  ! More than a day
  call timout(1, 3600.0d0)   ! Exactly one hour
  call timout(1, 60.0d0)     ! Exactly one minute
  call timout(1, 30.0d0)     ! Less than a minute
  call timout(1, 86400.0d0)  ! Exactly one day

contains

  subroutine timout(nout, tim)
    implicit none
    integer, intent(in) :: nout
    real(8), intent(in) :: tim
    integer :: idays, ihours, imins
    real(8) :: mins, days, hours, secs

    days = tim / 86400.0d0
    idays = int(days)
    hours = (days - real(idays)) * 24.0d0
    ihours = int(hours)
    mins = (hours - real(ihours)) * 60.0d0
    imins = int(mins)
    secs = (mins - real(imins)) * 60.0d0

    if (idays > 1) then
      print '(A, I2, A, I2, A, I2, A, F6.3, A)', 'COMPUTATION TIME = ', idays, ' DAYS ', ihours, &
        ' HOURS ', imins, ' MINUTES AND ', secs, ' SECONDS'
    else if (idays == 1) then
      print '(A, I2, A, I2, A, I2, A, F6.3, A)', 'COMPUTATION TIME = ', idays, ' DAY ', ihours, &
        ' HOURS ', imins, ' MINUTES AND ', secs, ' SECONDS'
    else if (ihours > 0) then
      print '(A, I2, A, I2, A, F6.3, A)', 'COMPUTATION TIME = ', ihours, ' HOURS ', imins, &
        ' MINUTES AND ', secs, ' SECONDS'
    else if (imins > 0) then
      print '(A, I2, A, F6.3, A)', 'COMPUTATION TIME = ', imins, ' MINUTES AND ', secs, ' SECONDS'
    else
      print '(A, F6.3, A)', 'COMPUTATION TIME = ', secs, ' SECONDS'
    endif
  end subroutine timout

end program test_timout