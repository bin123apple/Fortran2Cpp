module plane_eq_module
    implicit none
contains
    subroutine plane_eq(x1, y1, z1, x2, y2, z2, x3, y3, z3, x0, y0, output)
        implicit none
        double precision, intent(in) :: x1, y1, z1, x2, y2, z2, x3, y3, z3, x0, y0
        double precision, intent(out) :: output
        double precision :: a, b, c, d

        d = x1*y2*z3 + y1*z2*x3 + z1*x2*y3 - x1*z2*y3 - y1*x2*z3 - z1*y2*x3
        if (d /= 0.0d0) then
            a = (y2*z3 + y1*z2 + z1*y3 - z2*y3 - y1*z3 - z1*y2) / d
            b = (x1*z3 + z2*x3 + z1*x2 - x1*z2 - x2*z3 - z1*x3) / d
            c = (x1*y2 + y1*x3 + x2*y3 - x1*y3 - y1*x2 - y2*x3) / d
            if (c /= 0.0d0) then
                output = (1.0d0 - a*x0 - b*y0) / c
            else
                output = 0.0d0
            endif
        else
            output = 0.0d0
        endif
    end subroutine plane_eq
end module plane_eq_module

program test_plane_eq
    use plane_eq_module
    implicit none
    double precision :: output

    call plane_eq(1.0d0, 0.0d0, 0.0d0, 0.0d0, 1.0d0, 0.0d0, 0.0d0, 0.0d0, 1.0d0, 0.5d0, 0.5d0, output)
    print *, "Fortran Test Output: ", output

end program test_plane_eq