! Assuming the original subroutines are in 'subroutines.f90', 
! but for demonstration, dummy subroutines are defined within this file.

PROGRAM test_subroutines
    CALL test_SETUP()
    CALL test_CLEAR()
    CALL test_GMODE()
    CALL test_TMODE()
    
    PRINT *, 'All tests completed.'
END PROGRAM test_subroutines

SUBROUTINE SETUP
    PRINT *, 'SETUP called'
END SUBROUTINE SETUP

SUBROUTINE CLEAR
    PRINT *, 'CLEAR called'
END SUBROUTINE CLEAR

SUBROUTINE GMODE
    PRINT *, 'GMODE called'
END SUBROUTINE GMODE

SUBROUTINE TMODE
    PRINT *, 'TMODE called'
END SUBROUTINE TMODE

SUBROUTINE test_SETUP
    CALL SETUP()
    ! Replace the following print statement with actual test conditions as needed.
    PRINT *, 'SETUP test passed.'
END SUBROUTINE test_SETUP

SUBROUTINE test_CLEAR
    CALL CLEAR()
    ! Replace the following print statement with actual test conditions as needed.
    PRINT *, 'CLEAR test passed.'
END SUBROUTINE test_CLEAR

SUBROUTINE test_GMODE
    CALL GMODE()
    ! Replace the following print statement with actual test conditions as needed.
    PRINT *, 'GMODE test passed.'
END SUBROUTINE test_GMODE

SUBROUTINE test_TMODE
    CALL TMODE()
    ! Replace the following print statement with actual test conditions as needed.
    PRINT *, 'TMODE test passed.'
END SUBROUTINE test_TMODE