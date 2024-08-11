module math_operations_mod
    implicit none
contains
    subroutine updateY(y, ed, ek, tiltc, tilts, crkve, cikve, one, dpda, ix, i)
        double precision, intent(inout) :: y(2)
        double precision, intent(in) :: ed(*), ek(*), tiltc(*), tilts(*)
        double precision, intent(in) :: crkve, cikve, one, dpda
        integer, intent(in) :: ix, i

        y(1) = y(1) + (ed(ix) * tiltc(i) * crkve - ek(ix) * tilts(i) * cikve) / (one + dpda)
        y(2) = y(2) + (ek(ix) * tiltc(i) * cikve + ed(ix) * tilts(i) * crkve) / (one + dpda)
    end subroutine updateY
end module math_operations_mod

program test
    use math_operations_mod
    implicit none

    double precision, dimension(2) :: y
    double precision, dimension(5) :: ed, ek, tiltc, tilts
    double precision :: crkve, cikve, one, dpda
    integer :: ix, i

    ! Initialize some test values
    y = (/0.0, 0.0/)
    ed = (/1.0, 2.0, 3.0, 4.0, 5.0/)
    ek = (/5.0, 4.0, 3.0, 2.0, 1.0/)
    tiltc = (/0.1, 0.2, 0.3, 0.4, 0.5/)
    tilts = (/0.5, 0.4, 0.3, 0.2, 0.1/)
    crkve = 0.6
    cikve = 0.7
    one = 1.0
    dpda = 0.5
    ix = 3
    i = 3

    ! Perform the operation
    call updateY(y, ed, ek, tiltc, tilts, crkve, cikve, one, dpda, ix, i)

    ! Print the result for verification
    print *, "Y(1) = ", y(1)
    print *, "Y(2) = ", y(2)
end program test