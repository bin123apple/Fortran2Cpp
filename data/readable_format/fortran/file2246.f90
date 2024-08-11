PROGRAM TestIntAdd
    IMPLICIT NONE
    INTEGER :: result
    INTEGER, DIMENSION(5) :: intLst = (/ 1, 2, 3, 4, 5 /)

    INTERFACE
        INTEGER FUNCTION INTADD(LENLST, INTLST)
            INTEGER, INTENT(IN) :: LENLST
            INTEGER, INTENT(IN) :: INTLST(*)
        END FUNCTION INTADD
    END INTERFACE

    result = INTADD(SIZE(intLst), intLst)
    PRINT *, 'The sum of the elements is: ', result

    IF (result == 15) THEN
        PRINT *, 'Test passed.'
    ELSE
        PRINT *, 'Test failed.'
    END IF
END PROGRAM TestIntAdd

INTEGER FUNCTION INTADD(LENLST, INTLST)
    INTEGER, INTENT(IN) :: LENLST
    INTEGER, INTENT(IN) :: INTLST(*)

    INTADD = 0
    DO I = 1, LENLST
        INTADD = INTADD + INTLST(I)
    END DO

    RETURN
END FUNCTION INTADD