program test_osrchm
    implicit none
    integer :: N, INC, ITARGET, MASK, SHIFT, INDEX, IWHERE, INUM
    integer, dimension(5) :: IARRAY
    integer :: i

    ! Initialize test data
    N = 5
    IARRAY = (/10, 20, 30, 40, 50/)
    INC = 1
    ITARGET = 20
    MASK = Z'FFFF'
    SHIFT = 0
    INDEX = 0
    IWHERE = 0
    INUM = 0

    ! Call the subroutine
    call OSRCHM(N, IARRAY, INC, ITARGET, MASK, SHIFT, INDEX, IWHERE, INUM)
    
    ! Print the results
    print *, 'INDEX: ', INDEX
    print *, 'IWHERE: ', IWHERE
    print *, 'INUM: ', INUM

contains

    subroutine OSRCHM(N, IARRAY, INC, ITARGET, MASK, SHIFT, INDEX, IWHERE, INUM)
        integer, intent(in) :: N, INC, ITARGET, MASK, SHIFT
        integer, intent(inout) :: INDEX, IWHERE, INUM
        integer, dimension(N), intent(in) :: IARRAY
        integer :: i, j

        if (N < 0) then
            INDEX = 0
            IWHERE = 0
            INUM = 0
            return
        endif

        j = 1
        if (INC < 0) then
            j = N * (-INC)
        endif

        do i= 1, N
            if (iand(MASK, ishft(IARRAY(j), -SHIFT)) > ITARGET) then
                INDEX = N + 1
                IWHERE = i
                INUM = 0
                return
            elseif (iand(MASK, ishft(IARRAY(j), -SHIFT)) == ITARGET) then
                INDEX = i
                IWHERE = i
                if (INUM == 0) then
                    INUM = 1
                    return
                endif
                INUM = 1
                do while (i <= N)
                    j = j + INC
                    if (iand(MASK, ishft(IARRAY(j), -SHIFT)) /= ITARGET) exit
                    INUM = INUM + 1
                end do
                return
            endif
            j = j + INC
        end do

        INDEX = N + 1
        IWHERE = N + 1
        INUM = 0
    end subroutine OSRCHM

end program test_osrchm