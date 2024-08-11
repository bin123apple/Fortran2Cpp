program test_edtoir
    implicit none
    integer, parameter :: npix = 3, nlin = 3
    integer*2 :: in(npix, nlin)
    integer :: out(npix, nlin)
    integer :: inval = -999, blank = -1
    real :: bscale = 1.0, bzero = 0.0
    integer :: i, j

    ! Initialize the input array
    do j = 1, nlin
        do i = 1, npix
            in(i, j) = -999
        end do
    end do

    call edtoir(in, out, npix, nlin, inval, blank, bscale, bzero)
    print *, "Test Case 1: bscale=1.0, bzero=0.0"
    do j = 1, nlin
        do i = 1, npix
            print *, "arr(", i, ",", j, ") = ", out(i, j)
        end do
    end do

contains

    subroutine edtoir(in, out, npix, nlin, inval, blank, bscale, bzero)
        implicit none
        integer :: npix, nlin, inval, blank, out(npix, nlin)
        integer*2 :: in(npix, nlin)
        real :: bscale, bzero
        real :: factor
        integer :: lin, pix, offset

        if (bscale /= 0.0) then
            offset = nint(bzero / bscale)
            factor = 1.0
        else
            offset = 1
            factor = 0.0
        endif

        do lin = 1, nlin
            do pix = 1, npix
                if (in(pix, lin) /= inval) then
                    out(pix, lin) = int(factor * in(pix, lin) + offset)
                else
                    out(pix, lin) = blank
                endif
            end do
        end do
    end subroutine edtoir

end program test_edtoir