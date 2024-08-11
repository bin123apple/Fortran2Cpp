program test_deallocate
    implicit none

    integer, allocatable :: n0array(:)
    integer, allocatable :: n1array(:)
    real, allocatable :: psi0(:)
    real, allocatable :: psi(:)
    real, allocatable :: polar(:)
    integer, allocatable :: iwork_st(:)
    integer, allocatable :: iblock_st(:)
    integer, allocatable :: isplit_st(:)
    real, allocatable :: d_st(:)
    real, allocatable :: e_st(:)
    real, allocatable :: w_st(:)
    real, allocatable :: work_st(:)
    real, allocatable :: z_st(:)

    ! Allocate arrays
    allocate(n0array(10))
    allocate(n1array(10))
    allocate(psi0(10))
    allocate(psi(10))
    allocate(polar(10))
    allocate(iwork_st(10))
    allocate(iblock_st(10))
    allocate(isplit_st(10))
    allocate(d_st(10))
    allocate(e_st(10))
    allocate(w_st(10))
    allocate(work_st(10))
    allocate(z_st(10))

    ! Deallocate arrays
    deallocate(n0array)
    deallocate(n1array)
    deallocate(psi0)
    deallocate(psi)
    deallocate(polar)
    deallocate(iwork_st)
    deallocate(iblock_st)
    deallocate(isplit_st)
    deallocate(d_st)
    deallocate(e_st)
    deallocate(w_st)
    deallocate(work_st)
    deallocate(z_st)

    print *, "Deallocation successful!"

end program test_deallocate