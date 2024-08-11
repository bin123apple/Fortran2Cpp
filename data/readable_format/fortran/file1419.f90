program main
  character (len=20) :: c
  open(unit=10, file='output.txt', status='replace')
  c = '     '
  write(10,*)c
  close(10)
end program main