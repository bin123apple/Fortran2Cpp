program test_inv3x3
    implicit none
    real :: a(3,3), ainv(3,3)
    integer :: i, j

    ! Define a test matrix directly
    a(1,1) = 1.0
    a(1,2) = 2.0
    a(1,3) = 3.0
    a(2,1) = 0.0
    a(2,2) = 4.0
    a(2,3) = 5.0
    a(3,1) = 1.0
    a(3,2) = 0.0
    a(3,3) = 6.0

    ! Call the subroutine to invert the matrix
    call inv3x3(a, ainv)

    ! Print the inverted matrix
    print *, 'Inverted Matrix:'
    do i = 1, 3
        do j = 1, 3
            print *, 'ainv(', i, ',', j, ') = ', ainv(i,j)
        end do
    end do

end program test_inv3x3

subroutine inv3x3(a, ainv)
    implicit none
    real a(3,3), ainv(3,3), det

    det = a(1,1)*(a(2,2)*a(3,3)-a(2,3)*a(3,2)) &
        + a(1,2)*(a(2,3)*a(3,1)-a(2,1)*a(3,3)) &
        + a(1,3)*(a(2,1)*a(3,2)-a(2,2)*a(3,1))

    ainv(1,1) = (a(2,2)*a(3,3)-a(2,3)*a(3,2)) / det
    ainv(2,1) = (a(2,3)*a(3,1)-a(2,1)*a(3,3)) / det
    ainv(3,1) = (a(2,1)*a(3,2)-a(2,2)*a(3,1)) / det
    ainv(1,2) = (a(1,3)*a(3,2)-a(1,2)*a(3,3)) / det
    ainv(2,2) = (a(1,1)*a(3,3)-a(1,3)*a(3,1)) / det
    ainv(3,2) = (a(1,2)*a(3,1)-a(1,1)*a(3,2)) / det
    ainv(1,3) = (a(1,2)*a(2,3)-a(1,3)*a(2,2)) / det
    ainv(2,3) = (a(1,3)*a(2,1)-a(1,1)*a(2,3)) / det
    ainv(3,3) = (a(1,1)*a(2,2)-a(1,2)*a(2,1)) / det
end subroutine inv3x3