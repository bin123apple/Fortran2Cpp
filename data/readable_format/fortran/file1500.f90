! GLQGridCoordTest.f90
program GLQGridCoordTest
    implicit none
    integer, parameter :: dp = kind(1.0d0)
    integer :: lmax, nlat, nlong, i
    real(dp), allocatable :: latglq(:), longlq(:)

    ! Test for different values of lmax
    do lmax = 2, 5
        call TestGLQGridCoord(lmax)
    end do

contains

    subroutine TestGLQGridCoord(lmax)
        integer, intent(in) :: lmax
        integer :: nlat, nlong, i
        real(dp), allocatable :: latglq(:), longlq(:)

        nlat = lmax + 1
        nlong = 2 * lmax + 1
        allocate(latglq(nlat), longlq(nlong))

        call CalculateGLQGridCoord(latglq, longlq, lmax, nlat, nlong)

        print *, "Test passed for lmax = ", lmax

        deallocate(latglq, longlq)
    end subroutine TestGLQGridCoord

    subroutine CalculateGLQGridCoord(latglq, longlq, lmax, nlat, nlong)
        real(dp), intent(out) :: latglq(:), longlq(:)
        integer, intent(in) :: lmax, nlat, nlong
        real(dp) :: pi = acos(-1.0_dp)
        integer :: i

        do i = 1, nlat
            latglq(i) = -90.0_dp + (i - 1) * 180.0_dp / (nlat - 1)
        end do

        do i = 1, nlong
            longlq(i) = (i - 1) * 360.0_dp / nlong
        end do
    end subroutine CalculateGLQGridCoord

end program GLQGridCoordTest