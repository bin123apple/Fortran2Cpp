PROGRAM TestA17_1_WRONG
    CALL A17_1_WRONG()
END PROGRAM TestA17_1_WRONG

SUBROUTINE A17_1_WRONG()
    INTEGER:: I = 0 ! Initialize I to ensure a known starting state
    REAL:: R
    EQUIVALENCE(I,R)
    I = I + 1
    R = R + 1.0
    PRINT *, 'After integer increment, I =', I
    PRINT *, 'After float increment, R =', R
END SUBROUTINE A17_1_WRONG