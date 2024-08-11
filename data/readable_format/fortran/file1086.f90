module modf_mod
  implicit none
contains
  integer function modf(m, ix)
    integer, intent(in) :: m, ix
    integer :: ia
    ia = 0
    if (ix <= 0) ia = m
    modf = ix + ia - ( (ix + ia - 1) / m ) * m
    if (modf < 1) modf = modf + m
  end function modf
end module modf_mod

program test_modf
  use modf_mod
  implicit none
  integer :: result
  ! Test cases
  result = modf(3, 4)
  print *, 'Test 1: Expected 1, got ', result
  
  result = modf(5, -1)
  print *, 'Test 2: Expected 5, got ', result
  
  result = modf(10, 27)
  print *, 'Test 3: Expected 7, got ', result
  
  result = modf(1, 0)
  print *, 'Test 4: Expected 1, got ', result
end program test_modf