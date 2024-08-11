module test
    implicit none
    private
    public :: point, grid1

    type point 
        real(8) :: x, y
    end type point

contains

    subroutine grid1(n, List_points)
        implicit none
        integer, intent(in) :: n 
        integer :: i, j
        real(8), parameter :: a = 2.0, b = 2.0, c = 1.0
        real(8) :: hx, hy
        type(point), dimension(0:n**2-1) :: List_points

        hx = a / dble(n-1)

        do i = 0, n-1
            hy = (b-c*i*hx/a) / dble(n-1)
            do j = 0, n-1
                List_points(i*n+j)%x = i*hx
                List_points(i*n+j)%y = j*hy+c*i*hx/a
            end do
        end do
    end subroutine grid1

end module test

program main
    use test
    implicit none
    integer :: n, i
    type(point), allocatable :: List_points(:)

    n = 10  ! Example value for n
    allocate(List_points(0:n**2-1))
    
    call grid1(n, List_points)
    
    ! Print the results
    do i = 0, n**2-1
        print *, 'Point(', List_points(i)%x, ',', List_points(i)%y, ')'
    end do

    deallocate(List_points)
end program main