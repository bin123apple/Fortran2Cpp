! Define the subroutine switch1
subroutine switch1(sw, dsw, z, p1, ip1, zmemb1, zmemb2)
  implicit none
  real :: sw, dsw, z, p1, ip1, zmemb1, zmemb2
  real :: delz, delzp1

  if (z.ge.(zmemb2+p1).or.z.le.(zmemb1-p1)) then 
    sw = 0.0
    dsw = 0.0
  else
    if (z.gt.zmemb2) then 
      delz = z - zmemb2
      delzp1 = delz * ip1
      sw = 1.0 + (2.0*delzp1-3.0)*delzp1**2
      dsw = -6.0*(delzp1-1.0)*ip1*delzp1
    elseif (z.lt.zmemb1) then 
      delz = zmemb1 - z
      delzp1 = delz * ip1
      sw = 1.0 + (2.0*delzp1-3.0)*delzp1**2
      dsw = 6.0*(delzp1-1.0)*ip1*delzp1
    else
      sw = 1.0
      dsw = 0.0
    endif
  endif
end subroutine switch1

! Main program to test subroutine switch1
program test_switch1
  implicit none
  real :: sw, dsw, z, p1, ip1, zmemb1, zmemb2

  ! Test case 1: z within the range
  z = 5.0; p1 = 1.0; ip1 = 1.0; zmemb1 = 4.0; zmemb2 = 6.0
  call switch1(sw, dsw, z, p1, ip1, zmemb1, zmemb2)
  print *, "Test 1: sw=", sw, "dsw=", dsw

  ! Test case 2: z outside the range, above zmemb2+p1
  z = 8.0; p1 = 1.0; ip1 = 1.0; zmemb1 = 4.0; zmemb2 = 6.0
  call switch1(sw, dsw, z, p1, ip1, zmemb1, zmemb2)
  print *, "Test 2: sw=", sw, "dsw=", dsw

  ! Test case 3: z outside the range, below zmemb1-p1
  z = 2.0; p1 = 1.0; ip1 = 1.0; zmemb1 = 4.0; zmemb2 = 6.0
  call switch1(sw, dsw, z, p1, ip1, zmemb1, zmemb2)
  print *, "Test 3: sw=", sw, "dsw=", dsw

  ! Additional tests can be added here with different values
end program test_switch1