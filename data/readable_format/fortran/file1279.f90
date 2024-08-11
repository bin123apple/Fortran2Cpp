module m_mod
  implicit none
  real :: a(4), u(3,2)
  real :: b(4), v(4,2)
  equivalence (a(1),u(1,1)), (b(1),v(1,1))
end module m_mod

program test_equivalence
  use m_mod
  implicit none
  
  ! Initialize elements to test equivalence
  a(1) = 10.0
  b(1) = 20.0
  
  ! Test equivalence between 'a' and 'u', and between 'b' and 'v'
  print *, "Testing equivalence..."
  if (u(1,1) == a(1)) then
    print *, "PASS: a(1) and u(1,1) are equivalent."
  else
    print *, "FAIL: a(1) and u(1,1) are not equivalent."
  end if
  
  if (v(1,1) == b(1)) then
    print *, "PASS: b(1) and v(1,1) are equivalent."
  else
    print *, "FAIL: b(1) and v(1,1) are not equivalent."
  end if
end program test_equivalence