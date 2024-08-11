! Corrected Fortran unit test code
MODULE kind_module
     
  IMPLICIT NONE 

  INTEGER, PARAMETER :: single = SELECTED_REAL_KIND(p=6, r=37)
  INTEGER, PARAMETER :: double = SELECTED_REAL_KIND(p=15, r=307)
  INTEGER, PARAMETER :: prec = double

  INTEGER, PARAMETER :: cSingle = KIND(1.0_single)
  INTEGER, PARAMETER :: cDouble = KIND(1.0_double)
  INTEGER, PARAMETER :: cPrec = cDouble
         
END MODULE kind_module

PROGRAM testKind
  USE kind_module
  IMPLICIT NONE

  ! Variables for testing
  REAL(KIND=cSingle) :: singleVar
  REAL(KIND=cDouble) :: doubleVar
  REAL(KIND=cPrec)   :: precVar

  ! Test and display the kinds and precision
  PRINT *, "Single precision kind:", cSingle
  PRINT *, "Double precision kind:", cDouble
  PRINT *, "Chosen precision kind (cPrec):", cPrec

  ! Initializing variables
  singleVar = 1.0_single
  doubleVar = 1.0_double
  precVar = 1.0_prec

  ! Display the values to verify correctness
  PRINT *, "Single variable:", singleVar
  PRINT *, "Double variable:", doubleVar
  PRINT *, "Precision variable (using cPrec):", precVar

END PROGRAM testKind