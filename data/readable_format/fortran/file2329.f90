program test_b4step2
    implicit none

    integer, parameter :: mbc = 2, mx = 100, my = 100, meqn = 5, maux = 15
    real(kind=8) :: xlower, ylower, dx, dy, t, dt
    real(kind=8) :: q(meqn, 1-mbc:mx+mbc, 1-mbc:my+mbc)
    real(kind=8) :: aux(maux, 1-mbc:mx+mbc, 1-mbc:my+mbc)
    integer :: i, j, k

    ! Initialize variables
    xlower = 0.0_8
    ylower = 0.0_8
    dx = 0.1_8
    dy = 0.1_8
    t = 1.5_8
    dt = 0.01_8

    ! Initialize q and aux arrays
    q = 0.0_8
    aux = 1.0_8

    ! Call the subroutine
    call b4step2(mbc, mx, my, meqn, q, xlower, ylower, dx, dy, t, dt, maux, aux)

    ! Check the result
    do k = 1, maux
        do j = 1-mbc, my+mbc
            do i = 1-mbc, mx+mbc
                if (k == 13) then
                    if (aux(k, i, j) /= 0.0_8) then
                        print *, "Test failed"
                        stop
                    endif
                endif
            enddo
        enddo
    enddo

    print *, "Test passed"

contains

    subroutine b4step2(mbc, mx, my, meqn, q, xlower, ylower, dx, dy, t, dt, maux, aux)
        implicit none
        integer, intent(in) :: mbc, mx, my, meqn, maux
        real(kind=8), intent(in) :: xlower, ylower, dx, dy, t, dt
        real(kind=8), intent(inout) :: q(meqn, 1-mbc:mx+mbc, 1-mbc:my+mbc)
        real(kind=8), intent(inout) :: aux(maux, 1-mbc:mx+mbc, 1-mbc:my+mbc)

        if (t > 1.d0) then
            aux(13, :, :) = 0.d0
        endif
    end subroutine b4step2

end program test_b4step2