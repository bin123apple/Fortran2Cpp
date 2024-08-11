! main_program.f90
program main_program
    implicit none
    integer, parameter :: n = 5
    double precision, dimension(n) :: yv1, yv2
    double precision, dimension(n) :: tiltc, tilts, moidpsv
    double precision, dimension(1, n) :: aaiv, bbiv
    integer :: i, j

    ! Initialize arrays for testing
    do i = 1, n
        tiltc(i) = 0.1 * i
        tilts(i) = 0.05 * i
        aaiv(1, i) = 0.2 * i
        bbiv(1, i) = 0.3 * i
        moidpsv(i) = 1.0 * i
        yv1(i) = 0.0
        yv2(i) = 0.0
    end do

    ! Perform operations
    do j = 1, n
        do i = 1, n
            yv1(j) = yv1(j) + (tiltc(i) * bbiv(1, i) - tilts(i) * aaiv(1, i)) * moidpsv(j)
            yv2(j) = yv2(j) + (tiltc(i) * aaiv(1, i) + tilts(i) * bbiv(1, i)) * moidpsv(j)
        end do
    end do

    ! Print the results
    print *, 'yv1:', yv1
    print *, 'yv2:', yv2
end program main_program