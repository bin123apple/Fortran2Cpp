program test_legzo
    implicit none
    integer, parameter :: N = 5
    double precision :: X(N), W(N)
    integer :: i

    ! Call the LEGZO subroutine
    call LEGZO(N, X, W)

    ! Output the results for manual verification or comparison
    print *, 'X values:'
    do i = 1, N
        print *, X(i)
    end do

    print *, 'W values:'
    do i = 1, N
        print *, W(i)
    end do

contains

    subroutine LEGZO(N, X, W)
        implicit none
        integer, intent(in) :: N
        double precision, intent(out) :: X(N), W(N)
        double precision :: Z, Z0, P, F0, F1, PF, PD, FD, Q, WP, GD
        integer :: N0, NR, I, K, J

        N0 = (N + 1) / 2
        do NR = 1, N0
            Z = cos(3.1415926D0 * (NR - 0.25D0) / N)
            do
                Z0 = Z
                P = 1.0D0
                do I = 1, NR - 1
                    P = P * (Z - X(I))
                end do
                F0 = 1.0D0
                if (NR.EQ.N0 .AND. N.NE.2*INT(N/2)) Z = 0.0D0
                F1 = Z
                do K = 2, N
                    PF = (2.0D0 - 1.0D0 / K) * Z * F1 - (1.0D0 - 1.0D0 / K) * F0
                    PD = K * (F1 - Z * PF) / (1.0D0 - Z * Z)
                    F0 = F1
                    F1 = PF
                end do
                if (Z.EQ.0.0) exit
                FD = PF / P
                Q = 0.0D0
                do I = 1, NR
                    WP = 1.0D0
                    do J = 1, NR
                        if (J.NE.I) WP = WP * (Z - X(J))
                    end do
                    Q = Q + WP
                end do
                GD = (PD - Q * FD) / P
                Z = Z - FD / GD
                if (abs(Z - Z0) > abs(Z) * 1.0D-15) cycle
                exit
            end do
            X(NR) = Z
            X(N + 1 - NR) = -Z
            W(NR) = 2.0D0 / ((1.0D0 - Z * Z) * PD * PD)
            W(N + 1 - NR) = W(NR)
        end do
    end subroutine LEGZO

end program test_legzo