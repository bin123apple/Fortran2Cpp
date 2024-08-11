module euler_module
    implicit none
contains
    subroutine eulerrot(ang, rot)
        real(8), intent(in) :: ang(3)
        real(8), intent(out) :: rot(3,3)
        real(8) sa, sb, sg, ca, cb, cg
        sa = sin(ang(1))
        sb = sin(ang(2))
        sg = sin(ang(3))
        ca = cos(ang(1))
        cb = cos(ang(2))
        cg = cos(ang(3))
        rot(1,1) = cg * cb * ca - sg * sa
        rot(1,2) = cg * cb * sa + sg * ca
        rot(1,3) = -cg * sb
        rot(2,1) = -sg * cb * ca - cg * sa
        rot(2,2) = -sg * cb * sa + cg * ca
        rot(2,3) = sg * sb
        rot(3,1) = sb * ca
        rot(3,2) = sb * sa
        rot(3,3) = cb
    end subroutine eulerrot
end module euler_module

program test_eulerrot
    use euler_module
    implicit none
    real(8) :: ang(3)
    real(8) :: rot(3,3)
    integer :: i, j

    ! Test input angles (in radians)
    ang = [0.1, 0.2, 0.3]

    ! Call the subroutine
    call eulerrot(ang, rot)

    ! Output the results for visual verification
    do i = 1, 3
        do j = 1, 3
            print *, "rot(", i, ",", j, ") = ", rot(i, j)
        end do
    end do
end program test_eulerrot