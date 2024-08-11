MODULE types_module
  IMPLICIT NONE
  PUBLIC :: T, S

  TYPE :: T
    INTEGER :: A(2) = [1, 2]
  END TYPE T

  TYPE :: S
    INTEGER :: B = 1
  END TYPE S

END MODULE types_module

PROGRAM test_program
  USE types_module
  IMPLICIT NONE

  CALL test_T()
  CALL test_S()

CONTAINS

  SUBROUTINE test_T()
    TYPE(T) :: testInstance
    IF (testInstance%A(1) == 1 .AND. testInstance%A(2) == 2) THEN
      PRINT *, "Test for T passed."
    ELSE
      PRINT *, "Test for T failed."
    END IF
  END SUBROUTINE test_T

  SUBROUTINE test_S()
    TYPE(S) :: testInstance
    IF (testInstance%B == 1) THEN
      PRINT *, "Test for S passed."
    ELSE
      PRINT *, "Test for S failed."
    END IF
  END SUBROUTINE test_S

END PROGRAM test_program