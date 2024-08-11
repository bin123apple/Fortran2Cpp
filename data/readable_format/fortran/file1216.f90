PROGRAM testLoop23
    INTEGER, PARAMETER :: N = 5
    REAL*8 :: x(N), a(N), b(N), c(N), d(N), y(N)
    INTEGER :: i

    ! Initialize arrays
    DO i = 1, N
        a(i) = i * 1.0
        b(i) = i * 2.0
        c(i) = i * 3.0
        d(i) = i * 4.0
    END DO

    ! Call the subroutine
    CALL loop23_F77(N, x, a, b, c, d, y)

    ! Print results
    PRINT *, "x = ", x
    PRINT *, "y = ", y

    ! Call the overhead subroutine
    CALL loop23_F77Overhead(N, x, a, b, c, d, y)

END PROGRAM testLoop23


SUBROUTINE loop23_F77(N, x, a, b, c, d, y)
    INTEGER i, N
    REAL*8 x(N), a(N), b(N), c(N), d(N), y(N)

    DO i=1,N
        x(i)=a(i)*b(i)+c(i)*d(i)
        y(i)=b(i)+d(i)
    END DO
    RETURN
END


SUBROUTINE loop23_F77Overhead(N, x, a, b, c, d, y)
    INTEGER i, N
    REAL*8 x(N), a(N), b(N), c(N), d(N), y(N)
    ! This subroutine intentionally does nothing
    RETURN
END