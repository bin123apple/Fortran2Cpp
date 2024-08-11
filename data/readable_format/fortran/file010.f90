module my_subroutines
    implicit none
contains
    subroutine addres(jdiag, mht, nwk, ma, mb, neq)
        integer, intent(inout) :: jdiag(*), mht(*)
        integer, intent(inout) :: nwk, ma, mb, neq
        integer :: i

        jdiag(1) = 1
        ma = 0
        mb = 0
        do i = 2, neq
            ma = max(ma, mht(i-1))
            mb = mb + mht(i-1)
            jdiag(i) = jdiag(i-1) + 1 + mht(i-1)
        end do
        ma = ma + 1
        mb = mb + mht(neq) ! Adding the last element which was missing in the loop.
        mb = mb / neq
        nwk = jdiag(neq)
    end subroutine addres
end module my_subroutines

program testAddres
    use my_subroutines
    implicit none
    integer, allocatable :: jdiag(:), mht(:)
    integer :: nwk, ma, mb, neq

    neq = 5
    allocate(jdiag(neq), mht(neq))
    mht = (/1, 2, 3, 4, 5/)
    nwk = 0
    ma = 0
    mb = 0

    call addres(jdiag, mht, nwk, ma, mb, neq)

    print *, "jdiag:", jdiag
    print *, "ma:", ma
    print *, "mb:", mb
    print *, "nwk:", nwk

    deallocate(jdiag, mht)
end program testAddres