program TestOCTANT1
    implicit none
    integer, parameter :: MAXX_IN=10, MAXY_IN=10, MAX_VALUES_PER_OCTANT=5
    real, dimension(MAXX_IN, MAXY_IN) :: A_IN, SD_A_IN
    integer :: IX_FOUND(MAX_VALUES_PER_OCTANT), IY_FOUND(MAX_VALUES_PER_OCTANT)
    integer :: POINTS_FOUND, IX, IY
    real :: BADDATA
    integer :: i, j

    ! Initialize data and parameters
    BADDATA = -999.0
    do i = 1, MAXX_IN
        do j = 1, MAXY_IN
            A_IN(i, j) = real(i + j)
            SD_A_IN(i, j) = real(i + j)
        end do
    end do
    A_IN(3, 4) = BADDATA
    SD_A_IN(5, 5) = BADDATA

    IX = 1
    IY = 1
    
    call OCTANT1(A_IN, SD_A_IN, MAXX_IN, MAXY_IN, MAXX_IN, MAXY_IN, &
                 BADDATA, 5, MAX_VALUES_PER_OCTANT, IX, IY, &
                 POINTS_FOUND, IX_FOUND, IY_FOUND)

    ! Output results
    print *, 'Points found:', POINTS_FOUND
    do i = 1, POINTS_FOUND
        print *, 'Point:', IX_FOUND(i), IY_FOUND(i)
    end do

contains

subroutine OCTANT1(A_IN,SD_A_IN,MAXX_IN,MAXY_IN,NX,NY,BADDATA, &
                    MAX_SEARCH_RADIUS,MAX_VALUES_PER_OCTANT,IX,IY, &
                    POINTS_FOUND,IX_FOUND,IY_FOUND)
    implicit none
    integer, intent(in) :: MAXX_IN,MAXY_IN,NX,NY,IX,IY,MAX_SEARCH_RADIUS,MAX_VALUES_PER_OCTANT
    real, intent(in) :: BADDATA
    real, dimension(MAXX_IN, MAXY_IN), intent(in) :: A_IN, SD_A_IN
    integer, dimension(MAX_VALUES_PER_OCTANT), intent(out) :: IX_FOUND, IY_FOUND
    integer :: IX_SEARCH, IY_SEARCH
    integer, intent(out) :: POINTS_FOUND

    POINTS_FOUND=0
    do IY_SEARCH=IY+1, min(IY+MAX_SEARCH_RADIUS, NY)
        do IX_SEARCH=IX, min(IX+IY_SEARCH-IY-1, NX)
            if (A_IN(IX_SEARCH,IY_SEARCH) /= BADDATA .and. SD_A_IN(IX_SEARCH,IY_SEARCH) /= BADDATA) then
                POINTS_FOUND=POINTS_FOUND+1
                if (POINTS_FOUND <= MAX_VALUES_PER_OCTANT) then
                    IX_FOUND(POINTS_FOUND)=IX_SEARCH
                    IY_FOUND(POINTS_FOUND)=IY_SEARCH
                end if
                if (POINTS_FOUND >= MAX_VALUES_PER_OCTANT) then
                    return
                end if
            end if
        end do
    end do
end subroutine OCTANT1

end program TestOCTANT1