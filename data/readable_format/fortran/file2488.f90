PROGRAM MAIN
    INTEGER, DIMENSION(3), VOLATILE :: a
    INTEGER :: b
    EQUIVALENCE (a(1), b)
    
    ! Initialize array
    a(1) = 10
    a(2) = 20
    a(3) = 30
    
    ! Print values to verify equivalence
    PRINT *, "a(1):", a(1)
    PRINT *, "a(2):", a(2)
    PRINT *, "a(3):", a(3)
    PRINT *, "b:", b
    
    ! Check if b is equal to a(1)
    IF (b == a(1)) THEN
        PRINT *, "Test Passed"
    ELSE
        PRINT *, "Test Failed"
    END IF
END PROGRAM MAIN