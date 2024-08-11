program test_cublas
    use iso_c_binding
    implicit none
    integer, parameter :: Msize = 2
    real(kind=8), dimension(Msize, Msize), target :: matrix
    type(c_ptr) :: dev_ptr

    ! Initialize the matrix with some test values
    matrix = reshape([1.0d0, 2.0d0, 3.0d0, 4.0d0], shape(matrix))

    ! Assuming cublas_setmat and cublas_release are external procedures properly
    ! bound to cuBLAS library functions
    call cublas_setmat(Msize, matrix, dev_ptr)
    call cublas_release(dev_ptr)

    print *, "Fortran test completed successfully."

contains

    ! These are placeholders for actual cuBLAS operations
    ! You need to replace these with proper interfaces to cuBLAS functions
    subroutine cublas_setmat(Msize, matrix, dev_ptr)
        integer, intent(in) :: Msize
        real(kind=8), intent(in), target :: matrix(Msize, Msize)
        type(c_ptr), intent(out) :: dev_ptr
        print *, "Setting matrix (placeholder)."
        ! Placeholder logic
        ! Here you would call the actual cuBLAS functions
    end subroutine

    subroutine cublas_release(dev_ptr)
        type(c_ptr), intent(inout) :: dev_ptr
        print *, "Releasing resources (placeholder)."
        ! Placeholder logic
        ! Here you would call the actual cuBLAS functions for resource release
    end subroutine

end program test_cublas