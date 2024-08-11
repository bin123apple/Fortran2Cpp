program test_dmat_prt
    implicit none
    double precision, dimension(9) :: dmat
    integer :: m, n, ld
    integer :: i

    ! Fill the dmat array with some values
    do i = 1, 9
        dmat(i) = i * 1.0d0
    end do

    ! Set matrix dimensions
    m = 3
    n = 3
    ld = 3

    ! Call the dmat_prt subroutine
    call dmat_prt(dmat, m, n, ld)

end program test_dmat_prt

subroutine dmat_prt(dmat, m, n, ld)
    implicit none
    double precision dmat(*)
    integer m, n, ld
    integer i, j, start, cols, doing

    if ((m.eq.0).or.(n.eq.0).or.(ld.lt.m)) return

    start = 1
    cols = n
    do while (cols.ne.0)
        doing = min(3, cols - 1)
        do i = 0, m - 1
            print '(4F19.12)', (dmat(start + i + j * ld), j = 0, doing)
        end do
        print '(/)'
        doing = doing + 1
        cols = cols - doing
        start = start + (ld * doing)
    end do

    return
end subroutine dmat_prt