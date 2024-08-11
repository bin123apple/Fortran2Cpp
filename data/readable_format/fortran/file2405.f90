! dcovarxy.f90
program test_dcovarxy
    implicit none
    integer, parameter :: n = 5, m = 2
    integer :: lag, ncrit, iopt
    double precision :: xmsg, ymsg
    double precision, dimension(n, m) :: x, y
    double precision, dimension(m, m) :: cxy

    ! Initialize variables
    lag = 1
    ncrit = 1
    iopt = 0
    xmsg = -999.0
    ymsg = -999.0

    ! Initialize x and y with test data
    x = reshape([1.0, 2.0, 3.0, 4.0, 5.0, &
                 2.0, 3.0, 4.0, 5.0, 6.0], shape(x))
    y = reshape([5.0, 4.0, 3.0, 2.0, 1.0, &
                 6.0, 5.0, 4.0, 3.0, 2.0], shape(y))

    ! Call the subroutine
    call dcovarxy(x, y, xmsg, ymsg, cxy, n, m, lag, ncrit, iopt)

    ! Output the results
    print *, 'Fortran cxy:'
    print *, cxy

contains

    subroutine dcovarxy(x, y, xmsg, ymsg, cxy, n, m, lag, ncrit, iopt)
        implicit none
        integer :: n, m, lag, ncrit, iopt
        double precision, dimension(n, m) :: x, y
        double precision :: xmsg, ymsg
        double precision, dimension(m, m) :: cxy
        integer :: i, j, k
        double precision :: sumxx, sumyy, sumxy, sumx, sumy, nxy, xvar, yvar

        cxy = 0.0
        do i = 1, m
            do j = 1, m
                nxy = 0.0
                sumx = 0.0
                sumy = 0.0
                sumxy = 0.0
                sumxx = 0.0
                sumyy = 0.0

                do k = lag + 1, n
                    if (x(k, i) /= xmsg .and. y(k-lag, j) /= ymsg) then
                        nxy = nxy + 1
                        sumx = sumx + x(k, i)
                        sumy = sumy + y(k-lag, j)
                        sumxy = sumxy + x(k, i)*y(k-lag, j)
                        sumxx = sumxx + x(k, i)*x(k, i)
                        sumyy = sumyy + y(k-lag, j)*y(k-lag, j)
                    end if
                end do

                if (nxy >= ncrit) then
                    cxy(i, j) = (sumxy - (sumx*sumy)/nxy) / (nxy - 1.0)

                    if (iopt == 1) then
                        xvar = (sumxx - (sumx*sumx)/nxy) / (nxy - 1.0)
                        yvar = (sumyy - (sumy*sumy)/nxy) / (nxy - 1.0)
                        cxy(i, j) = cxy(i, j) / (sqrt(xvar)*sqrt(yvar))
                    end if
                else
                    cxy(i, j) = xmsg
                end if
            end do
        end do
    end subroutine

end program