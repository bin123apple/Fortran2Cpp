PROGRAM TestSplintd
    IMPLICIT NONE
    INTEGER, PARAMETER :: n = 4
    REAL*4 :: xa(n), ya(n), y2a(n), x, y

    ! Initialize the arrays
    xa = (/0.0, 1.0, 2.0, 3.0/)
    ya = (/0.0, 1.0, 4.0, 9.0/)
    y2a = (/0.0, 0.5, 1.0, 1.5/)
    x = 1.5

    ! Call the subroutine
    CALL splintd(xa, ya, y2a, n, x, y)

    ! Print the result
    PRINT*, 'Interpolated value at x = ', x, ' is y = ', y

END PROGRAM TestSplintd

SUBROUTINE splintd(xa, ya, y2a, n, x, y)
    INTEGER n
    REAL*4 x, y, xa(n), y2a(n), ya(n)
    INTEGER k, khi, klo
    REAL*4 a, b, h
    DATA klo, khi /1, 1/
    SAVE khi, klo

    IF (khi .LE. n) THEN
        IF (xa(khi) .GT. x .AND. xa(klo) .LT. x .AND. khi - klo .EQ. 1) THEN
            GOTO 2
        END IF
    END IF

    klo = 1
    khi = n
1   IF (khi - klo .GT. 1) THEN
        k = (khi + klo) / 2
        IF (xa(k) .GT. x) THEN
            khi = k
        ELSE
            klo = k
        END IF
        GOTO 1
    END IF

2   h = xa(khi) - xa(klo)
    IF (h .LE. 0.0) PAUSE 'bad xa input in splint'
    a = (xa(khi) - x) / h
    b = (x - xa(klo)) / h
    y = a * ya(klo) + b * ya(khi) + ((a**3 - a) * y2a(klo) + (b**3 - b) * y2a(khi)) * (h**2) / 6.0
    RETURN
END SUBROUTINE splintd