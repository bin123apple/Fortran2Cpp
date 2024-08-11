! This is the combined file including the pbm_cut subroutine and its tests.
program test_pbm_cut
    implicit none
    integer, dimension(2, 10) :: ks
    integer :: ithds, kstart, kend, nthds, i

    ! The subroutine pbm_cut is included below this program block.

    ! Test case 1: 100 elements, 10 threads
    kstart = 1
    kend = 100
    nthds = 10
    call pbm_cut(ks, kstart, kend, nthds)
    print *, "Test 1: 100 elements, 10 threads"
    do i = 1, nthds  ! Corrected the loop to use 1-based indexing
        print *, "Thread", i-1, ": Start =", ks(1, i), "End =", ks(2, i)
    end do

    ! Add more test cases as needed
end program test_pbm_cut

subroutine pbm_cut(ks, kstart, kend, nthds)
    ! Arguments and local variables declaration.
    integer, intent(inout) :: ks(2, *)
    integer, intent(in) :: kstart, kend, nthds
    integer :: kend0, kstart0, ithds, nn, nblk

    kend0 = kend
    kstart0 = kstart
    ithds = 1  ! Start with 1 to follow Fortran's 1-based indexing

    do while (ithds < nthds)
        nn = kend0 - kstart0 + 1
        nblk = nn / (nthds - ithds + 1)
        if (nblk < 0) nblk = 0
        if (mod(nblk, 2) == 1) then
            nblk = nblk + 1
        end if
        ks(1, ithds) = kstart0
        ks(2, ithds) = kstart0 + nblk - 1
        kstart0 = kstart0 + nblk
        ithds = ithds + 1
    end do

    nn = kend0 - kstart0 + 1
    nblk = nn
    if (nblk < 0) nblk = 0
    ks(1, ithds) = kstart0
    ks(2, ithds) = kstart0 + nblk - 1

    return
end subroutine pbm_cut