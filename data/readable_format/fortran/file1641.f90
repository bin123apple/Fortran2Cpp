PROGRAM testDCABS1
  COMPLEX*16 Z
  DOUBLE PRECISION DCABS1
  EXTERNAL DCABS1

  Z = (3.0D0, 4.0D0)  ! A complex number where real=3 and imag=4
  PRINT *, 'Test 1: DCABS1((3.0, 4.0)) = ', DCABS1(Z)  ! Expected: 7.0

  Z = (-1.5D0, 2.5D0) ! Another complex number where real=-1.5 and imag=2.5
  PRINT *, 'Test 2: DCABS1((-1.5, 2.5)) = ', DCABS1(Z)  ! Expected: 4.0

END PROGRAM testDCABS1

DOUBLE PRECISION FUNCTION DCABS1(Z)
  COMPLEX*16 Z
  INTRINSIC ABS,DBLE,DIMAG
  DCABS1 = ABS(DBLE(Z)) + ABS(DIMAG(Z))
  RETURN
END