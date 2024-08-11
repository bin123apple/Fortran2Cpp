program test_per_freq
    implicit none
    double precision, dimension(2) :: flim
    real, allocatable :: f(:)
    integer :: n
    integer :: i

    ! Test parameters
    n = 5
    flim(1) = 100.0
    flim(2) = 200.0

    allocate(f(n))

    call per_freq(f, n, flim)

    print *, "Testing per_freq subroutine"
    do i=1, n
        print *, "f(", i, ") = ", f(i)
    end do

    deallocate(f)

contains

    subroutine per_freq(f, n, flim)
        integer, intent(in) :: n
        double precision, intent(in) :: flim(2)
        real, intent(out) :: f(n)
        double precision :: df
        integer :: i

        df = (flim(2)-flim(1))/dble(n-1)

        do i=1, n
            f(i) = flim(1) + dble(i-1)*df
        end do
    end subroutine per_freq

end program test_per_freq