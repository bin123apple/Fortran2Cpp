program doimplied

    implicit none
    integer :: i
    integer, dimension(5) :: P

    P = (/ (i**2, i=1,5) /)
    call testP(P)

contains

    subroutine testP(P)
        integer, dimension(5), intent(in) :: P
        integer :: i
        do i=1, 5
            if (P(i) /= i**2) then
                print *, "Test failed at index:", i, "Expected:", i**2, "Got:", P(i)
                return
            endif
        end do
        print *, "All tests passed."
    end subroutine testP

end program doimplied