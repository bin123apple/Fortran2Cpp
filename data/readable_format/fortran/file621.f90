program test_cdiv
  implicit none
  double precision ar, ai, br, bi, cr, ci

  ! Test values
  ar = 3.0d0
  ai = 4.0d0
  br = 1.0d0
  bi = -2.0d0

  call cdiv(ar, ai, br, bi, cr, ci)

  print *, "Result: (cr, ci) = ", cr, ci

end program test_cdiv

subroutine cdiv(ar,ai,br,bi,cr,ci)
  double precision ar,ai,br,bi,cr,ci
  double precision s,ars,ais,brs,bis,s_inv
  s_inv = 1.0d0 / ( dabs(br) + dabs(bi) )
  ars = ar * s_inv
  ais = ai * s_inv
  brs = br * s_inv
  bis = bi * s_inv
  s_inv = 1.0d0 / ( brs*brs + bis*bis )
  cr = (ars*brs + ais*bis) * s_inv
  ci = (ais*brs - ars*bis) * s_inv
  return
end