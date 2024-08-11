! This program is a test driver for the JACG subroutine.
program test_jacg
    use iso_fortran_env
    implicit none
    real(kind=real64), allocatable :: XJAC(:)
    integer(kind=int32) :: NP
    real(kind=real64) :: ALPHA, BETA
    integer :: i

    ! Test case 1
    NP = 5
    allocate(XJAC(NP))
    XJAC = [1.0_real64, 2.0_real64, 3.0_real64, 4.0_real64, 5.0_real64]
    ALPHA = 2.0_real64
    BETA = 1.0_real64

    call JACG(XJAC, NP, ALPHA, BETA)
    print *, "Test case 1 results: "
    do i = 1, NP
        print *, XJAC(i)
    end do

    deallocate(XJAC)

    ! You can add more test cases as needed, varying NP, ALPHA, BETA, and the values in XJAC

contains

    subroutine JACG(XJAC, NP, ALPHA, BETA)
        integer(kind=int32), intent(in) :: NP
        real(kind=real64), intent(inout) :: XJAC(NP)
        real(kind=real64), intent(in) :: ALPHA, BETA
        integer :: i
        ! Hypothetical implementation for demonstration
        do i = 1, NP
            XJAC(i) = ALPHA * XJAC(i) + BETA
        end do
    end subroutine JACG

end program test_jacg