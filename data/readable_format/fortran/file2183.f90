! File: ssmv_test.f90
subroutine SSMV(N, X, Y, NELT, IA, JA, A, ISYM)
    implicit none
    integer, intent(in) :: N, NELT, ISYM
    real, dimension(N), intent(in) :: X
    real, dimension(NELT), intent(in) :: A
    integer, dimension(NELT), intent(in) :: IA, JA
    real, dimension(N), intent(out) :: Y
    integer :: I, IBGN, ICOL, IEND, IROW, J, JBGN, JEND

    ! Initialize Y
    do I = 1, N
        Y(I) = 0.0
    end do

    ! Sparse matrix-vector multiplication
    do ICOL = 1, N
        IBGN = JA(ICOL)
        IEND = JA(ICOL+1)-1
        do I = IBGN, IEND
            Y(IA(I)) = Y(IA(I)) + A(I) * X(ICOL)
        end do
    end do

    if (ISYM == 1) then
        do IROW = 1, N
            JBGN = JA(IROW) + 1
            JEND = JA(IROW+1) - 1
            do J = JBGN, JEND
                Y(IROW) = Y(IROW) + A(J) * X(IA(J))
            end do
        end do
    endif
end subroutine SSMV

program test_ssmv
    implicit none
    integer, parameter :: N = 3, NELT = 6
    integer :: ISYM
    real, dimension(N) :: X, Y
    real, dimension(NELT) :: A
    integer, dimension(NELT) :: IA
    integer, dimension(N+1) :: JA

    ! Initialize data
    X = (/1.0, 2.0, 3.0/)
    A = (/1.0, 2.0, 3.0, 4.0, 5.0, 6.0/)
    IA = (/1, 2, 3, 1, 2, 3/)
    JA = (/1, 3, 5, 7/)
    ISYM = 1

    ! Perform SSMV
    call SSMV(N, X, Y, NELT, IA, JA, A, ISYM)

    ! Output result
    print *, 'Result Y: ', Y
end program test_ssmv