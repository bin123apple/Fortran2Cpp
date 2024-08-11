program test_exact
    implicit none

    integer, parameter :: nx0 = 10, ny0 = 10, nz = 10
    double precision :: ce(5,13)
    integer :: i, j, k
    double precision :: u000ijk(5)
    double precision :: expected(5)
    integer :: m

    ! Initialize ce array with some test values
    do m = 1, 5
        ce(m, 1:13) = [m*1.0d0, m+0.1d0, m+0.2d0, m+0.3d0, m+0.4d0, &
                       m+0.5d0, m+0.6d0, m+0.7d0, m+0.8d0, m+0.9d0, &
                       m+1.0d0, m+1.1d0, m+1.2d0]
    end do

    ! Initialize test values for i, j, k
    i = 2
    j = 2
    k = 2

    ! Call the subroutine
    call exact(i, j, k, u000ijk)

    ! Expected values
    do m = 1, 5
        expected(m) = ce(m,1) + &
             ce(m,2) * (dble(i-1) / (nx0-1)) + &
             ce(m,3) * (dble(j-1) / (ny0-1)) + &
             ce(m,4) * (dble(k-1) / (nz-1)) + &
             ce(m,5) * (dble(i-1) / (nx0-1))**2 + &
             ce(m,6) * (dble(j-1) / (ny0-1))**2 + &
             ce(m,7) * (dble(k-1) / (nz-1))**2 + &
             ce(m,8) * (dble(i-1) / (nx0-1))**3 + &
             ce(m,9) * (dble(j-1) / (ny0-1))**3 + &
             ce(m,10) * (dble(k-1) / (nz-1))**3 + &
             ce(m,11) * (dble(i-1) / (nx0-1))**4 + &
             ce(m,12) * (dble(j-1) / (ny0-1))**4 + &
             ce(m,13) * (dble(k-1) / (nz-1))**4
    end do

    ! Compare the computed values with expected values
    do m = 1, 5
        if (abs(u000ijk(m) - expected(m)) > 1.0e-12) then
            print *, "Test failed for index ", m
            print *, "Expected value: ", expected(m)
            print *, "Computed value: ", u000ijk(m)
            stop
        end if
    end do

    print *, "All tests passed!"

contains

    subroutine exact(i, j, k, u000ijk)
        integer :: i, j, k
        double precision :: u000ijk(5)
        integer :: m
        double precision :: xi, eta, zeta

        xi = (dble(i - 1)) / (nx0 - 1)
        eta = (dble(j - 1)) / (ny0 - 1)
        zeta = (dble(k - 1)) / (nz - 1)

        do m = 1, 5
            u000ijk(m) = ce(m, 1) + &
                 ce(m, 2) * xi + &
                 ce(m, 3) * eta + &
                 ce(m, 4) * zeta + &
                 ce(m, 5) * xi**2 + &
                 ce(m, 6) * eta**2 + &
                 ce(m, 7) * zeta**2 + &
                 ce(m, 8) * xi**3 + &
                 ce(m, 9) * eta**3 + &
                 ce(m, 10) * zeta**3 + &
                 ce(m, 11) * xi**4 + &
                 ce(m, 12) * eta**4 + &
                 ce(m, 13) * zeta**4
        end do
    end subroutine exact

end program test_exact