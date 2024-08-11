! This is your module but included directly in the same file
module other_file_mod
    ! Here you would define any procedures, types, or variables that belong to the module
end module other_file_mod

! This is your main program or another module that uses other_file_mod
program main
    use other_file_mod  ! This includes the module into your program
    implicit none

    ! Your program code goes here
    print *, "Hello from the main program!"

    ! Test passed if we reach this point without errors
    print *, "Test passed."
end program main