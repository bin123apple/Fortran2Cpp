program test_smooth_bruckner
    implicit none

    double precision, allocatable :: y(:), y_bkg(:)
    integer :: n, smooth_points, iterations, i

    ! Example parameters
    n = 10
    smooth_points = 2
    iterations = 3

    ! Allocate and initialize arrays
    allocate(y(0:n-1))
    allocate(y_bkg(0:n-1))
    y = (/1.0d0, 2.0d0, 3.0d0, 4.0d0, 5.0d0, 4.0d0, 3.0d0, 2.0d0, 1.0d0, 0.0d0/)

    ! Call the subroutine
    call smooth_bruckner(y_bkg, y, n, smooth_points, iterations)

    ! Print the result
    print *, 'y_bkg:'
    do i = 0, n-1
        print *, y_bkg(i)
    end do
end program test_smooth_bruckner

subroutine smooth_bruckner(y_bkg, y, n, smooth_points, iterations)
    implicit none

    integer, intent(in) :: n
    integer, intent(in) :: smooth_points
    integer, intent(in) :: iterations
    double precision, intent(in), dimension(0:n-1) :: y
    double precision, intent(out), dimension(0:n-1) :: y_bkg

    double precision, dimension(0:n+2*smooth_points-1) :: y_extended
    double precision :: window_avg
    double precision :: y_new 
    integer :: i, j
    double precision :: window_size

    ! Extend the array y at both ends
    y_extended(0:smooth_points-1) = y(0)
    y_extended(smooth_points:n+smooth_points-1) = y
    y_extended(smooth_points+n:2*smooth_points+n-1) = y(n-1)

    window_size = 2*smooth_points + 1
    do j=0, iterations-1
        window_avg = sum(y_extended(0:2*smooth_points))/(2*smooth_points+1)
        do i=smooth_points, (n-smooth_points-3) 
            if (y_extended(i)>window_avg) then
                y_new = window_avg        
                window_avg = window_avg + ((window_avg-y_extended(i)) + &
                                           (y_extended(i+smooth_points+1)-y_extended(i - smooth_points))) / &
                                           window_size
                y_extended(i) = y_new
            else
                window_avg = window_avg + &
                            (y_extended(i+smooth_points+1)-y_extended(i - smooth_points)) / window_size
            end if 
        end do
    end do

    y_bkg = y_extended(smooth_points:n+smooth_points-1)
end subroutine smooth_bruckner