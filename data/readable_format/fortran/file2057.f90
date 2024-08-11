module refinement_module
    implicit none
contains

    subroutine tag4refinement(mx,my,mbc, meqn, xlower, ylower, dx, dy, blockno, q, tag_threshold, init_flag, tag_patch)
        implicit none

        integer :: mx,my, mbc, meqn, tag_patch, init_flag
        integer :: blockno
        double precision :: xlower, ylower, dx, dy
        double precision :: tag_threshold
        double precision, dimension(1-mbc:mx+mbc,1-mbc:my+mbc,meqn) :: q

        integer :: i,j, mq
        double precision :: qmin, qmax

        tag_patch = 0

        mq = 1
        qmin = q(1,1,mq)
        qmax = q(1,1,mq)
        do j = 1-mbc,my+mbc
            do i = 1-mbc,mx+mbc
                qmin = min(q(i,j,mq),qmin)
                qmax = max(q(i,j,mq),qmax)
                if (abs(q(i,j,1)) .gt. tag_threshold) then
                    tag_patch = 1
                    return
                endif
            enddo
        enddo
    end subroutine tag4refinement

end module refinement_module

program testTag4Refinement
    use refinement_module
    implicit none

    integer, parameter :: mx = 2, my = 2, mbc = 1, meqn = 1
    double precision :: q(-mbc:mx+mbc,-mbc:my+mbc,meqn)
    double precision :: xlower, ylower, dx, dy, tag_threshold
    integer :: blockno, init_flag, tag_patch

    ! Test case 1: No values exceed the threshold
    q = 0.0
    tag_threshold = 1.0
    call tag4refinement(mx, my, mbc, meqn, xlower, ylower, dx, dy, blockno, q, tag_threshold, init_flag, tag_patch)
    print *, "Test 1 (no exceed):", tag_patch

    ! Test case 2: At least one value exceeds the threshold
    q = 0.0
    q(0,0,1) = 2.0  ! Exceeds threshold
    call tag4refinement(mx, my, mbc, meqn, xlower, ylower, dx, dy, blockno, q, tag_threshold, init_flag, tag_patch)
    print *, "Test 2 (one exceed):", tag_patch

    ! Test case 3: Value exactly on the threshold
    q = 0.0
    q(0,0,1) = 1.0  ! Exactly the threshold
    call tag4refinement(mx, my, mbc, meqn, xlower, ylower, dx, dy, blockno, q, tag_threshold, init_flag, tag_patch)
    print *, "Test 3 (on threshold):", tag_patch

end program testTag4Refinement