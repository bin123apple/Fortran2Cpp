program testMover
    implicit none
    double precision, allocatable :: c1(:,:), c2(:,:)
    integer, allocatable :: atom_list(:)
    integer :: na1, na2, np2
    double precision :: cut

    ! Initialize test data
    na1 = 2
    na2 = 2
    np2 = 2
    cut = 1.5
    allocate(c1(na1,3), c2(na2,3), atom_list(np2))

    ! Coordinates for c1 and c2 are set up to have exactly one pair within the cut-off distance
    c1(1,1) = 0.0
    c1(1,2) = 0.0
    c1(1,3) = 0.0
    c1(2,1) = 3.0
    c1(2,2) = 3.0
    c1(2,3) = 3.0

    c2(1,1) = 1.0
    c2(1,2) = 1.0
    c2(1,3) = 1.0
    c2(2,1) = 4.0
    c2(2,2) = 4.0
    c2(2,3) = 4.0

    call mover(c1, na1, c2, na2, cut, np2, atom_list)

    ! Check results
    print *, 'atom_list:', atom_list

contains

    subroutine mover(c1, na1, c2, na2, cut, np2, atom_list)
        double precision, intent(in) :: c1(na1,3), c2(na2,3), cut
        integer, intent(in) :: na1, na2, np2
        integer, intent(out) :: atom_list(np2)
        double precision :: x1, y1, z1, x2, y2, z2, dist
        double precision :: dx2, dy2, dz2
        integer :: i, j, count

        count = 1
        do i = 1, na1
            x1 = c1(i,1)
            y1 = c1(i,2)
            z1 = c1(i,3)
            do j = 1, na2
                x2 = c2(j,1)
                y2 = c2(j,2)
                z2 = c2(j,3)
                dx2 = (x2 - x1)**2
                dy2 = (y2 - y1)**2
                dz2 = (z2 - z1)**2
                dist = sqrt(dx2 + dy2 + dz2)
                if(dist < cut) then
                    atom_list(count) = j
                    count = count + 1
                endif
            enddo
        enddo

        print *, 'FORTAN: COUNT = ', count - 1

    end subroutine mover

end program testMover