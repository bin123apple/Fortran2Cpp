! Define the clusfgt subroutine
subroutine clusfgt( n, x, incx, target, index, nclus )
    integer n, incx, nclus
    real target
    integer, dimension(2,*) :: index
    real, dimension(*) :: x
    integer i, ib, ie, nb, ne

    if (n < 1) return

    if (incx >= 0) then
        ib = 1
        ie = 1
    else
        ib = 1 - incx * (n - 1)
        ie = 1 - incx * (n - 1)
    end if

    nb = 0
    do i = 1, n
        if (x(ib) > target) then
            if (nb == 0 .or. x(ib-incx) <= target) then
                nb = nb + 1
                index(1,nb) = i
            end if
            if (i == n) then
                index(2,nb) = i
            end if
        else if (ib - incx > 0 .and. x(ib-incx) > target) then
            index(2,nb) = i - 1
        end if
        ib = ib + incx
    end do

    nclus = nb
end subroutine clusfgt

! Main program to test the clusfgt subroutine
program test_clusfgt
    implicit none
    integer :: n, incx, nclus, i, j
    real :: target
    integer, allocatable :: index(:,:)
    real, allocatable :: x(:)

    ! Test case setup
    n = 5
    incx = 1
    target = 3.5
    allocate(x(n))
    allocate(index(2,n))
    x = (/1.0, 2.0, 3.0, 4.0, 5.0/)
    
    ! Call the subroutine
    call clusfgt(n, x, incx, target, index, nclus)
    
    ! Output the results
    print *, "Number of clusters found:", nclus
    do i = 1, nclus
        print *, "Cluster ", i, "starts at index", index(1,i), "and ends at index", index(2,i)
    end do

    ! Deallocate to prevent memory leaks
    deallocate(x)
    deallocate(index)
end program test_clusfgt