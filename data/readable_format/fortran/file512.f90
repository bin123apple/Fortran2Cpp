program ds_routines_program
    implicit none
    real, dimension(30) :: rstore
    real, dimension(1, 4) :: vertic
    integer :: i

    ! Initialize rstore with example data
    do i = 1, 30
        rstore(i) = i
    end do

    ! Call the subroutine
    call dsget(vertic, rstore)

    ! Output the results for verification
    print *, "vertic:"
    do i = 1, 4
        print *, vertic(1, i)
    end do

    print *, "ok"

contains

    subroutine dsget(vertic, rstore)
        real, dimension(:), intent(in out) :: rstore
        real, dimension(:,:), intent(out) :: vertic
        integer :: nrvert, point
        nrvert = 4
        point = 26
        vertic(1, 1:nrvert) = rstore(point+1:point+nrvert)
    end subroutine dsget

end program ds_routines_program