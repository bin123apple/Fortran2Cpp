program test_sort_split_nodes
    implicit none

    integer, parameter :: numfn = 5
    integer, parameter :: numelv = 10

    integer :: nfault(3, numfn)
    integer :: indxiel(numelv)
    integer :: i

    ! Initialize nfault and indxiel with test values
    do i = 1, numfn
        nfault(1, i) = i
    end do
    do i = 1, numelv
        indxiel(i) = i + 1
    end do

    ! Call the subroutine
    call sort_split_nodes(nfault, indxiel, numfn, numelv)

    ! Verify the results
    do i = 1, numfn
        if (nfault(1, i) /= indxiel(i)) then
            print *, 'Test failed at index', i
            stop
        end if
    end do
    print *, 'All tests passed.'

end program test_sort_split_nodes

subroutine sort_split_nodes(nfault, indxiel, numfn, numelv)
    implicit none

    integer, parameter :: izero = 0
    integer :: numfn, numelv
    integer :: nfault(3, numfn), indxiel(numelv)
    integer :: i

    if (numfn .eq. izero) return
    do i = 1, numfn
        nfault(1, i) = indxiel(nfault(1, i))
    end do

    return
end subroutine sort_split_nodes