MODULE m0
    INTERFACE operator(.hoge.)
       MODULE PROCEDURE HOGE
    END INTERFACE
  CONTAINS
    FUNCTION hoge(a,b)
      INTEGER,INTENT(IN) :: a,b
      COMPLEX :: hoge
      hoge = CMPLX(b,a)
    END FUNCTION HOGE
END MODULE m0

PROGRAM MAIN
    USE m0
    IMPLICIT NONE
    COMPLEX :: c

    c = 5 .hoge. 4
    PRINT *, "Test 1, c = 5 .hoge. 4: ", c

    c = 5 .HOGE. 4
    PRINT *, "Test 2, c = 5 .HOGE. 4: ", c

    c = 5 . hOgE . 4
    PRINT *, "Test 3, c = 5 . hOgE . 4: ", c

    CALL TestHoge()
CONTAINS
    SUBROUTINE TestHoge()
        COMPLEX :: result
        result = 5 .hoge. 4
        IF (REAL(result) == 4 .AND. AIMAG(result) == 5) THEN
            PRINT *, "Unit Test passed: (5 .hoge. 4) = ", result
        ELSE
            PRINT *, "Unit Test failed: (5 .hoge. 4) = ", result
        END IF
    END SUBROUTINE TestHoge
END PROGRAM MAIN