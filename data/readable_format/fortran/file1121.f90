program kind_tests
  implicit none
  integer, parameter :: LARGE_INT = selected_int_kind(18)
  integer(kind=LARGE_INT) :: t = -123456_LARGE_INT

  integer, parameter :: R_DP = selected_real_kind(15, 307)
  real(kind=R_DP) :: x = 1.7_R_DP

  integer, parameter :: R_QP = selected_real_kind(33, 4931)
  real(kind=R_QP) :: y = 1.9_R_QP
  
  ! Test the values
  print *, "Testing t..."
  if (t == -123456) then
    print *, "PASS: t has the expected value."
  else
    print *, "FAIL: t does not have the expected value."
  end if

  print *, "Testing x..."
  if (x == 1.7_R_DP) then
    print *, "PASS: x has the expected value."
  else
    print *, "FAIL: x does not have the expected value."
  end if

  print *, "Testing y..."
  if (y == 1.9_R_QP) then
    print *, "PASS: y has the expected value."
  else
    print *, "FAIL: y does not have the expected value."
  end if
end program kind_tests