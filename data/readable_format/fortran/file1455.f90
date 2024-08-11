PROGRAM fptest
  IMPLICIT NONE
  CHARACTER (LEN=*), DIMENSION(1),  PARAMETER :: var  = 'a'
  CALL run_tests()
CONTAINS
  SUBROUTINE parsef (Var)
    IMPLICIT NONE
    CHARACTER (LEN=*), DIMENSION(:), INTENT(in) :: Var
    PRINT *, Var
  END SUBROUTINE parsef

  SUBROUTINE run_tests()
    CHARACTER (LEN=1), DIMENSION(1) :: testVar1
    CHARACTER (LEN=1), DIMENSION(2) :: testVar2
    
    ! Test 1
    testVar1 = 'b'
    CALL parsef(testVar1)

    ! Test 2
    testVar2 = (/ 'c', 'd' /)
    CALL parsef(testVar2)
  END SUBROUTINE run_tests
END PROGRAM fptest