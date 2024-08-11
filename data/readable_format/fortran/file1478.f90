! finish.f90
PROGRAM testFinish
    CALL FINISH
END PROGRAM testFinish

SUBROUTINE FINISH
    PRINT *, "This program will halt."
    STOP
END SUBROUTINE FINISH