program coop_wrapper_test
implicit none

! Assuming coop_version is a string variable that we need
character(len=32) :: coop_version

! Initialize version or any other variables if needed
coop_version = "1.0.0"

! Call the subroutine that was originally in the module
call coop_wrapper_typedef_print()

contains

  subroutine coop_wrapper_typedef_print()
    ! This subroutine simply prints the version and a message
    write(*,*) "This is COOP VERSION "//trim(coop_version)
    write(*,*) "Wrapper for typedef."
  end subroutine coop_wrapper_typedef_print

end program coop_wrapper_test