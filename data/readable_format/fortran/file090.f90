program testFprati
  implicit none
  double precision :: result
  double precision :: p1, f1, p2, f2, p3, f3

  ! Test case
  p1 = 1.0
  f1 = 2.0
  p2 = 3.0
  f2 = 4.0
  p3 = 5.0
  f3 = 6.0

  result = fprati(p1, f1, p2, f2, p3, f3)
  print *, "Fortran Test Result: ", result

contains
  
  double precision function fprati(p1, f1, p2, f2, p3, f3)
    double precision p1, f1, p2, f2, p3, f3
    double precision h1, h2, h3, p

    if (p3 .gt. 0.0) then
        h1 = f1 * (f2 - f3)
        h2 = f2 * (f3 - f1)
        h3 = f3 * (f1 - f2)
        p = -(p1 * p2 * h3 + p2 * p3 * h1 + p3 * p1 * h2) / (p1 * h1 + p2 * h2 + p3 * h3)
    else
        p = (p1 * (f1 - f3) * f2 - p2 * (f2 - f3) * f1) / ((f1 - f2) * f3)
    endif
    fprati = p
  end function fprati

end program testFprati