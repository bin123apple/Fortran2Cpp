program test_realim
    implicit none
    integer, parameter :: m = 2, n = 2
    real :: a(m, n), b(m, n)
    integer :: i, j

    ! Initialize input arrays
    a(1, 1) = 1.0; a(1, 2) = 2.0
    a(2, 1) = 3.0; a(2, 2) = 4.0
    b(1, 1) = 0.0; b(1, 2) = 0.5
    b(2, 1) = 1.0; b(2, 2) = 1.5

    ! Print initial arrays
    print *, 'Initial arrays:'
    print *, 'a:'
    do i = 1, m
        print *, (a(i, j), j = 1, n)
    end do
    print *, 'b:'
    do i = 1, m
        print *, (b(i, j), j = 1, n)
    end do

    ! Call the subroutine
    call realim(a, b, m, n)

    ! Print modified arrays
    print *, 'Modified arrays:'
    print *, 'a:'
    do i = 1, m
        print *, (a(i, j), j = 1, n)
    end do
    print *, 'b:'
    do i = 1, m
        print *, (b(i, j), j = 1, n)
    end do

contains

    subroutine realim(a, b, m, n)
        implicit none
        integer :: m, n
        real :: a(m, n), b(m, n)
        real :: im
        integer :: j, k
        real :: modul, phase, rl
        
        do k = 1, n
            do j = 1, m
                modul = a(j, k)
                phase = b(j, k)
                rl = modul * cos(phase)
                im = modul * sin(phase)
                a(j, k) = rl
                b(j, k) = im
            end do
        end do
    end subroutine realim

end program test_realim