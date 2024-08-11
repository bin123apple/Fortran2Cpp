! Define the subroutine
SUBROUTINE TDLBLP (AXIS,VLBL,PLBL)
    CHARACTER*1 AXIS
    CHARACTER*20 VLBL, PLBL
    PLBL = VLBL
END SUBROUTINE TDLBLP

! Test program for the subroutine
PROGRAM testTDLBLP
    IMPLICIT NONE
    CHARACTER*1 AXIS
    CHARACTER*20 VLBL, PLBL

    ! Test case 1: AXIS = 'U'
    AXIS = 'U'
    VLBL = 'Test Label'
    CALL TDLBLP(AXIS, VLBL, PLBL)
    PRINT *, "Test 1 - Expected: Test Label, Got: ", PLBL

    ! Test case 2: AXIS = 'X' (not U, V, or W)
    AXIS = 'X'
    VLBL = 'Another Label'
    CALL TDLBLP(AXIS, VLBL, PLBL)
    PRINT *, "Test 2 - Expected: Another Label, Got: ", PLBL

    ! Add more tests as necessary
END PROGRAM testTDLBLP