! init_conds_module.f90
module init_conds_module
    implicit none
    contains

    subroutine init_conds(x, y, z, rho, ux, uy, uz, p)
        implicit none
        double precision, intent(in) :: x, y, z
        double precision, intent(out) :: rho, ux, uy, uz, p

        uz = 0.0d0

        if ((x >= 0.25d0) .and. (x <= 0.75d0) .and. (y >= 0.25d0) .and. (y <= 0.75d0)) then
            p = 2.5d0
            rho = 4.0d0
        else
            p = 2.5d0
            rho = 1.0d0
        endif

        ux = 0.5d0
        uy = 0.5d0
    end subroutine init_conds

end module init_conds_module

! test_init_conds.f90
program test_init_conds
    use init_conds_module
    implicit none

    double precision :: x, y, z
    double precision :: rho, ux, uy, uz, p

    ! Test case within specified range
    x = 0.5; y = 0.5; z = 0.0
    call init_conds(x, y, z, rho, ux, uy, uz, p)
    print *, "Within range:", "rho =", rho, "ux =", ux, "uy =", uy, "uz =", uz, "p =", p

    ! Test case outside specified range
    x = 0.1; y = 0.1; z = 0.0
    call init_conds(x, y, z, rho, ux, uy, uz, p)
    print *, "Outside range:", "rho =", rho, "ux =", ux, "uy =", uy, "uz =", uz, "p =", p

end program test_init_conds