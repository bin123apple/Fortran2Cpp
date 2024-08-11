program test_fortran
    implicit none
    integer :: i, j
    real, dimension(3) :: yv1, yv2, oidpsv, mtc, strackc, stracks
    real :: crkve, cikve

    ! Initialize variables
    yv1 = (/1.0, 2.0, 3.0/)
    yv2 = (/4.0, 5.0, 6.0/)
    oidpsv = (/0.5, 0.5, 0.5/)
    mtc = (/1.0, 1.0, 1.0/)
    strackc = (/0.1, 0.2, 0.3/)
    stracks = (/0.4, 0.5, 0.6/)
    crkve = 2.0
    cikve = 3.0

    i = 2 ! For the purposes of this example
    do j = 1, 3
        yv1(j) = yv1(j) + (oidpsv(j) * (strackc(i) * crkve + stracks(i) * cikve)) * mtc(j)
        yv2(j) = yv2(j) + (oidpsv(j) * (stracks(i) * crkve - strackc(i) * cikve)) * mtc(j)
    end do

    ! Print results to verify correctness
    print *, "yv1:", yv1
    print *, "yv2:", yv2
end program test_fortran