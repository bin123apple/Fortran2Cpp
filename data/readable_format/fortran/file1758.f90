program test_v_n
    implicit none
    double precision :: phi, psi, theta, W, V, U
    double precision, dimension(3,1) :: v_n

    ! Initialize variables
    phi = 0.5
    psi = 0.25
    theta = 0.75
    W = 1.0
    V = 2.0
    U = 3.0

    ! Vector computation with line breaks
    v_n(1,1) = (cos(phi)*cos(psi)*sin(theta)+sin(phi)*sin(psi))*W+ &
               (sin(phi)*cos(psi)*sin(theta)-cos(phi)*sin(psi))*V+ &
               cos(psi)*cos(theta)*U
    v_n(2,1) = (cos(phi)*sin(psi)*sin(theta)-sin(phi)*cos(psi))*W+ &
               (sin(phi)*sin(psi)*sin(theta)+cos(phi)*cos(psi))*V+ &
               sin(psi)*cos(theta)*U
    v_n(3,1) = cos(phi)*cos(theta)*W+sin(phi)*cos(theta)*V-sin(theta)*U

    ! Print results
    print *, 'v_n(1,1) = ', v_n(1,1)
    print *, 'v_n(2,1) = ', v_n(2,1)
    print *, 'v_n(3,1) = ', v_n(3,1)

end program test_v_n