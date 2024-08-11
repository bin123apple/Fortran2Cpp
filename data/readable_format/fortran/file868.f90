module BoxMullerMod
    implicit none
contains
    subroutine boxMuller(x, y)
        real, intent(out) :: x, y
        real :: u1, u2, r, theta
        call random_seed()
        call random_number(u1)
        call random_number(u2)
        r = sqrt(-2.0 * log(u1))
        theta = 2.0 * 3.14159265358979323846 * u2
        x = r * cos(theta)
        y = r * sin(theta)
    end subroutine boxMuller
end module BoxMullerMod

program test_box_muller
    use BoxMullerMod
    implicit none
    real :: x, y, mean, variance, start, finish
    integer :: i, Nsim

    Nsim = 10000
    mean = 0.0
    variance = 0.0

    call cpu_time(start)
    do i = 1, Nsim
        call boxMuller(x, y)
        mean = mean + x + y
        variance = variance + x**2 + y**2
    end do
    call cpu_time(finish)

    mean = mean / (2*Nsim)
    variance = variance / (2*Nsim) - mean**2

    print *, "Mean:", mean
    print *, "Variance:", variance
    print *, "Elapsed Time:", finish - start, "seconds"
end program test_box_muller