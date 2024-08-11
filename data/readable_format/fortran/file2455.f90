program test_zmedge
    implicit none

    integer, parameter :: n_edges = 3
    real :: XZMMIN, XZMMAX, YZMMIN, YZMMAX
    real, dimension(4) :: XN, YN
    integer, dimension(3, n_edges) :: IEDSET
    character(len=8) :: cdebug
    integer :: idebug, i

    ! Initialize variables
    XZMMIN = 0.5
    XZMMAX = 2.5
    YZMMIN = 0.5
    YZMMAX = 2.5

    XN = (/0.0, 1.0, 2.0, 3.0/)
    YN = (/0.0, 1.0, 2.0, 3.0/)
    IEDSET = reshape((/1, 0, 1, 1, 1, 2, 1, 2, 3/), shape(IEDSET))

    cdebug = 'HIDDEN'
    idebug = 1

    ! Call the subroutine
    call ZMEDGE(XZMMIN, XZMMAX, YZMMIN, YZMMAX, XN, YN, IEDSET, n_edges)

    ! Print the modified IEDSET
    print *, 'IEDSET after ZMEDGE:'
    do i = 1, n_edges
        print *, IEDSET(:, i)
    end do

contains

    subroutine ZMEDGE(XZMMIN, XZMMAX, YZMMIN, YZMMAX, XN, YN, IEDSET, NEDGES)
        real, intent(in) :: XZMMIN, XZMMAX, YZMMIN, YZMMAX
        real, dimension(*) :: XN, YN
        integer, dimension(3, *) :: IEDSET
        integer, intent(in) :: NEDGES
        integer :: nhid, N1, N2, IEDG
        real :: X1, X2, Y1, Y2

        nhid = 0
        do IEDG = 1, NEDGES
            if (IEDSET(1, IEDG) == 0) cycle

            N1 = IEDSET(2, IEDG)
            X1 = XN(N1)
            Y1 = YN(N1)
            if (X1 <= XZMMIN .or. X1 >= XZMMAX .or. Y1 <= YZMMIN .or. Y1 >= YZMMAX) then
                N2 = IEDSET(3, IEDG)
                X2 = XN(N2)
                Y2 = YN(N2)
                if ((X1 <= XZMMIN .and. X2 <= XZMMIN) .or. &
                    (X1 >= XZMMAX .and. X2 >= XZMMAX) .or. &
                    (Y1 <= YZMMIN .and. Y2 <= YZMMIN) .or. &
                    (Y1 >= YZMMAX .and. Y2 >= YZMMAX)) then
                    IEDSET(1, IEDG) = 0
                    nhid = nhid + 1
                end if
            end if
        end do

        ! Debug output
        if (cdebug == 'HIDDEN' .and. idebug >= 1) then
            print *, 'edges outside zoom window =', nhid
        end if
    end subroutine ZMEDGE

end program test_zmedge