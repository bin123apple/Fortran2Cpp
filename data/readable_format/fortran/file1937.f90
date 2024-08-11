! Save this as test_program.f90
program test
  integer :: i = 2
  open(unit=10, file='output.txt')
100 x: select case (i)
200 case default
    write(10, *) i
  end select x
  close(10)
end program test