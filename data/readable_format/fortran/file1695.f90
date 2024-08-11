program test
  implicit none
  call printCommonBlockValues
end program test

subroutine printCommonBlockValues
  implicit none
  common /blocka/ a, b, d
  double precision a, b, d(10,30)
  
  ! Initialize variables for testing purposes
  a = 0.0
  b = 0.0
  d = 0.0
  
  print *, 'Testing common block'
  print *, 'a = ', a
  print *, 'b = ', b
  print *, 'First element of d = ', d(1,1)
end subroutine printCommonBlockValues