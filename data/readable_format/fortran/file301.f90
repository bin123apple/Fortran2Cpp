subroutine make_phbm(beam, m, n, ibc, jbc, alpha, status)
    integer :: status, m, n, ibc, jbc
    real*4 :: alpha
    real*4, dimension(m,n) :: beam

    if (status /= 0) then
        return
    endif

    beam(ibc,jbc) = beam(ibc,jbc) + alpha*beam(ibc,jbc)
end subroutine make_phbm

program test_make_phbm
    implicit none
    integer :: m, n, ibc, jbc, status
    real*4 :: alpha
    real*4, allocatable :: beam(:,:)

    m = 3
    n = 3
    allocate(beam(m,n))
    beam = reshape([1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0], shape(beam))
    alpha = 0.5
    ibc = 2
    jbc = 3

    ! Test 1: Verify no modification when status is not 0
    status = 1
    call make_phbm(beam, m, n, ibc, jbc, alpha, status)
    if (beam(2,3) == 6.0) then
        print *, 'Fortran Test 1 Passed'
    else
        print *, 'Fortran Test 1 Failed'
    endif

    ! Reset beam for next test
    beam = reshape([1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0], shape(beam))

    ! Test 2: Confirm correct modification when status is 0
    status = 0
    call make_phbm(beam, m, n, ibc, jbc, alpha, status)
    if (beam(2,3) == 9.0) then
        print *, 'Fortran Test 2 Passed'
    else
        print *, 'Fortran Test 2 Failed'
    endif

    deallocate(beam)
end program test_make_phbm