! Define the subroutine
subroutine R3SGRT(GRPID, TYPNAM, nresp, grdtyp, ERROR)
    implicit none
    integer, intent(in) :: GRPID
    integer, intent(out) :: ERROR, nresp
    integer, intent(inout) :: grdtyp(*)
    character(len=8), intent(in) :: TYPNAM
    integer :: NTYPES, BADTYP, ITYPE
    parameter(NTYPES=1)
    character(len=8) :: R3TYPE(NTYPES)
    data BADTYP/7554/
    data R3TYPE/'BUCK_PC'/
 
    ERROR = 0
    do ITYPE = 1, NTYPES
        if (TYPNAM .eq. R3TYPE(ITYPE)) then
            nresp = 1
            grdtyp(1) = 3
            return
        endif
    enddo
    ERROR = BADTYP
end subroutine R3SGRT

! Test program
program testR3SGRT
    implicit none
    integer :: GRPID, ERROR, nresp
    integer, allocatable :: grdtyp(:)
    character(len=8) :: TYPNAM

    allocate(grdtyp(1))

    ! Test 1: Matching case
    GRPID = 1
    TYPNAM = 'BUCK_PC'
    call R3SGRT(GRPID, TYPNAM, nresp, grdtyp, ERROR)
    print *, 'Test 1 - Expected nresp=1, grdtyp(1)=3, ERROR=0:', nresp, grdtyp(1), ERROR

    ! Test 2: Non-matching case
    TYPNAM = 'INVALID'
    call R3SGRT(GRPID, TYPNAM, nresp, grdtyp, ERROR)
    print *, 'Test 2 - Expected ERROR=7554:', ERROR

    deallocate(grdtyp)
end program testR3SGRT