! Define the subroutines in the same file
module maxval_subroutines
    implicit none
contains

    subroutine maxval_i_js2(array, maxValue)
        integer, dimension(:), intent(in) :: array
        integer, intent(out) :: maxValue
        ! Dummy implementation - replace with actual logic
        maxValue = maxval(array)
    end subroutine maxval_i_js2

    subroutine maxval_i_ss2(array, maxValue)
        integer, dimension(:), intent(in) :: array
        integer, intent(out) :: maxValue
        ! Dummy implementation - replace with actual logic
        maxValue = maxval(array)
    end subroutine maxval_i_ss2

end module maxval_subroutines

! Test program
program testMaxValSubroutines
    use maxval_subroutines
    implicit none
    integer :: maxValue
    integer, dimension(5) :: testArray = (/1, 5, 3, 7, 6/)

    ! Test maxval_i_js2
    call maxval_i_js2(testArray, maxValue)
    print *, "Test maxval_i_js2 - Expected max: 7, Actual max:", maxValue

    ! Test maxval_i_ss2
    call maxval_i_ss2(testArray, maxValue)
    print *, "Test maxval_i_ss2 - Expected max: 7, Actual max:", maxValue

end program testMaxValSubroutines