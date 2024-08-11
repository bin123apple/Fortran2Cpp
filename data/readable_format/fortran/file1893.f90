program helloworld
implicit none

! Main program
call say_hello
call test_say_hello

contains

! Function to print "Hello, World!"
subroutine say_hello()
    print *, "Hello world!"
end subroutine say_hello

! A simple test procedure
subroutine test_say_hello()
    ! Here we would ideally call say_hello and check its behavior
    ! Since Fortran doesn't have a built-in assertion library and cannot easily capture stdout
    ! we'll just manually check by calling the function
    print *, "Testing say_hello subroutine:"
    call say_hello
    ! Manual inspection would be required to validate the test
    ! In a real testing scenario, we would compare expected output or behavior
end subroutine test_say_hello

end program helloworld