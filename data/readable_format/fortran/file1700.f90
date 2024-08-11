subroutine ugetio(iopt,nin,nout)
    integer :: iopt,nin,nout
    integer, save :: nind=1, noutd=2
    if (iopt == 3) then
        noutd = nout
    else if (iopt == 2) then
        nind = nin
    else if (iopt == 1) then
        nin = nind
        nout = noutd
    end if
end subroutine ugetio

program test_ugetio
    implicit none
    integer :: nin, nout

    ! Test iopt = 1
    call ugetio(1, nin, nout)
    print *, 'Test iopt=1: nin=', nin, 'nout=', nout

    ! Test iopt = 2
    nin = 10
    call ugetio(2, nin, nout)
    print *, 'Test iopt=2: nin=', nin, 'nout=', nout

    ! Test iopt = 3
    nout = 20
    call ugetio(3, nin, nout)
    print *, 'Test iopt=3: nin=', nin, 'nout=', nout

end program test_ugetio