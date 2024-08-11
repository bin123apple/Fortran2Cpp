MODULE DataShadowingCombinations

  IMPLICIT NONE

  PUBLIC

  TYPE ShadowingCombinations
    LOGICAL :: UseThisSurf = .FALSE.
    INTEGER :: NumGenSurf = 0
    INTEGER, ALLOCATABLE, DIMENSION(:) :: GenSurf
    INTEGER :: NumBackSurf = 0
    INTEGER, ALLOCATABLE, DIMENSION(:) :: BackSurf
    INTEGER :: NumSubSurf = 0
    INTEGER, ALLOCATABLE, DIMENSION(:) :: SubSurf
  END TYPE ShadowingCombinations

  TYPE (ShadowingCombinations), ALLOCATABLE, DIMENSION(:) :: ShadowComb

END MODULE DataShadowingCombinations

PROGRAM TestShadowingCombinations
  USE DataShadowingCombinations
  IMPLICIT NONE

  TYPE(ShadowingCombinations) :: testComb

  ! Allocate arrays for testComb
  ALLOCATE(testComb%GenSurf(3))
  ALLOCATE(testComb%BackSurf(2))
  ALLOCATE(testComb%SubSurf(4))

  ! Test initial values
  IF (.NOT. testComb%UseThisSurf) THEN
    PRINT *, "UseThisSurf initialized correctly."
  ELSE
    PRINT *, "Error in UseThisSurf initialization."
  END IF

  IF (testComb%NumGenSurf == 0) THEN
    PRINT *, "NumGenSurf initialized correctly."
  ELSE
    PRINT *, "Error in NumGenSurf initialization."
  END IF

  ! Test dynamic array functionality by assigning values
  testComb%GenSurf = (/1, 2, 3/)
  testComb%BackSurf = (/4, 5/)
  testComb%SubSurf = (/6, 7, 8, 9/)

  IF (ALL(testComb%GenSurf == (/1, 2, 3/))) THEN
    PRINT *, "GenSurf works correctly."
  ELSE
    PRINT *, "Error in GenSurf functionality."
  END IF

  ! Similarly, add further tests for BackSurf and SubSurf as needed

END PROGRAM TestShadowingCombinations