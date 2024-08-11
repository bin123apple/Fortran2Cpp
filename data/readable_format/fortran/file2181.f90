MODULE hartree_variables
  IMPLICIT NONE
  PRIVATE
  PUBLIC :: E_hartree, Vh

  REAL(8) :: E_hartree
  REAL(8), ALLOCATABLE :: Vh(:)
END MODULE hartree_variables

PROGRAM test_hartree_variables
  USE hartree_variables
  IMPLICIT NONE

  E_hartree = 1.234d0
  ALLOCATE(Vh(5))
  Vh = (/ 1.1d0, 2.2d0, 3.3d0, 4.4d0, 5.5d0 /)

  ! Print the values for verification
  PRINT *, 'E_hartree = ', E_hartree
  PRINT *, 'Vh = ', Vh

  CALL test()

CONTAINS

  SUBROUTINE test()
    IMPLICIT NONE
    REAL(8) :: expected_Vh(5)

    expected_Vh = (/ 1.1d0, 2.2d0, 3.3d0, 4.4d0, 5.5d0 /)

    IF (ABS(E_hartree - 1.234d0) > 1.0d-12) THEN
       PRINT *, 'E_hartree test failed'
    ELSE
       PRINT *, 'E_hartree test passed'
    END IF

    IF (ALL(Vh == expected_Vh)) THEN
       PRINT *, 'Vh test passed'
    ELSE
       PRINT *, 'Vh test failed'
    END IF
  END SUBROUTINE test

END PROGRAM test_hartree_variables