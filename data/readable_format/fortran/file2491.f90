MODULE XDLAISNAN_MOD
  IMPLICIT NONE
CONTAINS
  LOGICAL FUNCTION XDLAISNAN(DIN1, DIN2)
    DOUBLE PRECISION, INTENT(IN) :: DIN1, DIN2
    XDLAISNAN = DIN1 .NE. DIN2
  END FUNCTION XDLAISNAN
END MODULE XDLAISNAN_MOD

PROGRAM TestXDLAISNAN
  USE XDLAISNAN_MOD
  IMPLICIT NONE
  DOUBLE PRECISION :: a, b

  ! Test case 1: a and b are equal
  a = 1.0
  b = 1.0
  WRITE(*,*) 'Test case 1: ', XDLAISNAN(a, b)  ! Expected output: F

  ! Test case 2: a and b are different
  a = 1.0
  b = 2.0
  WRITE(*,*) 'Test case 2: ', XDLAISNAN(a, b)  ! Expected output: T
END PROGRAM TestXDLAISNAN