program set
  implicit none
  integer :: centre, date
  integer :: infile, outfile
  integer :: igrib

  centre = 80
  call current_date(date)
  ! Mock function calls to illustrate structure
  print *, "Opening GRIB file (mock)"
  print *, "Setting GRIB file attributes (mock)"
  call check_settings(centre, date)
  
contains

  subroutine current_date(date)
    integer, intent(out) :: date
    integer :: val_date(8)
    call date_and_time(values = val_date)
    date = val_date(1) * 10000 + val_date(2) * 100 + val_date(3)
  end subroutine current_date

  subroutine check_settings(centre, date)
    integer, intent(in) :: centre, date
    ! Mock function to illustrate checking settings
    print *, "Checking settings (mock)"
    print *, "Centre: ", centre
    print *, "Date: ", date
  end subroutine check_settings

end program set