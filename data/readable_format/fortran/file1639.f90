program testDb
  implicit none
  real :: result

  interface
    real function db(x)
      real, intent(in) :: x
    end function db
  end interface

  ! Test 1
  result = db(1.259e-10)
  print *, "Test 1 (Expect approximately -99.0): ", result

  ! Test 2
  result = db(1.0)
  print *, "Test 2 (Expect approximately 0.0): ", result

  ! Test 3
  result = db(100.0)
  print *, "Test 3 (Expect approximately 20.0): ", result
end program testDb

real function db(x)
  real, intent(in) :: x
  db = -99.0
  if (x > 1.259e-10) then
    db = 10.0 * log10(x)
  endif
end function db