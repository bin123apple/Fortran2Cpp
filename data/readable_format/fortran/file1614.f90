module schmit_module
    use, intrinsic :: iso_fortran_env, only: real64
    implicit none
    
contains

    subroutine schmit(U, N, NDIM)
        integer, intent(in) :: N, NDIM
        real(real64), intent(inout), dimension(NDIM,NDIM) :: U
        integer :: i, j
        real(real64) :: colNorm
        
        do j = 1, NDIM
            colNorm = 0.0_real64
            do i = 1, NDIM
                colNorm = colNorm + U(i,j)**2
            end do
            colNorm = sqrt(colNorm)
            do i = 1, NDIM
                U(i,j) = U(i,j) / colNorm
            end do
        end do
    end subroutine schmit

end module schmit_module

program test_schmit
    use schmit_module
    implicit none
    real(real64), dimension(3,3) :: U
    U = reshape([1.0_real64, 2.0_real64, 3.0_real64, &
                 2.0_real64, 3.0_real64, 4.0_real64, &
                 3.0_real64, 4.0_real64, 5.0_real64], shape=[3,3])
    call schmit(U, 3, 3)
    print *, "Normalized Matrix U:"
    print *, U
end program test_schmit