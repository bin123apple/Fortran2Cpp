PROGRAM testSCABS1
  REAL, EXTERNAL :: SCABS1
  COMPLEX :: Z
  REAL :: result

  ! Test case 1
  Z = CMPLX(3.0, 4.0)
  result = SCABS1(Z)
  PRINT *, "Test case 1: (3,4) - Expected: 7, Got:", result

  ! Test case 2
  Z = CMPLX(-1.5, 2.5)
  result = SCABS1(Z)
  PRINT *, "Test case 2: (-1.5,2.5) - Expected: 4, Got:", result

  ! Add more test cases as needed
END PROGRAM testSCABS1

REAL FUNCTION SCABS1(Z)
  COMPLEX Z
  INTRINSIC ABS,AIMAG,REAL
  SCABS1 = ABS(REAL(Z)) + ABS(AIMAG(Z))
  RETURN
END