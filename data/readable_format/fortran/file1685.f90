module matrix_operations
    implicit none
    contains

    subroutine matrix_multiply(a, b, c, n)
        integer, intent(in) :: n
        real(8), dimension(n,n), intent(in) :: a, b
        real(8), dimension(n,n), intent(inout) :: c
        integer :: i, j, k

        do i = 1, n
            do j = 1, n
                do k = 1, n
                    c(j, i) = c(j, i) + a(k, i) * b(j, k)
                end do
            end do
        end do
    end subroutine matrix_multiply

end module matrix_operations

program test_matrix_multiply
    use matrix_operations
    implicit none
    real(8), dimension(2,2) :: a, b, c
    real(8), dimension(2,2) :: expected_c
    integer :: i, j
    logical :: test_passed

    ! Initialize matrices
    a = reshape([1.0d0, 2.0d0, 3.0d0, 4.0d0], shape(a))
    b = reshape([1.0d0, 0.0d0, 0.0d0, 1.0d0], shape(b))
    c = 0.0d0
    expected_c = reshape([1.0d0, 2.0d0, 3.0d0, 4.0d0], shape(expected_c))

    ! Perform matrix multiplication
    call matrix_multiply(a, b, c, 2)

    ! Check results
    test_passed = .true.
    do i = 1, 2
        do j = 1, 2
            if (abs(c(i, j) - expected_c(i, j)) > 1e-9) then
                test_passed = .false.
                exit
            endif
        end do
        if (.not. test_passed) exit
    end do

    if (test_passed) then
        print *, "Test passed."
    else
        print *, "Test failed."
    endif

end program test_matrix_multiply