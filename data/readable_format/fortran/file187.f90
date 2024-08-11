subroutine clusige(n, x, incx, target, index, nclus)
    integer, intent(in) :: n, incx, target
    integer, intent(in) :: x(*)
    integer, intent(out) :: index(2, *), nclus
    integer :: i, ib, ie, nb, ne
    if (n < 1) return
    if (incx >= 0) then
        ib = 1
        ie = 1
    else
        ib = 1 - incx * (n - 1)
        ie = 1 - incx * (n - 1)
    endif
    nb = 0
    do i = 1, n
        if (x(ib) >= target) then
            if (nb == 0 .or. (x(ib-incx) < target)) then
                nb = nb + 1
                index(1, nb) = i
            endif
            ie = i
        endif
        ib = ib + incx
    end do
    
    if (nb > 0) then
        index(2, nb) = ie
    endif
    nclus = nb
end subroutine clusige

! Main program for testing
program test
    integer, parameter :: n = 10
    integer :: x(n) = [3, 6, 9, 15, 20, 25, 30, 35, 40, 2]
    integer :: index(2, n), nclus, target, incx

    target = 10
    incx = 1
    call clusige(n, x, incx, target, index, nclus)

    print *, "Number of clusters:", nclus
    if (nclus > 0) then
        print *, "Start indices:", (index(1, i), i=1, nclus)
        print *, "End indices:", (index(2, i), i=1, nclus)
    endif
end program test