! Sss.f90
MODULE Sss
  IMPLICIT NONE
CONTAINS
  SUBROUTINE exampleSub()
    PRINT *, "This is an example subroutine within the module Sss."
  END SUBROUTINE exampleSub
END MODULE Sss

PROGRAM testSss
  USE Sss
  IMPLICIT NONE
  CALL exampleSub()
END PROGRAM testSss