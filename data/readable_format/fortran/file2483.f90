! phixyzp_test.f90
subroutine phixyzp(is, ic, ixp, iyp, izp, level)
    implicit none
    integer, intent(in) :: is, ic, level
    integer, intent(out) :: ixp, iyp, izp
    integer :: icp
    integer, dimension(0:7,0:11) :: icstate
    integer, dimension(0:7) :: ixind, iyind, izind

    ! Initialize icstate
    data icstate / &
         0,1,2,3,4,5,6,7, &
         0,3,4,7,6,5,2,1, &
         0,7,6,1,2,5,4,3, &
         2,3,0,1,6,7,4,5, &
         4,3,2,5,6,1,0,7, &
         6,5,2,1,0,3,4,7, &
         4,7,0,3,2,1,6,5, &
         6,7,4,5,2,3,0,1, &
         2,5,4,3,0,7,6,1, &
         6,1,0,7,4,3,2,5, &
         2,1,6,5,4,7,0,3, &
         4,5,6,7,0,1,2,3 /

    ! Initialize ixind, iyind, izind
    data ixind /0,0,1,1,1,1,0,0/
    data iyind /0,0,0,0,1,1,1,1/
    data izind /0,1,1,0,0,1,1,0/

    if(level .eq. 1) then
        icp = ic
    else
        icp = icstate(ic, is)
    endif
    ixp = ixind(icp)
    iyp = iyind(icp)
    izp = izind(icp)
end subroutine phixyzp

program test_phixyzp
    implicit none
    integer :: ixp, iyp, izp
    integer :: is, ic, level

    call phixyzp(2, 3, ixp, iyp, izp, 1)
    print *, 'Test case 1:', ixp, iyp, izp

    call phixyzp(5, 7, ixp, iyp, izp, 2)
    print *, 'Test case 2:', ixp, iyp, izp
end program test_phixyzp