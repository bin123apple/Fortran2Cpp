module SchmidtModule
    implicit none
    contains

    subroutine PlSchmidt(p, lmax, z, exitstatus)
        implicit none
        integer, intent(in) :: lmax
        real(8), intent(out) :: p(:)
        real(8), intent(in) :: z
        integer, intent(out), optional :: exitstatus
        real(8) :: pm2, pm1, pl
        integer :: l

        ! Initialize exit status
        if (present(exitstatus)) exitstatus = 0

        ! Error handling
        if (lmax < 0) then
            print*, "Error --- PlSchmidt"
            print*, "LMAX must be greater than or equal to 0."
            print*, "Input value is ", lmax
            if (present(exitstatus)) then
                exitstatus = 2
                return
            else
                stop
            endif
        else if (abs(z) > 1.0d0) then
            print*, "Error --- PlSchmidt"
            print*, "ABS(Z) must be less than or equal to 1."
            print*, "Input value is ", z
            if (present(exitstatus)) then
                exitstatus = 2
                return
            else
                stop
            endif
        end if

        ! Initial conditions
        pm2 = 1.d0
        p(1) = pm2

        if (lmax > 0) then
            pm1 = z
            p(2) = pm1
        end if

        ! Schmidt semi-normalized recurrence relation
        do l = 2, lmax
            pl = (2.0d0*l-1.0d0) * z * pm1 - (l-1.0d0) * pm2
            pl = pl / l
            p(l+1) = pl
            pm2 = pm1
            pm1 = pl
        end do
    end subroutine PlSchmidt
end module SchmidtModule

program testPlSchmidt
    use SchmidtModule
    implicit none
    integer :: lmax
    real(8) :: z
    real(8), allocatable :: p(:)
    integer :: exitstatus
    integer :: i

    ! Test parameters
    lmax = 4
    z = 0.5
    allocate(p(lmax+1))

    ! Call the PlSchmidt subroutine
    call PlSchmidt(p, lmax, z, exitstatus)

    ! Check exit status
    if (exitstatus /= 0) then
        print*, "Error with exit status:", exitstatus
        stop
    end if

    ! Print results
    do i = 1, lmax+1
        print*, "P(", i-1, ") =", p(i)
    end do

    ! Cleanup
    deallocate(p)
end program testPlSchmidt