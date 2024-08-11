program test_recips
    implicit none
    integer, parameter :: DP = selected_real_kind(15, 307) ! Double precision
    real(kind=DP) :: a1(3) = [1.0_DP, 2.0_DP, 3.0_DP]
    real(kind=DP) :: a2(3) = [4.0_DP, 5.0_DP, 6.0_DP]
    real(kind=DP) :: a3(3) = [7.0_DP, 8.0_DP, 9.0_DP]
    real(kind=DP) :: b1(3), b2(3), b3(3)

    call recips(a1, a2, a3, b1, b2, b3)

    print *, "b1:", b1
    print *, "b2:", b2
    print *, "b3:", b3

contains

    subroutine recips(a1, a2, a3, b1, b2, b3)
        real(kind=DP), intent(in) :: a1(3), a2(3), a3(3)
        real(kind=DP), intent(out) :: b1(3), b2(3), b3(3)
        real(kind=DP) :: den, s
        integer :: iperm, i, j, k, l, ipol
        den = 0
        i = 1
        j = 2
        k = 3
        s = 1.0_DP
    100 continue
        do iperm = 1, 3
            den = den + s * a1(i) * a2(j) * a3(k)
            l = i
            i = j
            j = k
            k = l
        end do
        i = 2
        j = 1
        k = 3
        s = -s
        if (s < 0.0_DP) then
            goto 100
        end if
        i = 1
        j = 2
        k = 3
        do ipol = 1, 3
            b1(ipol) = (a2(j) * a3(k) - a2(k) * a3(j)) / den
            b2(ipol) = (a3(j) * a1(k) - a3(k) * a1(j)) / den
            b3(ipol) = (a1(j) * a2(k) - a1(k) * a2(j)) / den
            l = i
            i = j
            j = k
            k = l
        end do
    end subroutine recips

end program test_recips