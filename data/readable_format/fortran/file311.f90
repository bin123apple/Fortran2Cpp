PROGRAM TestAveVar
    IMPLICIT NONE
    REAL*8, ALLOCATABLE :: data(:), data2(:)
    REAL*8 ave, var
    INTEGER n

    ! Initialize test data
    n = 5
    ALLOCATE(data(n))
    ALLOCATE(data2(n))
    data = (/1.0, 2.0, 3.0, 4.0, 5.0/)

    ! Test avevar subroutine
    CALL avevar(data, n, ave, var)
    PRINT *, "Test avevar"
    PRINT *, "Average:", ave
    PRINT *, "Variance:", var

    ! Test avevar2 subroutine
    CALL avevar2(data, data2, n, ave, var)
    PRINT *, "Test avevar2"
    PRINT *, "Average:", ave
    PRINT *, "Variance:", var
    PRINT *, "Filtered Data (n <= 3*std):"
    DO n = 1, SIZE(data2)
        IF (data2(n) /= 0.0) THEN
            PRINT *, data2(n)
        END IF
    END DO

    DEALLOCATE(data)
    DEALLOCATE(data2)
END PROGRAM TestAveVar

SUBROUTINE avevar(data,n,ave,var)
    IMPLICIT NONE
    INTEGER :: n,m
    REAL*8 :: ave,var,data(n)
    INTEGER :: j
    REAL*8 :: s,ep
    ave=0.0
    m=MIN(1000,n)
    DO j=1,m
        ave=ave+data(j)
    END DO
    ave=ave/m
    var=0.0
    ep=0.0
    DO j=1,n
        s=data(j)-ave
        ep=ep+s
        var=var+s*s
    END DO
    var=(var-ep**2/n)/(n-1)
END SUBROUTINE avevar

SUBROUTINE avevar2(data,data2,n,ave,var)
    IMPLICIT NONE
    INTEGER :: n,m,n2
    REAL*8 :: ave,var,data(n),std,data2(n)
    INTEGER :: j
    REAL*8 :: s,ep
    var=0.0
    ep=0.0
    DO j=1,n
        s=data(j)-ave
        ep=ep+s
        var=var+s*s
    END DO
    var=(var-ep**2/n)/(n-1)
    std=SQRT(var)

    DO WHILE (.TRUE.)
        n2=0
        DO j=1,n
            IF(ABS(data(j)-ave)<3.0*std) THEN
                n2=n2+1
                data2(n2)=data(j)
            END IF
        END DO

        EXIT
    END DO

    var=0.0
    ep=0.0
    DO j=1,n2
        s=data2(j)-ave
        ep=ep+s
        var=var+s*s
    END DO
    var=(var-ep**2/n2)/(n2-1)
END SUBROUTINE avevar2