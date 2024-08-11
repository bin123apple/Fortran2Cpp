program test_cp_corrected
  implicit none
  real*8 cp, Tg1, Tg2, cp_cor

  ! Test values
  cp = 1.5
  Tg1 = 300.0
  Tg2 = 350.0

  ! Call subroutine
  call cp_corrected(cp, Tg1, Tg2, cp_cor)

  ! Check result
  if (cp_cor == cp) then
    print *, 'Test passed: cp_cor equals cp.'
  else
    print *, 'Test failed: cp_cor does not equal cp.'
  endif
end program test_cp_corrected

subroutine cp_corrected(cp, Tg1, Tg2, cp_cor)
  implicit none
  real*8 cp, Tg1, Tg2, cp_cor

  Tg1 = Tg1
  Tg2 = Tg2
  cp_cor = cp

end subroutine cp_corrected