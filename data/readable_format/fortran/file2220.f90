module greet_mod
contains
    subroutine greet_world()
        write(*, '(a)') 'Greet World'
    end subroutine greet_world
end module greet_mod

program test_greet
    use greet_mod
    call greet_world()
end program test_greet