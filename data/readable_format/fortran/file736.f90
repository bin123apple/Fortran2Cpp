PROGRAM testFind
    IMPLICIT NONE
    INTEGER :: ibuffer(5), ib, nini, ntot, ip, iat

    ! Initialize the buffer and other variables
    ibuffer = (/1, 2, 3, 2, 1/)
    ib = 2
    nini = 1
    ntot = 5
    ip = 2
    iat = 0

    ! Call the FIND subroutine
    CALL FIND(ibuffer, ib, nini, ntot, ip, iat)

    ! Check the result
    IF (iat == 5) THEN
        PRINT *, "Test passed: iat is 5 as expected."
    ELSE
        PRINT *, "Test failed: iat is not 5."
    END IF
END PROGRAM testFind

SUBROUTINE FIND(ibuffer, ib, nini, ntot, ip, iat)
    IMPLICIT NONE
    INTEGER, INTENT(IN) :: ibuffer(*), ib, nini, ntot, ip
    INTEGER, INTENT(OUT) :: iat
    INTEGER :: ipx, i

    ipx = 0
    iat = 0
    DO i = nini+1, ntot
        IF (ibuffer(i) == ib) THEN
            ipx = ipx + 1
            IF (ip == ipx) THEN
                iat = i
                RETURN
            END IF
        END IF
    END DO
END SUBROUTINE FIND