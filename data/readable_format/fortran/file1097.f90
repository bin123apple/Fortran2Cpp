! psi_test.f90
double precision function psi(x,y)
    implicit double precision (a-h,o-z)
    psi = x**2 + y**2
end

program test_psi
    implicit none
    double precision psi
    double precision x, y, result

    ! Test 1
    x = 3.0
    y = 4.0
    result = psi(x, y)
    print *, "Test 1 (3, 4): Expected 25, Got ", result

    ! Test 2
    x = 0.0
    y = 0.0
    result = psi(x, y)
    print *, "Test 2 (0, 0): Expected 0, Got ", result

    ! Test 3
    x = -5.0
    y = 2.0
    result = psi(x, y)
    print *, "Test 3 (-5, 2): Expected 29, Got ", result
end program test_psi