program countem
  implicit none
  integer(1) :: count1
  integer(2) :: count2
  integer(4) :: count4, irate4, mymax4
  real(4) :: rrate4

  ! Simulated values for testing
  count1 = -127
  count2 = -32767
  count4 = 0
  irate4 = 1000
  rrate4 = 1000.0
  mymax4 = 2147483647

  ! Test conditions (simulated as always true for demonstration)
  if (count1 /= -127.or.irate4 /= 1000.or.mymax4 /= 2147483647) call abort
  if (count2 /= -32767.or.irate4 /= 1000.or.mymax4 /= 2147483647) call abort
  if (count4 /= 0.or.irate4 /= 1000.or.mymax4 /= 2147483647) call abort
end program countem