module matrix_operations
    implicit none
contains
    subroutine r3mtm(a, b, c)
        real(8), intent(in) :: a(3,3)
        real(8), intent(in) :: b(3,3)
        real(8), intent(out) :: c(3,3)
        integer :: i, j, k

        do i = 1, 3
            do j = 1, 3
                c(i, j) = 0.0d0
                do k = 1, 3
                    c(i, j) = c(i, j) + a(i, k) * b(k, j)
                end do
            end do
        end do
    end subroutine r3mtm
end module matrix_operations

program test_r3mtm
    use matrix_operations
    implicit none
    real(8), dimension(3,3) :: a
    real(8), dimension(3,3) :: b
    real(8), dimension(3,3) :: c

    ! Initialize matrices a and b
    a = reshape([1d0, 2d0, 3d0, &
                 4d0, 5d0, 6d0, &
                 7d0, 8d0, 9d0], shape(a))
    b = reshape([9d0, 8d0, 7d0, &
                 6d0, 5d0, 4d0, &
                 3d0, 2d0, 1d0], shape(b))

    ! Perform matrix multiplication
    call r3mtm(a, b, c)

    ! Print results
    print *, 'Result matrix C:'
    print *, '(',c(1,1),c(1,2),c(1,3),')'
    print *, '(',c(2,1),c(2,2),c(2,3),')'
    print *, '(',c(3,1),c(3,2),c(3,3),')'
end program test_r3mtm