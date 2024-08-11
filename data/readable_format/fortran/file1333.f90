! file: fpsysy.f90
module fpsysy_module
    implicit none
contains
    subroutine fpsysy(a, n, g)
        real, dimension(:,:), intent(inout) :: a
        real, dimension(:), intent(inout) :: g
        integer, intent(in) :: n
        real :: fac
        integer :: i, i1, j, k

        g(1) = g(1) / a(1,1)
        if (n == 1) return

        do k = 2, n
            a(k,1) = a(k,1) / a(1,1)
        end do

        do i = 2, n
            i1 = i - 1
            do k = i, n
                fac = a(k,i)
                do j = 1, i1
                    fac = fac - a(k,j)*a(j,i)
                end do
                a(k,i) = fac
                if (k > i) then
                    a(k,i) = fac / a(i,i)
                end if
            end do
        end do

        do i = 2, n
            i1 = i - 1
            fac = g(i)
            do j = 1, i1
                fac = fac - g(j)*a(i,j)
            end do
            g(i) = fac / a(i,i)
        end do

        do i = n-1, 1, -1
            do k = i+1, n
                g(i) = g(i) - g(k)*a(k,i)
            end do
        end do
    end subroutine fpsysy
end module fpsysy_module

program test_fpsysy
    use fpsysy_module
    implicit none
    real, dimension(3,3) :: a
    real, dimension(3) :: g
    integer :: n, i

    ! Initialize a test case
    n = 3
    a = reshape([1.0, 2.0, 3.0, &
                 2.0, 5.0, 7.0, &
                 3.0, 7.0, 10.0], shape(a), order=[2,1])
    g = [6.0, 18.0, 24.0]

    ! Call the subroutine
    call fpsysy(a, n, g)

    ! Print the results
    print *, "Results for g:"
    do i = 1, n
        print *, g(i)
    end do
end program test_fpsysy