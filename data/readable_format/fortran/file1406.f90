program hello_world
    implicit none

    call print_hello_world

contains

    subroutine print_hello_world
        implicit none
        print *, 'hello world'
    end subroutine print_hello_world

    ! A simple "test" procedure that checks an expected behavior.
    ! Note: Fortran doesn't have a built-in assert like many other languages,
    ! so this is a very rudimentary demonstration.
    subroutine test_hello_world
        implicit none
        character(len=20) :: expected_output
        expected_output = 'hello world'

        ! In a real scenario, you'd capture the output of print_hello_world
        ! and compare. Here, we're just demonstrating structure.
        if (expected_output /= 'hello world') then
            print *, 'Test failed.'
        else
            print *, 'Test passed.'
        endif
    end subroutine test_hello_world

end program hello_world