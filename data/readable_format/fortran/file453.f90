module matrix_operations
    implicit none
contains
    subroutine r3mtm(a, b, c)
        real(8), intent(in) :: a(3,3), b(3,3)
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

program test_matrix_mul
    use matrix_operations
    implicit none
    real(8), dimension(3,3) :: a, b, c
    integer :: i, j

    a = reshape([1.0d0, 2.0d0, 3.0d0, &
                 4.0d0, 5.0d0, 6.0d0, &
                 7.0d0, 8.0d0, 9.0d0], shape(a), order=[2,1])

    b = reshape([9.0d0, 8.0d0, 7.0d0, &
                 6.0d0, 5.0d0, 4.0d0, &
                 3.0d0, 2.0d0, 1.0d0], shape(b), order=[2,1])

    call r3mtm(a, b, c)

    print *, "Resulting matrix C:"
    do i = 1, 3
        print '(3F8.2)', (c(i, j), j=1, 3)
    end do
end program test_matrix_mul