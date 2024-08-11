program test_us_recl
  real, dimension(5) :: array = 5.4321
  integer :: istatus
  open(unit=10, form="unformatted", access="sequential", RECL=16)
  write(10, iostat=istatus) array
  close(10)
  if (istatus == 0) then
    open(unit=11, file="success_flag.txt", status="replace", action="write")
    write(11, *) "Success"
    close(11)
  else
    STOP 1
  endif
end program test_us_recl