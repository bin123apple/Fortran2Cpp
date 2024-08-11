! Combined Fortran file with both the subroutine and test program
module distance_module
    implicit none
contains
    subroutine distance_point_line_2D(P0, P1_line, P2_line, dis, normal)
        implicit none
        double precision, intent(IN) :: P0(2), P1_line(2), P2_line(2)
        double precision, intent(OUT) :: dis
        double precision, intent(OUT) :: normal(2)
        double precision :: a, b, c
        a = (P2_line(2) - P1_line(2))
        b = -(P2_line(1) - P1_line(1))
        c = -(a * P1_line(1) + b * P1_line(2))
        normal(1) = a / dsqrt(a**2 + b**2)
        normal(2) = b / dsqrt(a**2 + b**2)
        dis = (a * P0(1) + b * P0(2) + c) / dsqrt(a**2 + b**2)
    end subroutine distance_point_line_2D
end module distance_module

program test_distance_point_line_2D
    use distance_module
    implicit none
    double precision :: P0(2), P1_line(2), P2_line(2), dis, normal(2)

    ! Test Case 1: Point on the line
    P0 = [2.0d0, 2.0d0]
    P1_line = [1.0d0, 1.0d0]
    P2_line = [3.0d0, 3.0d0]
    call distance_point_line_2D(P0, P1_line, P2_line, dis, normal)
    print *, "Test 1 - Distance:", dis, "Normal:", normal

    ! Test Case 2: Point to the left of the line
    P0 = [1.0d0, 2.0d0]
    call distance_point_line_2D(P0, P1_line, P2_line, dis, normal)
    print *, "Test 2 - Distance:", dis, "Normal:", normal

    ! Test Case 3: Point to the right of the line
    P0 = [3.0d0, 4.0d0]
    call distance_point_line_2D(P0, P1_line, P2_line, dis, normal)
    print *, "Test 3 - Distance:", dis, "Normal:", normal

end program test_distance_point_line_2D