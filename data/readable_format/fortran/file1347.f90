module clawpack46_module
    implicit none
contains

    subroutine clawpack46_setaux(mbc, mx, my, mz, xlower, ylower, zlower, dx, dy, dz, maux, aux)
        integer :: mbc, mx, my, mz, maux
        double precision :: xlower, ylower, zlower, dx, dy, dz
        double precision, dimension(1-mbc:mx+mbc, 1-mbc:my+mbc, 1-mbc:mz+mbc, maux) :: aux
        integer :: i, j, k, l

        ! Initialize the aux array with some values for testing
        do i = 1-mbc, mx+mbc
            do j = 1-mbc, my+mbc
                do k = 1-mbc, mz+mbc
                    do l = 1, maux
                        aux(i, j, k, l) = i + j + k + l
                    end do
                end do
            end do
        end do
    end subroutine clawpack46_setaux

end module clawpack46_module

program test_clawpack46
    use clawpack46_module
    implicit none
    
    integer :: mbc, mx, my, mz, maux
    double precision :: xlower, ylower, zlower, dx, dy, dz
    double precision, allocatable :: aux(:,:,:,:)

    ! Initialize parameters for the test
    mbc = 1
    mx = 10
    my = 10
    mz = 10
    maux = 5
    xlower = 0.0
    ylower = 0.0
    zlower = 0.0
    dx = 1.0
    dy = 1.0
    dz = 1.0

    ! Allocate the aux array
    allocate(aux(1-mbc:mx+mbc, 1-mbc:my+mbc, 1-mbc:mz+mbc, maux))

    ! Call the subroutine
    call clawpack46_setaux(mbc, mx, my, mz, xlower, ylower, zlower, dx, dy, dz, maux, aux)

    ! Example check: Print the value of a specific element to verify correctness
    print *, "Value at (1,1,1,1): ", aux(1,1,1,1)

    ! Deallocate the aux array
    deallocate(aux)
    
end program test_clawpack46