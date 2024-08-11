module anisotropy_ajn
contains
    subroutine CIJ_symm(C)
        real(8), intent(inout) :: C(6,6)
        integer :: i, j
        do i = 1, 6
            do j = 1, i-1
                C(j,i) = C(i,j)
            end do
        end do
    end subroutine CIJ_symm
end module anisotropy_ajn

program test_CIJ_symm
    use anisotropy_ajn, only: CIJ_symm
    implicit none
    real(8) :: C(6,6) = reshape((/11, 12, 13, 14, 15, 16, &
                                   0, 22, 23, 24, 25, 26, &
                                   0,  0, 33, 34, 35, 36, &
                                   0,  0,  0, 44, 45, 46, &
                                   0,  0,  0,  0, 55, 56, &
                                   0,  0,  0,  0,  0, 66/), (/6,6/))

    write(*,'(a)') 'Matrix before symmetrisation:'
    call print_matrix(C)

    call CIJ_symm(C)

    write(*,'(/a)') 'Matrix after symmetrisation:'
    call print_matrix(C)

contains

    subroutine print_matrix(C)
        real(8), intent(in) :: C(6,6)
        integer :: i, j
        do i = 1, 6
            write(*,'(6F8.2)') (C(i,j), j=1,6)
        end do
    end subroutine print_matrix
end program test_CIJ_symm