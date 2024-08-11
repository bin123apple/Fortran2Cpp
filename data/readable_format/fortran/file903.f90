! Assuming the PARAMETER declarations are needed before usage
program testCommonBlocks
    implicit none
    integer, parameter :: MAXREC=10, RECLEN=20
    integer :: i

    ! Common block declarations
    integer :: stidmx, strpos(MAXREC), stid
    logical :: newpos, newrec
    character(RECLEN) :: strec

    common /dbbuf1/ stidmx, strpos, stid, newpos, newrec
    common /dbbuf2/ strec

    ! Initialize some variables
    stidmx = 100
    stid = 1
    newpos = .TRUE.
    newrec = .FALSE.
    do i = 1, MAXREC
        strpos(i) = i*10
    end do
    strec = 'Hello, Fortran Common!'

    ! Print to verify
    print *, 'stidmx:', stidmx
    print *, 'stid:', stid
    print *, 'newpos:', newpos
    print *, 'newrec:', newrec
    do i = 1, MAXREC
        print *, 'strpos(', i, '):', strpos(i)
    end do
    print *, 'strec:', strec

end program testCommonBlocks