module servo_with_limits_data
    implicit none
    integer :: nblades, stepno, stuck_type
    real(8) :: omega0, beta0, vmax, amax, theta_min, theta_max
    real(8) :: time_runaway, time_stuck, stuck_angle
    real(8) :: oldtime, theta_ref, yold(2,3), ynew(2,3)
    real(8) :: oldarray2(100)
    real(8) :: timestep
end module servo_with_limits_data

program test_servo_with_limits
    use servo_with_limits_data
    implicit none

    integer :: i

    ! Initialize module variables
    nblades = 4
    stepno = 10
    stuck_type = 2
    omega0 = 1.5
    beta0 = 0.3
    vmax = 100.0
    amax = 10.0
    theta_min = -30.0
    theta_max = 30.0
    time_runaway = 5.0
    time_stuck = 2.0
    stuck_angle = 45.0
    oldtime = 0.0
    theta_ref = 60.0
    yold = reshape([1.0, 2.0, 3.0, 4.0, 5.0, 6.0], shape(yold))
    ynew = reshape([6.0, 5.0, 4.0, 3.0, 2.0, 1.0], shape(ynew))

    do i = 1, 100
        oldarray2(i) = real(i)
    end do

    timestep = 0.01

    ! Display some values to ensure the program works
    print *, "nblades = ", nblades
    print *, "omega0 = ", omega0
    print *, "yold(1,1) = ", yold(1,1)
    print *, "ynew(2,3) = ", ynew(2,3)
    print *, "oldarray2(50) = ", oldarray2(50)
end program test_servo_with_limits