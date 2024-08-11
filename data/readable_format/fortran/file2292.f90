MODULE mod
  CONTAINS
    SUBROUTINE three()
      CALL two()
    END SUBROUTINE three

    SUBROUTINE four()
      CALL one()
    END SUBROUTINE four
END MODULE mod

SUBROUTINE one()
END SUBROUTINE one

SUBROUTINE two()
END SUBROUTINE two

PROGRAM test_mod
  USE mod
  IMPLICIT NONE

  CALL three()
  CALL four()

END PROGRAM test_mod