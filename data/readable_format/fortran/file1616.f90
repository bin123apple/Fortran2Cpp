MODULE workmod
    INTEGER :: counter = 0
CONTAINS
    SUBROUTINE work(i, j)
        INTEGER, INTENT(IN) :: i, j
        counter = counter + 1
    END SUBROUTINE work

    SUBROUTINE wrong1(n)
        INTEGER, INTENT(IN) :: n
        INTEGER :: i, j
        DO i = 1, n
            DO j = 1, n
                CALL work(i,j)
            END DO
        END DO
    END SUBROUTINE wrong1

    SUBROUTINE resetCounter()
        counter = 0
    END SUBROUTINE resetCounter

    FUNCTION getCounter() RESULT(cnt)
        INTEGER :: cnt
        cnt = counter
    END FUNCTION getCounter
END MODULE workmod

PROGRAM testWorkWrong1
    USE workmod
    INTEGER :: n, expected, result

    CALL resetCounter()
    n = 5
    expected = n*n
    CALL wrong1(n)
    result = getCounter()

    IF (result == expected) THEN
        PRINT *, 'Fortran Test passed. Counter:', result
    ELSE
        PRINT *, 'Fortran Test failed. Counter:', result
    END IF
END PROGRAM testWorkWrong1