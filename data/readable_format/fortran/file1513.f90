PROGRAM TEST_BSPARM
  IMPLICIT NONE
  
  ! Declarations for variables to be passed to BSPARM subroutine
  INTEGER :: MCALL, IT1, IT2
  DOUBLE PRECISION :: AC1, AC2

  ! Declarations for COMMON blocks
  INTEGER :: NDIM, NWILD, NCALL
  INTEGER :: ITMX1, ITMX2
  DOUBLE PRECISION :: ACC1, ACC2
  DOUBLE PRECISION :: XL(50), XU(50)
  INTEGER :: IG(50)

  ! Constants
  INTEGER, PARAMETER :: MXDIM = 50

  ! COMMON blocks
  COMMON /BPARM1/ XL, XU, NDIM, NWILD, IG, NCALL
  COMMON /BPARM2/ ACC1, ACC2, ITMX1, ITMX2

  ! Test values
  MCALL = 100
  AC1 = 0.01
  AC2 = 0.02
  IT1 = 10
  IT2 = 20

  ! Call the BSPARM subroutine with the test values
  CALL BSPARM(MCALL, AC1, AC2, IT1, IT2)

  ! Output the results for verification
  PRINT *, 'NCALL:', NCALL
  PRINT *, 'ACC1:', ACC1
  PRINT *, 'ACC2:', ACC2
  PRINT *, 'ITMX1:', ITMX1
  PRINT *, 'ITMX2:', ITMX2

  PRINT *, 'Test completed successfully'

END PROGRAM TEST_BSPARM

SUBROUTINE BSPARM(MCALL, AC1, AC2, IT1, IT2)
  IMPLICIT NONE
  
  ! External declarations for COMMON blocks
  INTEGER :: NDIM, NWILD, NCALL
  INTEGER :: ITMX1, ITMX2
  DOUBLE PRECISION :: ACC1, ACC2
  DOUBLE PRECISION :: XL(50), XU(50)
  INTEGER :: IG(50)
  
  ! Inputs to the subroutine
  INTEGER, INTENT(IN) :: MCALL, IT1, IT2
  DOUBLE PRECISION, INTENT(IN) :: AC1, AC2

  ! COMMON blocks
  COMMON /BPARM1/ XL, XU, NDIM, NWILD, IG, NCALL
  COMMON /BPARM2/ ACC1, ACC2, ITMX1, ITMX2

  ! Update values based on subroutine parameters
  NCALL = MCALL
  ACC1 = AC1
  ACC2 = AC2
  ITMX1 = IT1
  ITMX2 = IT2
END SUBROUTINE BSPARM