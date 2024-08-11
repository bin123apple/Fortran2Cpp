program yw_test
    implicit none
    integer :: hx(6, 6)
    integer :: ps, e2

    ! Initialize array
    do ps = 1, 6
        do e2 = 1, 6
            hx(e2, ps) = 0
            if (ps >= 5 .and. e2 >= 5) then
                hx(e2, ps) = 99 ! Using 99 for a clear test case
            end if
        end do
    end do

    ! Test output
    call print_array(hx)
end program yw_test

subroutine print_array(array)
    integer, intent(in) :: array(6, 6)
    integer :: i, j

    do i = 1, 6
        do j = 1, 6
            write(*, '(*(I3, 1X))') array(j, i)
        end do
        write(*, *)
    end do
end subroutine print_array