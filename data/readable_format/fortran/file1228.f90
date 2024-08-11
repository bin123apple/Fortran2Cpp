! This is the subroutine you want to test
subroutine liomain()
    implicit none
    ! This subroutine does not perform any operations
end subroutine liomain

! This is the main program for testing the subroutine
program test_liomain
    implicit none
    call liomain
    print *, "liomain called successfully."
end program test_liomain