module greet_mod
    implicit none
contains
    subroutine greet(name)
        character(len=*), intent(in) :: name
        print *, 'Hello, '//trim(name)//'!'
    end subroutine greet
end module greet_mod

module world_mod
    implicit none
    character(len=100) :: world = " World "
end module world_mod

program hello2
    use greet_mod, only: greet
    use world_mod, only: world
    implicit none

    ! Main program functionality
    call greet(trim(world))

    ! Test
    call test_greet
contains
    ! A simple test subroutine for demonstration.
    subroutine test_greet
        character(len=:), allocatable :: test_world
        test_world = " Test World "
        call greet(trim(test_world))
        ! In a real scenario, you would compare the output
        ! or behavior to expected results.
        ! Here, we're just showing functionality.
    end subroutine test_greet
end program hello2