SUBROUTINE FOO (K)
    INTEGER I, J, K, A(5,5), B
    COMMON A
    A(1,1) = 1
10  B = 0
    DO 30 I = 1, K
        DO 20 J = 1, K
            B = B + A(I,J)
20      CONTINUE
        A(I,I) = A(I,I) * 2
30  CONTINUE
    IF (B.GE.3) RETURN
    GO TO 10
END SUBROUTINE

PROGRAM BAR
    INTEGER A(5,5)
    COMMON A
    CALL FOO (2)

    ! Check if A(1,1) is 8
    IF (A(1,1).NE.8) THEN
        PRINT *, 'Test failed: A(1,1) is not 8'
        CALL ABORT
    END IF

    ! Set A(1,1) to 0
    A(1,1) = 0

    ! Check if all elements of A are zero
    IF (ANY(A.NE.0)) THEN
        PRINT *, 'Test failed: Not all elements of A are zero'
        CALL ABORT
    END IF

    PRINT *, 'All tests passed!'
END PROGRAM

SUBROUTINE ABORT
    PRINT *, 'Abort called!'
    STOP
END SUBROUTINE