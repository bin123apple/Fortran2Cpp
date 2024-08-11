module sym_cnst_odiag
    implicit none
    contains

    subroutine sym_cnst_odiag_real_dp(matrix)
        integer, parameter :: dp = kind(1.0d0)
        real(kind=dp), dimension(:,:), intent(inout) :: matrix
        integer :: i, j

        do i = 1, size(matrix, 1)
            do j = 1, size(matrix, 2)
                matrix(i, j) = matrix(i, j) + 1.0_dp
            end do
        end do
    end subroutine sym_cnst_odiag_real_dp
end module sym_cnst_odiag

program test_sym_cnst_odiag
    use sym_cnst_odiag
    implicit none
    integer, parameter :: dp = kind(1.0d0)
    real(kind=dp), dimension(:,:), allocatable :: matrix
    integer :: n, m, i, j

    n = 4
    m = 4
    allocate(matrix(n, m))

    do i = 1, n
        do j = 1, m
            matrix(i, j) = real(i + j, dp)
        end do
    end do

    print *, 'Before calling sym_cnst_odiag_real_dp:'
    do i = 1, n
        print '(4F8.2)', matrix(i, :)
    end do

    call sym_cnst_odiag_real_dp(matrix)

    print *, 'After calling sym_cnst_odiag_real_dp:'
    do i = 1, n
        print '(4F8.2)', matrix(i, :)
    end do

    deallocate(matrix)
end program test_sym_cnst_odiag