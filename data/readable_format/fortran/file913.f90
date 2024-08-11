program testWritemac
    implicit none
    integer, parameter :: nev=2, nevcomplex=2
    real*8 :: mac(nev,nevcomplex)
    integer :: i, j

    ! Initialize the mac array with some test values
    do i=1,nev
        do j=1,nevcomplex
            mac(i,j) = i + j * 0.1
        end do
    end do

    ! Call the writemac subroutine
    call writemac(mac,nev,nevcomplex)

end program testWritemac

subroutine writemac(mac,nev,nevcomplex)
    implicit none
    integer i,j,nev,nevcomplex
    real*8 mac(nev,nevcomplex)

    write(5,*)
    write(5,*)    'Modal Assurance Criterion'
    write(5,*)
    do i=1,nev
       write(5,100) (mac(i,j),j=1,nevcomplex)
    enddo

100 format(15(1x,e11.4))
    return
end