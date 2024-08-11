! fd.f90
subroutine fd(data_in, df_out, N, dx, kd)
    implicit none

    integer, intent(in) :: N, kd
    double precision, intent(in) :: dx
    double precision, intent(in) :: data_in(N)
    double precision, intent(out) :: df_out(N)
    double precision :: temp_data_in(1-kd:N+kd)
    double precision :: s
    double precision :: cd1(-4:4)
    integer :: i, j

    ! Fill temp_data_in with data_in and implement periodic boundary conditions
    temp_data_in(1:N) = data_in(1:N)
    do i = 1, kd
        temp_data_in(1-i) = data_in(N-i+1)
        temp_data_in(N+i) = data_in(1+i-1)
    end do

    ! Define coefficients
    cd1(-4) = 1d0 / 280d0
    cd1(-3) = -4d0 / 105d0
    cd1(-2) = 0.2d0
    cd1(-1) = -0.8d0
    cd1(0) = 0d0
    cd1(1) = 0.8d0
    cd1(2) = -0.2d0
    cd1(3) = 4d0 / 105d0
    cd1(4) = -1d0 / 280d0

    ! Compute finite differences
    do j = 1, N
        s = 0d0
        do i = -kd, kd
            s = s + cd1(i) * temp_data_in(j+i)
        end do
        s = s / dx
        df_out(j) = s
    end do
end subroutine

program test_fd
    implicit none
    double precision, allocatable :: data_in(:), df_out(:)
    integer :: N, kd
    double precision :: dx

    N = 5
    dx = 0.1d0
    kd = 4
    allocate(data_in(N), df_out(N))
    data_in = [1d0, 2d0, 3d0, 4d0, 5d0]

    call fd(data_in, df_out, N, dx, kd)

    print *, "Test 1: N=5, dx=0.1, kd=4"
    print *, df_out

    deallocate(data_in, df_out)
end program test_fd