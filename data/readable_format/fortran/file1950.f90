module fault_module
    implicit none
    real(kind=8), dimension(2) :: center
    real(kind=8) :: theta
    real(kind=8), dimension(2) :: xcb
contains
    subroutine mapc2p(xc, yc, xp, yp)
        implicit none
        real(kind=8), intent(in) :: xc, yc
        real(kind=8), intent(out) :: xp, yp
        real(kind=8) :: ls, alpha, xrot, yrot

        if (xc < xcb(1)) then
            ls = sqrt((xc-xcb(1))**2 + (yc-center(2))**2)
        elseif (xc > xcb(2)) then
            ls = sqrt((xc-xcb(2))**2 + (yc-center(2))**2)
        else
            ls = abs(yc - center(2))
        end if

        alpha = ls / (-center(2))
        xrot = center(1) + cos(theta) * (xc - center(1)) + sin(theta) * (yc - center(2))
        yrot = center(2) - sin(theta) * (xc - center(1)) + cos(theta) * (yc - center(2))

        if (alpha < 1.0) then
            xp = (1.0-alpha) * xrot + alpha * xc
            yp = (1.0-alpha) * yrot + alpha * yc
        else
            xp = xc
            yp = yc
        end if
    end subroutine mapc2p
end module fault_module

program test_mapc2p
    use fault_module
    implicit none

    real(kind=8) :: xp, yp

    center = (/0.0d0, 1.0d0/)  ! Adjust center to avoid division by zero in alpha calculation
    theta = 0.0d0  ! Example value in radians
    xcb = (/ -1.0d0, 1.0d0 /)

    call mapc2p(0.5d0, 0.5d0, xp, yp)

    print *, "Transformed coordinates: xp = ", xp, ", yp = ", yp
end program test_mapc2p