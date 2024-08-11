program test_sqdist
    implicit none
    real*8 :: result
    real*8 :: x1, y1, z1, x2, y2, z2
    integer :: ind, MAXROT
    real*8 :: rotmat(3, 3, 3)

    ! Initialize test values
    x1 = 1.0
    y1 = 2.0
    z1 = 3.0
    x2 = 4.0
    y2 = 5.0
    z2 = 6.0
    ind = 1
    MAXROT = 3

    ! Initialize the rotation matrix
    rotmat(1,1,1) = 1.0
    rotmat(1,1,2) = 0.0
    rotmat(1,1,3) = 0.0
    rotmat(1,2,1) = 0.0
    rotmat(1,2,2) = 1.0
    rotmat(1,2,3) = 0.0
    rotmat(1,3,1) = 0.0
    rotmat(1,3,2) = 0.0
    rotmat(1,3,3) = 1.0

    ! Call the function
    result = sqdist(x1, y1, z1, x2, y2, z2, ind, MAXROT, rotmat)

    ! Print the result
    print *, 'Squared distance:', result

contains

    real*8 function sqdist(x1, y1, z1, x2, y2, z2, ind, MAXROT, rotmat)
        real*8 :: x1, y1, z1, x2, y2, z2
        integer :: ind, MAXROT
        real*8 :: rotmat(MAXROT, 3, 3)
        real*8 :: cont, dx, dy, dz
        integer :: i

        dx = dble(x1 - x2)
        dy = dble(y1 - y2)
        dz = dble(z1 - z2)
        sqdist = 0.0
        do i = 1, 3
            cont = rotmat(ind, i, 1) * dx &
                 + rotmat(ind, i, 2) * dy &
                 + rotmat(ind, i, 3) * dz
            sqdist = sqdist + cont * cont
        end do
    end function sqdist

end program test_sqdist