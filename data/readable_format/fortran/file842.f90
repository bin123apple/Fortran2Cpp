program test_reinit2
    implicit none

    ! Declare variables and arrays for testing
    integer, allocatable :: kontet(:,:), ifac(:,:), ieln(:,:), ifatet(:,:), itetfa(:,:), iedg(:,:), ieled(:,:)
    integer :: netet_, newsize, i, j

    ! Initialize variables
    netet_ = 1
    newsize = 3

    ! Allocate arrays based on newsize and netet_
    allocate(kontet(4, newsize))
    allocate(ifac(4, 4*newsize))
    allocate(ieln(2, 4*newsize))
    allocate(ifatet(4, newsize))
    allocate(itetfa(2, 4*newsize))
    allocate(iedg(3, 6*newsize))
    allocate(ieled(2, 6*newsize))

    ! Call the subroutine
    call reinit2(kontet, ifac, ieln, netet_, newsize, ifatet, itetfa, iedg, ieled)

    ! Print results for verification
    print *, 'kontet:'
    do i = 1, 4
        print *, kontet(i, :)
    end do

    ! You could add similar print statements for ifac, ieln, ifatet, itetfa, iedg, ieled for further verification

contains

    subroutine reinit2(kontet, ifac, ieln, netet_, newsize, ifatet, itetfa, iedg, ieled)
        implicit none

        integer, intent(inout) :: kontet(4,*), ifac(4,*), ieln(2,*), netet_, newsize
        integer, intent(inout) :: ifatet(4,*), itetfa(2,*), iedg(3,*), ieled(2,*)
        integer :: i, j

        kontet(4, netet_) = netet_ + 1
        do i = netet_ + 1, newsize
            do j = 1, 3
                kontet(j, i) = 0
            end do
            kontet(4, i) = i + 1
        end do
        kontet(4, newsize) = 0

        ! Similar blocks for ifac, ieln, ifatet, itetfa, iedg, ieled initialization (omitted for brevity)
    end subroutine reinit2

end program test_reinit2