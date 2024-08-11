! Defining the subroutine
subroutine i2torl(iin, npix, nlin, scale, zero, inval, rinval, rout)
    implicit none
    integer :: npix, nlin, inval
    integer*2 :: iin(npix, nlin)
    real :: rout(npix, nlin), scale, zero, rinval
    integer :: lin, pix
    
    do lin = 1, nlin
        do pix = 1, npix
            if (iin(pix, lin) .ne. inval) then
                rout(pix, lin) = scale * iin(pix, lin) + zero
            else
                rout(pix, lin) = rinval
            endif
        end do
    end do
end subroutine i2torl

! Testing the subroutine
program test_i2torl
    implicit none
    integer, parameter :: npix = 2, nlin = 2
    integer*2 :: iin(npix, nlin)
    real :: rout(npix, nlin)
    real, parameter :: scale = 2.0, zero = 1.0, rinval = -1.0
    integer, parameter :: inval = 0
    integer :: pix, lin

    ! Initialize input array
    iin(1,1) = 1
    iin(2,1) = 0
    iin(1,2) = -1
    iin(2,2) = 2

    ! Call the subroutine
    call i2torl(iin, npix, nlin, scale, zero, inval, rinval, rout)

    ! Check results
    print *, 'Testing i2torl subroutine...'
    do lin = 1, nlin
        do pix = 1, npix
            print *, 'rout(', pix, ',', lin, ') = ', rout(pix, lin)
        end do
    end do
end program test_i2torl