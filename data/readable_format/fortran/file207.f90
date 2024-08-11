! ----------------------------
! file: symh_module.f90
! ----------------------------
module symh_mod
    use, intrinsic :: iso_fortran_env, only: real64
    implicit none
contains
    subroutine symh(H, DIP, I, N, IPO)
        real(real64), dimension(*), intent(inout) :: H
        real(real64), dimension(3, *), intent(inout) :: DIP
        integer, dimension(:,:), intent(in) :: IPO
        integer, intent(in) :: I, N

        integer :: j, k
        do j = 1, N
            H(j) = H(j) + 1.0_real64
            do k = 1, 3
                H(j) = H(j) + DIP(k, j)
            end do
        end do
    end subroutine symh
end module symh_mod

! ----------------------------
! file: test_symh.f90
! ----------------------------
program test_symh
    use symh_mod
    implicit none

    real(real64) :: H(5)
    real(real64) :: DIP(3, 5)
    integer :: IPO(10, 120) ! Adjust size as needed
    integer :: i, j

    H = (/ 1.0_real64, 2.0_real64, 3.0_real64, 4.0_real64, 5.0_real64 /)
    do i = 1, 3
        do j = 1, 5
            DIP(i, j) = real(i + j, real64)
        end do
    end do

    IPO = 0
    call symh(H, DIP, 1, 5, IPO)
    print *, "Modified H:"
    print *, H
end program test_symh