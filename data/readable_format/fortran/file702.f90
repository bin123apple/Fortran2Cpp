program test_clusigt
    implicit none
    integer :: nclus
    integer, allocatable :: x(:), index(:,:)
    integer :: i

    ! Test definitions and calls to clusigt go here

    ! Test 1: Array with all elements below the target
    allocate(x(5))
    x = (/1, 2, 3, 4, 5/)
    allocate(index(2,5))
    call clusigt(5, x, 1, 10, index, nclus)
    print *, 'Test 1: nclus should be 0, nclus =', nclus

    ! Additional tests...

contains

    subroutine clusigt(n, x, incx, target, index, nclus)
        integer n, incx, target, nclus
        integer x(*), index(2,*)
        integer i, ib, ie, nb, ne
        if (n < 1) return
        if (incx >= 0) then
            ib = 1
            ie = 1
        else
            ib = 1 - incx * (n - 1)
            ie = 1 - incx * (n - 1)
        endif
        if (x(ib) > target) then
            nb = 1
            index(1,nb) = 1
        else
            nb = 0
        endif
        ib = ib + incx
        do i = 2, n
            if (x(ib-incx) <= target .and. x(ib) > target) then
                nb = nb + 1
                index(1,nb) = i
            endif
            ib = ib + incx
        end do
        if (nb > 0) then
            ne = 0
            do i = 1, n-1
                if (x(ie) > target .and. x(ie+incx) <= target) then
                    ne = ne + 1
                    index(2,ne) = i
                endif
                ie = ie + incx
            end do
            if (x(ie) > target) then
                ne = ne + 1
                index(2,ne) = n
            endif
        endif
        nclus = nb
    end subroutine clusigt

end program test_clusigt