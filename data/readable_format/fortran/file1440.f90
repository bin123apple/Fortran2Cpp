module cholesky_module
    implicit none
contains
    function calc_Dmat_cholesky(nbasis, Lmat, Umat, Bmat) result(Dmat)
        integer, intent(in) :: nbasis
        real*8, intent(in) :: Lmat(nbasis, nbasis)
        real*8, intent(in) :: Umat(nbasis, nbasis)
        real*8, intent(in) :: Bmat(nbasis, nbasis)
        real*8 :: Dmat(nbasis, nbasis)
        real*8, allocatable :: Matrix(:,:)
        integer :: ii, jj

        allocate(Matrix(nbasis, nbasis))
        Matrix = (-1.0d0) * Lmat
        Matrix = matmul(Matrix, Bmat)
        Matrix = matmul(Matrix, Umat)

        do jj = 1, nbasis
            do ii = 1, jj-1
                Dmat(ii, jj) = -Matrix(jj, ii)
            end do
            Dmat(jj, jj) = 0.0d0
            do ii = jj + 1, nbasis
                Dmat(ii, jj) = Matrix(ii, jj)
            end do
        end do

        deallocate(Matrix)
    end function calc_Dmat_cholesky
end module cholesky_module

program test_cholesky
    use cholesky_module
    implicit none

    real*8 :: Lmat(3,3), Umat(3,3), Bmat(3,3), Dmat(3,3)
    integer :: i, j

    ! Initialize matrices for testing
    Lmat = reshape((/1d0, 0d0, 0d0, 0d0, 1d0, 0d0, 0d0, 0d0, 1d0/), shape(Lmat))
    Umat = Lmat
    Bmat = Lmat

    ! Call the function
    Dmat = calc_Dmat_cholesky(3, Lmat, Umat, Bmat)

    ! Output the result for verification
    print *, "Test 1: Identity Matrices Result"
    do i = 1, 3
        print *, (Dmat(i, j), j = 1, 3)
    end do
end program test_cholesky