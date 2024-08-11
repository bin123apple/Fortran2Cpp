module precision
    ! Define the kind for double precision.
    integer, parameter :: double = selected_real_kind(15, 307)
end module precision

module fittingmod
    use precision, only: double
    implicit none
    integer, pointer :: ntrace2, nfit2, ilinkpsf2, nline2
    integer, dimension(:), pointer :: isol2
    real(double), dimension(:), pointer :: line2, sol2
end module fittingmod

program test_fittingmod
    use fittingmod
    implicit none

    ! Allocate and set values
    allocate(ntrace2)
    ntrace2 = 5
    allocate(nfit2)
    nfit2 = 10
    allocate(ilinkpsf2)
    ilinkpsf2 = 2
    allocate(nline2)
    nline2 = 3

    allocate(isol2(5))
    isol2 = (/1, 2, 3, 4, 5/)

    allocate(line2(3))
    line2 = (/1.0_double, 2.0_double, 3.0_double/)

    allocate(sol2(10))
    sol2 = (/1.0_double, 2.0_double, 3.0_double, 4.0_double, &
             5.0_double, 6.0_double, 7.0_double, 8.0_double, &
             9.0_double, 10.0_double/)

    ! Print values to verify
    print *, "ntrace2:", ntrace2
    print *, "nfit2:", nfit2
    print *, "ilinkpsf2:", ilinkpsf2
    print *, "nline2:", nline2
    print *, "isol2:", isol2
    print *, "line2:", line2
    print *, "sol2:", sol2

    ! Clean up
    deallocate(ntrace2, nfit2, ilinkpsf2, nline2, isol2, line2, sol2)
end program test_fittingmod