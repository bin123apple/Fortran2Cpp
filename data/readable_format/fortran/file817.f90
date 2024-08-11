module notwin_mod
  implicit none
contains
  logical function notwin(xw1,xw2,x) 
    double precision, intent(in) :: xw1, xw2, x
    if (xw1 > xw2) then
      notwin = .false.
    else
      notwin = x < xw1 .or. x > xw2
    end if
  end function notwin
end module notwin_mod

program testNotwin
  use notwin_mod
  implicit none
  
  logical :: result
  
  ! Test 1: x is within the range
  result = notwin(1.0d0, 5.0d0, 3.0d0)
  print *, "Test 1 (Expect .FALSE.): ", result

  ! Test 2: x is outside the range (greater than xw2)
  result = notwin(1.0d0, 5.0d0, 6.0d0)
  print *, "Test 2 (Expect .TRUE.): ", result

  ! Test 3: x is outside the range (less than xw1)
  result = notwin(1.0d0, 5.0d0, 0.0d0)
  print *, "Test 3 (Expect .TRUE.): ", result

  ! Test 4: xw1 is greater than xw2
  result = notwin(5.0d0, 1.0d0, 3.0d0)
  print *, "Test 4 (Expect .FALSE.): ", result

  ! Test 5: x is equal to xw1
  result = notwin(1.0d0, 5.0d0, 1.0d0)
  print *, "Test 5 (Expect .FALSE.): ", result

  ! Test 6: x is equal to xw2
  result = notwin(1.0d0, 5.0d0, 5.0d0)
  print *, "Test 6 (Expect .FALSE.): ", result

end program testNotwin