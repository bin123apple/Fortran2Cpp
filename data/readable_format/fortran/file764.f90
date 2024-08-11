PROGRAM testDCABS1
  COMPLEX*16 Z
  DOUBLE PRECISION DCABS1

  ! Test 1
  Z = (3.0d0, 4.0d0) ! A complex number where the real part is 3 and the imaginary part is 4
  PRINT *, 'DCABS1((3,4)) = ', DCABS1(Z) ! Expected output: 7

  ! Test 2
  Z = (-1.5d0, 2.5d0) ! A complex number where the real part is -1.5 and the imaginary part is 2.5
  PRINT *, 'DCABS1((-1.5,2.5)) = ', DCABS1(Z) ! Expected output: 4

  ! Test 3
  Z = (0.0d0, 0.0d0) ! A complex number where both parts are 0
  PRINT *, 'DCABS1((0,0)) = ', DCABS1(Z) ! Expected output: 0

END PROGRAM testDCABS1

DOUBLE PRECISION FUNCTION DCABS1(Z)
  COMPLEX*16 Z
  INTRINSIC ABS,DBLE,DIMAG

  DCABS1 = ABS(DBLE(Z)) + ABS(DIMAG(Z))
  RETURN
END