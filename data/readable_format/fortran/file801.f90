! Define the cor subroutine
subroutine cor(n, x, y, output)

    integer n
    double precision x(n), y(n)

    double precision:: output
    double precision:: sxx, sxy, syy, xsum, ysum, xysum, x2sum, y2sum, rn

    sxx   = 0.0
    sxy   = 0.0
    syy   = 0.0
    xsum  = 0.0
    ysum  = 0.0
    xysum = 0.0
    x2sum = 0.0
    y2sum = 0.0
    rn    = dfloat(n)

    do 20 i = 1,n
         xsum = xsum + x(i)
         ysum = ysum + y(i)
         xysum = xysum + (x(i) * y(i))
20   continue

    do 30 i = 1,n
         x2sum = x2sum + x(i) * x(i)
         y2sum = y2sum + y(i) * y(i)
30   continue
    xsum2 = xsum * xsum
    ysum2 = ysum * ysum

    cornum = xysum - ((xsum * ysum) / rn)
    corden = sqrt ((x2sum - (xsum2 / rn)) * (y2sum - (ysum2 / rn)))
    output = cornum / corden
    return
end subroutine cor

! Main program to test the cor subroutine
program test_cor
    implicit none
    double precision, allocatable :: x(:), y(:)
    double precision :: output
    integer :: n

    ! Example input
    n = 5
    allocate(x(n), y(n))

    x = (/1.0, 2.0, 3.0, 4.0, 5.0/)
    y = (/2.0, 4.0, 5.0, 6.0, 7.0/)

    call cor(n, x, y, output)

    print *, "Correlation: ", output

    deallocate(x, y)
end program test_cor