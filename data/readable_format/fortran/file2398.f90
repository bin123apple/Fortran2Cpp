program test_tcopy
    implicit none

    integer, parameter :: n = 5, m = 5, n1 = 3, m1 = 3
    integer*2 :: KWHOLE(n, m)
    real :: PART(n1, m1)
    integer :: IX1, IY1, IX2, IY2, INVAL, NINVAL, KADD
    real :: BS, BZ
    integer :: i, j

    ! Initialize KWHOLE with test values
    do j = 1, m
        do i = 1, n
            KWHOLE(i, j) = (i-1)*m + j
        end do
    end do

    ! Initialize PART to zero
    PART = 0.0
    IX1 = 2
    IY1 = 2
    IX2 = 4
    IY2 = 4
    BS = 1.5
    BZ = 2.0
    INVAL = 13
    KADD = 0

    ! Call the subroutine
    call TCOPY(KWHOLE, n, m, PART, n1, m1, IX1, IY1, IX2, IY2, BS, BZ, INVAL, NINVAL, KADD)

    ! Print results
    print *, 'PART:'
    do j = 1, n1
        print *, (PART(j, i), i=1, m1)
    end do
    print *, 'NINVAL:', NINVAL

end program test_tcopy

subroutine TCOPY(KWHOLE, N, M, PART, N1, M1, IX1, IY1, IX2, IY2, BS, BZ, INVAL, NINVAL, KADD)
    integer*2, intent(in) :: KWHOLE(N, M)
    real, intent(inout) :: PART(N1, M1)
    integer, intent(in) :: IX1, IY1, IX2, IY2, INVAL, KADD
    real, intent(in) :: BS, BZ
    integer, intent(out) :: NINVAL

    integer :: I, J, I1, J1, L
    real :: S

    NINVAL = 0
    J1 = 1
    do J = IY1, IY2
        I1 = 1
        do I = IX1, IX2
            L = KWHOLE(I, J)
            S = real(L) * BS + BZ
            if (L == INVAL) then
                NINVAL = NINVAL + 1
            endif
            if (KADD == 0) then
                PART(I1, J1) = S
            else
                PART(I1, J1) = PART(I1, J1) + S
            endif
            I1 = I1 + 1
        end do
        J1 = J1 + 1
    end do
end subroutine TCOPY