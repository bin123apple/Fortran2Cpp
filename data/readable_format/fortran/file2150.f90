program test_hrk_ud
    implicit none
    integer, parameter :: nef = 5
    integer, parameter :: nfaces = 4
    integer :: ielfa(4, nfaces) = reshape([1, 2, 0, 3, 1, 2, 1, 3, 2, 4, 2, 3, 3, 4, 3, 2], shape(ielfa))
    integer :: ipnei(nef) = [0, 1, 2, 3, 4]
    real*8 :: vel(nef, 0:7)
    real*8 :: flux(10) = [0.5d0, -0.2d0, 0.0d0, 0.8d0, -0.1d0, 0.3d0, -0.4d0, 0.6d0, -0.5d0, 0.2d0]
    real*8 :: vfa(0:7, nfaces)
    integer :: i

    ! Initialize vel
    do i = 1, nef
        vel(i, :) = real(i)
    end do
    
    ! Initialize vfa
    vfa = 0.d0

    ! Call the subroutine
    call hrk_ud(ielfa, vel, ipnei, nef, flux, vfa, 1, nfaces)
    
    ! Print the results
    print *, "vfa(6, :) = ", vfa(6, :)

contains

    subroutine hrk_ud(ielfa, vel, ipnei, nef, flux, vfa, nfacea, nfaceb)
        implicit none
        integer ielfa(4,*), i, j, indexf, ipnei(*), iel1, iel2, nef, nfacea, nfaceb
        real*8 vel(nef,0:7), flux(*), vfa(0:7,*)
        do i = nfacea, nfaceb
            iel2 = ielfa(2, i)
            if (iel2 .le. 0) cycle
            iel1 = ielfa(1, i)
            j = ielfa(4, i)
            indexf = ipnei(iel1) + j
            if (flux(indexf) .ge. 0.d0) then
                vfa(6, i) = vel(iel1, 6)
            elseif (iel2 .gt. 0) then
                vfa(6, i) = vel(iel2, 6)
            endif
        enddo
        return
    end subroutine hrk_ud

end program test_hrk_ud