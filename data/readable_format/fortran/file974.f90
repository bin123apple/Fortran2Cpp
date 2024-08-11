PROGRAM test
  IMPLICIT NONE
  
  CALL testArrayInitialization()
  CALL testCharacterArrayInitialization()
  PRINT *, 'All tests passed.'
  
CONTAINS

  SUBROUTINE testArrayInitialization()
    INTEGER(KIND=8) :: arr(3)
    arr = (/ 4_8, 42_8, 12_8 /)
    IF (arr(1) /= 4 .OR. arr(2) /= 42 .OR. arr(3) /= 12) CALL abort()
    
    ! Additional tests for array initialization could go here
  END SUBROUTINE testArrayInitialization
  
  SUBROUTINE testCharacterArrayInitialization()
    CHARACTER(len=6) :: carr(3)
    carr(1) = "foo   " ! Adjusted for len=6
    carr(2) = "foob  " ! Adjusted for len=6, "foob" followed by two spaces
    carr(3) = "xyz   " ! Adjusted for len=6
    IF (carr(1) /= "foo   " .OR. carr(2) /= "foob  " .OR. carr(3) /= "xyz   ") THEN
      CALL abort()
    END IF
    
    ! Additional tests for character array initialization could go here
  END SUBROUTINE testCharacterArrayInitialization

END PROGRAM test