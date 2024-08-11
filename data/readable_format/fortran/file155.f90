program test_prog
  complex zero, one_two, three_four
  parameter(zero=(0.0e+0,0.0e+0))
  parameter(three=3)
  parameter(four=three+1)
  parameter(one_two=(1.0e+0,2.0e+0), three_four=(three,four))

  ! Test zero
  if (zero == (0.0e+0, 0.0e+0)) then
    write(6,*) "Test zero passed."
  else
    write(6,*) "Test zero failed."
  endif

  ! Test one_two
  if (one_two == (1.0e+0, 2.0e+0)) then
    write(6,*) "Test one_two passed."
  else
    write(6,*) "Test one_two failed."
  endif

  ! Test three_four
  if (three_four == (3.0e+0, 4.0e+0)) then
    write(6,*) "Test three_four passed."
  else
    write(6,*) "Test three_four failed."
  endif

end program test_prog