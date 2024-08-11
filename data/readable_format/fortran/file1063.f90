MODULE mecip_I
CONTAINS
    SUBROUTINE mecip()
        PRINT *, "Executing mecip subroutine."
    END SUBROUTINE mecip
END MODULE mecip_I

PROGRAM main
    USE mecip_I
    CALL mecip()
END PROGRAM main