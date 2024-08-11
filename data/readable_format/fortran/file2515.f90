MODULE datin_I   
    INTERFACE
        SUBROUTINE datin () 
        END SUBROUTINE  
    END INTERFACE 
END MODULE

SUBROUTINE datin()
    PRINT *, 'datin subroutine called'
END SUBROUTINE datin

PROGRAM test_datin
    USE datin_I
    IMPLICIT NONE

    CALL datin()

END PROGRAM test_datin