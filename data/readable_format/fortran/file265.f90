module rhofix_mod
    implicit none
contains
    subroutine rhofix_mat(M, Matrix)
        integer, intent(in) :: M
        real(8), intent(inout) :: Matrix(M,M)
        integer :: ii, jj

        do ii = 1, M
            do jj = 1, M
                if (ii /= jj) then
                    Matrix(ii,jj) = Matrix(ii,jj) / 2.d0
                end if
            end do
        end do
    end subroutine rhofix_mat

    subroutine rhofix_vec(M, Vector)
        integer, intent(in) :: M
        real(8), intent(inout) :: Vector((M*(M+1))/2)
        integer :: ii, jj, kk

        kk = 0
        do ii = 1, M
            do jj = 1, ii
                kk = kk + 1
                if (ii /= jj) then
                    Vector(kk) = Vector(kk) / 2.d0
                end if
            end do
        end do
    end subroutine rhofix_vec
end module rhofix_mod

program test_rhofix
    use rhofix_mod
    implicit none
    integer :: M
    real(8), allocatable :: Matrix(:,:), Vector(:)

    M = 3
    allocate(Matrix(M,M))
    allocate(Vector((M*(M+1))/2))

    ! Initialize Matrix and Vector with arbitrary values for testing
    Matrix = reshape([real::1.d0, 2.d0, 3.d0, 4.d0, 5.d0, 6.d0, 7.d0, 8.d0, 9.d0], shape(Matrix))
    Vector = [1.d0, 2.d0, 3.d0, 4.d0, 5.d0, 6.d0]

    call rhofix_mat(M, Matrix)
    call rhofix_vec(M, Vector)

    print *, 'Modified Matrix:'
    print *, Matrix
    print *, 'Modified Vector:'
    print *, Vector
end program test_rhofix