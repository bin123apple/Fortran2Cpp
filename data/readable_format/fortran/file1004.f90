! combined.f90
subroutine great_dd1_x1(dd1, x1)
    implicit none
    ! Assuming integer for demonstration purposes
    integer, intent(in) :: dd1, x1
    print *, "Great subroutine called with dd1, x1: ", dd1, x1
end subroutine great_dd1_x1

subroutine great_u1_cc1(u1, cc1)
    implicit none
    ! Assuming integer for demonstration purposes
    integer, intent(in) :: u1, cc1
    print *, "Great subroutine called with u1, cc1: ", u1, cc1
end subroutine great_u1_cc1

! Add other subroutine definitions here...

! Main program to test one of the subroutines
program test_great
    implicit none
    call great_dd1_x1(5, 10)
    ! Call other subroutines as needed
end program test_great