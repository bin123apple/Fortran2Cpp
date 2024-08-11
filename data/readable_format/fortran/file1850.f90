module utility
    implicit none
    integer :: gatto = 0
    integer, private :: gatto_timido = 0

contains

    subroutine subtract(mino, ris, magg)
        integer, intent(in) :: mino
        integer, intent(out) :: ris
        integer, optional, intent(in) :: magg

        gatto_timido = 24
        if (present(magg)) then
            ris = magg - mino
        else
            ris = -mino
        endif
        gatto = 42
    end subroutine subtract

end module utility

program test_utility
    use utility
    implicit none
    integer :: results, gatto_test

    ! Test with optional `magg`
    call subtract(3, results, magg=10)
    print *, "Test with magg: Result =", results
    if (results == 7) then
        print *, "Passed"
    else
        print *, "Failed"
    endif

    ! Test without optional `magg`
    call subtract(3, results)
    print *, "Test without magg: Result =", results
    if (results == -3) then
        print *, "Passed"
    else
        print *, "Failed"
    endif

    ! Check global variable `gatto`
    gatto_test = gatto
    print *, "Global `gatto` = ", gatto_test
    if (gatto_test == 42) then
        print *, "`gatto` test Passed"
    else
        print *, "`gatto` test Failed"
    endif

    ! Note: `gatto_timido` is private, so its value is indirectly tested through the subroutine's behavior
end program test_utility