program t_test
      open(unit=10, file='output_fortran.txt', status='replace')
      do 100 i=1,3
      write(10,*)0
      write(10,*)1
 100  write(10,*)2
      close(10)
end program t_test