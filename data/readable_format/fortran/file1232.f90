PROGRAM test
    IMPLICIT NONE
    
    CALL S('Short')
    CALL S('ExactTenLen')
    CALL S('ThisStringIsLongerThanTen')
END PROGRAM test

SUBROUTINE S(C)
    IMPLICIT NONE
    CHARACTER(len=*) :: C
    PRINT *, C
END SUBROUTINE S